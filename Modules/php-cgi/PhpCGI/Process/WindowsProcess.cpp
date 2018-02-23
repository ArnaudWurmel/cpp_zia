//
// Created by Erwan BALLET on 22/02/2018.
//

#include <iostream>
#include <strsafe.h>
#include <tchar.h>
#include "WindowsProcess.h"

#ifdef _WIN32
zia::module::WindowsProcess::WindowsProcess() = default;

zia::module::WindowsProcess::~WindowsProcess() = default;

bool    zia::module::WindowsProcess::execute(std::vector<std::string> const& argsVec, std::map<std::string, std::string> const& env, zia::api::Net::Raw const& input) {
    SECURITY_ATTRIBUTES saAttr;
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = nullptr;
    std::string command;

    int i = 0;
	command += "\"";
    while (i < argsVec.size()) {
        command += argsVec[i];
        if (i < argsVec.size() - 1) {
            command += " ";
        }
        i++;
    }
	command += "\"";
	size_t	size = 0;
	auto it = env.begin();

	while (it != env.end()) {
		size = size + (*it).first.length() + (*it).second.length() + 2;
		++it;
	}
	it = env.begin();

	while (it != env.end()) {
		SetEnvironmentVariable((*it).first.c_str(), (*it).second.c_str());
		++it;
	}
    if ( ! CreatePipe(&g_hChildStd_OUT_Rd, &g_hChildStd_OUT_Wr, &saAttr, 0) )
        return false;
    if ( ! SetHandleInformation(g_hChildStd_OUT_Rd, HANDLE_FLAG_INHERIT, 0) )
        return false;
    if (! CreatePipe(&g_hChildStd_IN_Rd, &g_hChildStd_IN_Wr, &saAttr, 0))
        return false;
    if ( ! SetHandleInformation(g_hChildStd_IN_Wr, HANDLE_FLAG_INHERIT, 0) )
        return false;
	if (!CreateChildProcess(command)) {
		return false;
	}
    WriteToPipe(input);
    ReadFromPipe();
    return true;
}

bool zia::module::WindowsProcess::CreateChildProcess(std::string command) {
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
                                 nullptr,        // use parent's environment
                                 nullptr,       // use parent's current directory
                                 &siStartInfo,  // STARTUPINFO pointer
                                 &piProcInfo);  // receives PROCESS_INFORMATION

		if (!bSuccess) {
			return false;
		}
        else {
            CloseHandle(piProcInfo.hProcess);
            CloseHandle(piProcInfo.hThread);
        }
    }
	return true;
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
	CloseHandle(g_hChildStd_IN_Wr);
}

void zia::module::WindowsProcess::ReadFromPipe()
{
    DWORD dwRead, dwWritten;
    CHAR chBuf[255];
    BOOL bSuccess;

    for (;;)
    {
		std::memset(chBuf, 0, sizeof(chBuf));
        bSuccess = ReadFile( g_hChildStd_OUT_Rd, chBuf, 254, &dwRead, nullptr);
		if (!bSuccess || dwRead == 0) {
			break;
		}
		chBuf[dwRead] = 0;
        _output += chBuf;
		if (dwRead < 254) {
			break;
		}
    }
	CloseHandle(g_hChildStd_OUT_Rd);
}

std::string const &zia::module::WindowsProcess::getOutput() const {
    return _output;
}
 #endif