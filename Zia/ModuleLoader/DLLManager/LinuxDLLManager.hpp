//
// Created by Arnaud WURMEL on 20/01/2018.
//

#ifndef SERVERGAME_LINUXDLLMANAGER_HH
#define SERVERGAME_LINUXDLLMANAGER_HH

# include <iostream>

#ifndef _WIN32
# include <dlfcn.h>
#endif
# include "ADLLManager.hh"

#ifdef __APPLE__
# define EXT ".dylib"
#else
# define EXT ".so"
#endif


namespace zia {
    template<typename T>
    class LinuxDLLManager : public ADLLManager<T> {
    public:
        explicit LinuxDLLManager(std::string const& libPath) {
            _libPath = libPath;
            _handler = nullptr;
        }

        ~LinuxDLLManager() override {
#ifndef _WIN32
            if (_handler) {
                dlclose(_handler);
            }
#endif // !_WIN32
        }

    public:
        bool    init() override {
#ifdef _WIN32
            return false;
#else
            std::string path = _libPath + EXT;
            char    *error;

            _handler = dlopen(path.c_str(), RTLD_LAZY);
            if (!_handler) {
                std::cout << "Can't create library <" << dlerror() << ">" << std::endl;
                return false;
            }
            _instancier = reinterpret_cast<T *(*)()>(dlsym(_handler, "create"));
            if ((error = dlerror()) != NULL) {
                std::cout << "Can't instanciate module <" << error << ">" << std::endl;
                return false;
            }
            return true;
#endif // _WIN32
        }

        T* create() override {
            return _instancier();
        }

    private:
        std::string _libPath;
        void    *_handler;
        T  *(*_instancier)();
    };
}


#endif //SERVERGAME_LINUXDLLMANAGER_HH
