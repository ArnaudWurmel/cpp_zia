#include "../../api/module.h"
#include "HttpSender/HttpSender.hh"

extern "C" {
#ifdef _WIN32
	__declspec(dllimport) zia::api::Module *create();
#else
	zia::api::Module   *create();
#endif
}

extern "C" zia::api::Module *create() {
	return new zia::module::HttpSender();
}