//
// Created by Arnaud WURMEL on 21/01/2018.
//

#ifndef SERVERGAME_WINDOWSDLLMANAGER_HH
#define SERVERGAME_WINDOWSDLLMANAGER_HH

#ifdef _WIN32
#include <Windows.h>
#endif // !_WIN32
# include "ADLLManager.hh"

namespace zia {
    template<typename T>
    class WindowsDLLManager : public ADLLManager<T> {
    public:
        explicit WindowsDLLManager(std::string const& libPath) {
            _libPath = libPath;
        }

        ~WindowsDLLManager() override {
#ifdef _WIN32
            if (_handler) {
            	FreeLibrary(_handler);
            }
#endif // !_WIN32
        }

    public:
        bool    init() override {
#ifdef _WIN32
            std::string path = _libPath + ".dll";
            DWORD	error;

            _handler = LoadLibrary(path.c_str());
           	std::cout << "Loading " << path.c_str() << std::endl;
           	if (!_handler) {
              	std::cout << "Can't instanciate module <" << GetLastError() << ">" << std::endl;
               	return false;
           	}
           	_instancier = reinterpret_cast<T *(*)()>(GetProcAddress(_handler, "instanciateMonster"));
           	if ((error = GetLastError()) != NULL) {
           	    std::cout << "Can't instanciate module <" << error << ">" << std::endl;
           	    return false;
           	}
           	return true;
#else
    return false;
#endif // _WIN32
        }

        T* create() override {
            return _instancier();
        }

    private:
        std::string _libPath;
#ifdef _WIN32
		HINSTANCE	_handler;
#else
		void    *_handler;
#endif // _WIN32
        T  *(*_instancier)();

    private:
        static std::string  _ext;
    };
}


#endif //SERVERGAME_WINDOWSDLLMANAGER_HH
