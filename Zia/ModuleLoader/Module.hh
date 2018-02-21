//
// Created by Arnaud WURMEL on 09/02/2018.
//

#ifndef CPP_ZIA_MODULELOADER_HH
#define CPP_ZIA_MODULELOADER_HH

#include <memory>
# include "../../api/module.h"
# include "DLLManager/ADLLManager.hh"
#include "DLLManager/LinuxDLLManager.hpp"
#include "DLLManager/WindowsDLLManager.hpp"

namespace zia {
    template<typename T>
    class Module {
    public:
        explicit Module(std::string const& moduleName) {
            _moduleName = moduleName;
        }
        ~Module() {
            _module.reset();
            _manager.reset();
        }

    public:
        bool    load(std::vector<std::string> const& paths) {
            auto    iterator = paths.begin();

            while (iterator != paths.end()) {
#ifdef _WIN32
                _manager = std::shared_ptr<ADLLManager<T> >(new WindowsDLLManager<T>(*iterator + "/" + _moduleName));
#else
                _manager = std::shared_ptr<ADLLManager<T> >(new LinuxDLLManager<T>(*iterator + "/" + _moduleName));
#endif
                std::cout << "Before init" << std::endl;
                if (_manager->init()) {
                    std::cout << "initializec" << std::endl;
					T	*ptr = _manager->create();

					std::cout << ptr << std::endl;
                    _module = std::unique_ptr<T>(ptr);

                    if (_module) {
                        return true;
                    }
                }
                ++iterator;
            }
            return false;
        }

    public:
        std::unique_ptr<T>&  get() {
            return _module;
        }

        std::unique_ptr<T> const& get() const {
            return _module;
        }

    private:
        std::string _moduleName;
        std::unique_ptr<T>    _module;
        std::shared_ptr<ADLLManager<T>>    _manager;
    };
}


#endif //CPP_ZIA_MODULELOADER_HH
