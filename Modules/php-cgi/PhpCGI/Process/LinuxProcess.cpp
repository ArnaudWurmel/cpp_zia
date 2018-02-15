//
// Created by Arnaud WURMEL on 12/02/2018.
//

#include "LinuxProcess.hh"
#ifndef _WIN32

# include <sys/wait.h>
# include <sys/pipe.h>
#include <zconf.h>
#include <iostream>
#include <memory.h>
#include <vector>

zia::module::LinuxProcess::LinuxProcess() = default;

bool    zia::module::LinuxProcess::execute(std::vector<std::string> const &argsVec, std::map<std::string, std::string> const &env, zia::api::Net::Raw const& input) {
    pid_t pid;
    int pipefd[2];
    int infd[2];
    char    **args;
    char    **envTab;

    args = new char*[argsVec.size() + 1];
    int i = 0;
    while (i < argsVec.size()) {
        args[i] = new char[argsVec[i].size()];
        args[i] = strcpy(args[i], argsVec[i].c_str());
        ++i;
    }
    args[i] = nullptr;
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
    if (pipe(pipefd) == -1 || pipe(infd) == -1) {
        return false;
    }
    if ((pid = fork()) == -1) {
        close(pipefd[0]);
        close(pipefd[1]);
        return false;
    }
    else if (pid == 0) {
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        dup2(infd[0], STDIN_FILENO);
        close(infd[0]);
        close(infd[1]);
        execve(args[0], args, envTab);
        exit(0);
    }
    else {
        char    buffer[4092];
        std::string output;
        ssize_t nbytes;

        close(infd[0]);
        write(infd[1], input.data(), input.size());
        close(infd[1]);
        close(pipefd[1]);
        wait(nullptr);
        while ((nbytes = read(pipefd[0], buffer, sizeof(buffer) - 1)) > 0) {
            buffer[nbytes] = '\0';
            output += buffer;
        }
        close(pipefd[0]);
        _output = output;
    }
    i = 0;
    while (i < argsVec.size()) {
        delete args[i];
        ++i;
    }
    delete[] args;
    i = 0;
    while (i < env.size()) {
        delete envTab[i];
        ++i;
    }
    delete[] envTab;
    return true;
}

std::string const&  zia::module::LinuxProcess::getOutput() const {
    return _output;
}

zia::module::LinuxProcess::~LinuxProcess() = default;

#endif