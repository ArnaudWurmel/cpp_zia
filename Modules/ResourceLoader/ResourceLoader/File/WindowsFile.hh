//
// Created by marcha_1 on 13/02/2018.
//

#ifndef RESOURCELOADER_WINDOWSFILE_HH
#define RESOURCELOADER_WINDOWSFILE_HH

# include <Windows.h>
# include <sys/stat.h>
# include "AFile.hh"

#ifdef _WIN32
namespace zia::module {
	class WindowsFile : public AFile {
	public:
		WindowsFile();
		~WindowsFile() override;

	public:
		bool    load(std::string const&) override;
		bool    isDir() const override;
		std::string getFullPath() const override;

	private:
		DWORD WINAPI _attributes;
		std::string _path;
	};
}
#endif

#endif //RESOURCELOADER_WINDOWSFILE_HH
