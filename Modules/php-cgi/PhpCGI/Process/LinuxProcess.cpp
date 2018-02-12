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

zia::module::LinuxProcess::LinuxProcess() = default;

bool    zia::module::LinuxProcess::execute(std::string const &input, std::string const &path) {
    pid_t pid;
    int pipefd[2];
    int infd[2];
    char    *args[2];

    args[0] = strdup(path.c_str());
    args[1] = nullptr;
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
        execve(args[0], args, nullptr);
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
        wait(NULL);
        while ((nbytes = read(pipefd[0], buffer, sizeof(buffer) - 1)) > 0) {
            buffer[nbytes] = '\0';
            output += buffer;
        }
        close(pipefd[0]);
        _output = output;
    }
    return true;
}

std::string const&  zia::module::LinuxProcess::getOutput() const {
    return _output;
}

zia::module::LinuxProcess::~LinuxProcess() = default;

#endif