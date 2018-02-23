//
// Created by Erwan BALLET on 22/02/2018.
//

#include "WindowsProcess.h"

#ifdef _WIN32
zia::module::WindowsProcess::WindowsProcess() = default;

zia::module::WindowsProcess::~WindowsProcess() = default;

bool    zia::module::WindowsProcess::execute(std::vector<std::string> const& argsVec, std::map<std::string, std::string> const& env, zia::api::Net::Raw const& input) {
    SECURITY_ATTRIBUTES saAttr;
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = nullptr;
    char        **envTab;
    std::string command;

    int i = 0;
    while (i < argsVec.size()) {
        command += argsVec[i];
        if (i < argsVec.size() - 1) {
            command += " ";
        }
        i++;
    }
    envTab = new char*[env.size() + 1];
    i = 0;
    auto it = env.begin();
    while (i < env.size()) {
        std::string tmp = (*it).first + "=" + (*it).second;

        envTab[i] = new char[tmp.size() + 1];
        envTab[i] = strcpy(envTab[i], tmp.c_str());
        ++i;
        ++it;
    }
    envTab[i] = nullptr;
    if ( ! CreatePipe(&g_hChildStd_OUT_Rd, &g_hChildStd_OUT_Wr, &saAttr, 0) )
        return false;
    if ( ! SetHandleInformation(g_hChildStd_OUT_Rd, HANDLE_FLAG_INHERIT, 0) )
        return false;
    if (! CreatePipe(&g_hChildStd_IN_Rd, &g_hChildStd_IN_Wr, &saAttr, 0))
        return false;
    if ( ! SetHandleInformation(g_hChildStd_IN_Wr, HANDLE_FLAG_INHERIT, 0) )
        return false;
    CreateChildProcess(command, envTab);
    WriteToPipe(input);
    ReadFromPipe();
    i = 0;
    while (i < env.size()) {
        delete envTab[i];
        ++i;
    }
    delete[] envTab;
    return true;
}

void zia::module::WindowsProcess::CreateChildProcess(std::string command, char **envTab) {
    char    *cmd;
    PROCESS_INFORMATION piProcInfo;
    STARTUPINFO siStartInfo;
    BOOL bSuccess;

    ZeroMemory( &piProcInfo, sizeof(PROCESS_INFORMATION) );
    ZeroMemory( &siStartInfo, sizeof(STARTUPINFO) );
    siStartInfo.cb = sizeof(STARTUPINFO);
    siStartInfo.hStdError = g_hChildStd_OUT_Wr;
    siStartInfo.hStdOutput = g_hChildStd_OUT_Wr;
    siStartInfo.hStdInput = g_hChildStd_IN_Rd;
    siStartInfo.dwFlags |= STARTF_USESTDHANDLES;
    cmd = _strdup(command.c_str());
    if (cmd != nullptr) {
        bSuccess = CreateProcess(nullptr,
                                 cmd,           // command line
                                 nullptr,       // process security attributes
                                 nullptr,       // primary thread security attributes
                                 TRUE,          // handles are inherited
                                 0,             // creation flags
                                 envTab,        // use parent's environment
                                 nullptr,       // use parent's current directory
                                 &siStartInfo,  // STARTUPINFO pointer
                                 &piProcInfo);  // receives PROCESS_INFORMATION

        if (!bSuccess)
            return;
        else {
            CloseHandle(piProcInfo.hProcess);
            CloseHandle(piProcInfo.hThread);
        }
    }
}

void zia::module::WindowsProcess::WriteToPipe(zia::api::Net::Raw const& input)
{
    DWORD dwWritten;
    std::string tmp;
    auto it = input.begin();

    while (it != input.end()) {
        tmp += *reinterpret_cast<const char *>(&(*it));
        ++it;
    }
    char *buf = _strdup(tmp.c_str());
    WriteFile(g_hChildStd_IN_Wr, buf, input.size(), &dwWritten, nullptr);
}

void zia::module::WindowsProcess::ReadFromPipe()
{
    DWORD dwRead, dwWritten;
    CHAR chBuf[255];
    BOOL bSuccess;

    for (;;)
    {
        bSuccess = ReadFile( g_hChildStd_OUT_Rd, chBuf, 255, &dwRead, nullptr);
        if( ! bSuccess || dwRead == 0 ) break;
        _output += chBuf;
    }
}

std::string const &zia::module::WindowsProcess::getOutput() const {
    return _output;
}
 #endif