//
// Created by marcha_1 on 2/02/18.
//

#ifdef _WIN32
//#include "stdafx.h"
#include <vector>
#include <string>
#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#pragma comment(lib, "User32.lib")
#include "WindowsDirectoryReader.h"

zia::WindowsDirectoryReader::WindowsDirectoryReader() {}

std::vector<std::string>    zia::WindowsDirectoryReader::getFileNameFor(std::string const& filepath) {
		std::vector<std::string>    fileList;
		WIN32_FIND_DATA ffd;
		TCHAR szDir[500];
		LARGE_INTEGER filesize;
		HANDLE hFind = INVALID_HANDLE_VALUE;
		DWORD dwError = 0;
		LPCWSTR filepathw;
		std::wstring stemp;
		char ch[260];
		char DefChar = ' ';

		stemp = s2ws(filepath);
		filepathw = stemp.c_str();
        std::string convertor(stemp.begin(), stemp.end());
		StringCchCopy(szDir, MAX_PATH, convertor.c_str());
		StringCchCat(szDir, 500, TEXT("\\*"));
		hFind = FindFirstFile(szDir, &ffd);

		if (INVALID_HANDLE_VALUE == hFind)
		{
			return fileList;
		}

		do
		{
			if (!(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				filesize.LowPart = ffd.nFileSizeLow;
				filesize.HighPart = ffd.nFileSizeHigh;
                std::string tmpStr = ffd.cFileName;
                std::wstring tmpWstr(tmpStr.begin(), tmpStr.end());
				WideCharToMultiByte(CP_ACP, 0, tmpWstr.c_str(), -1, ch, 260, &DefChar, NULL);
				fileList.push_back(std::string(ch));
			}
		} while (FindNextFile(hFind, &ffd) != 0);

		dwError = GetLastError();
		if (dwError != ERROR_NO_MORE_FILES)
		{
			;
		}

		FindClose(hFind);
		return fileList;
}

std::wstring zia::WindowsDirectoryReader::s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

zia::WindowsDirectoryReader::~WindowsDirectoryReader() {}
#endif