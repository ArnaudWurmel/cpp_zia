//
// Created by Erwan BALLET on 22/02/2018.
//

#ifndef CPP_ZIA_WINDOWPROCESS_H
#define CPP_ZIA_WINDOWPROCESS_H

#include <vector>
#include <map>
#include "AProcess.hh"
#ifdef _WIN32
#include <windows.h>

namespace zia::module {
    class WindowsProcess : public AProcess {
    public:
        WindowsProcess();
        ~WindowsProcess() override;

    public:
        bool    execute(std::vector<std::string> const& argsVec, std::map<std::string, std::string> const& env, zia::api::Net::Raw const&);
        std::string const&  getOutput() const override;

    private:
        bool CreateChildProcess(std::string);
        void WriteToPipe(zia::api::Net::Raw const& input);
        void ReadFromPipe();


    private:
        HANDLE g_hChildStd_IN_Rd = nullptr;
        HANDLE g_hChildStd_IN_Wr = nullptr;
        HANDLE g_hChildStd_OUT_Rd = nullptr;
        HANDLE g_hChildStd_OUT_Wr = nullptr;
        std::string _output;
    };
}
 #endif
#endif //CPP_ZIA_WINDOWPROCESS_H
