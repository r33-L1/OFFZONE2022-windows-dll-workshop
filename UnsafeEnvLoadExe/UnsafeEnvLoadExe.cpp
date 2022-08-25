#include <Windows.h>
#include <iostream>
#include <string>

int main() {

	WCHAR sys_path[MAX_PATH];
	WCHAR win_path[MAX_PATH];

	if (!::GetSystemDirectoryW(sys_path, MAX_PATH))  // C:\Windows\System32
		std::cout << "Cannot obtain System directory" << std::endl;
	std::wstring wsSystemPath = std::wstring(sys_path);

	if (!::GetWindowsDirectoryW(win_path, MAX_PATH))  // C:\Windows
		std::cout << "Cannot obtain Windows directory" << std::endl;
	std::wstring wsWindowsPath = std::wstring(win_path);

	std::wcout << "System Directory: " << wsSystemPath << std::endl;
	std::wcout << "Windows Directory: " << wsWindowsPath << std::endl;

	char* sysroot = nullptr;
	size_t sz = 0;
	if (_dupenv_s(&sysroot, &sz, "SYSTEMROOT") != 0 || sysroot == nullptr) {  // %SYSTEMROOT% = C:\Windows
		std::cout << "Cannot obtain environmentecho variable" << std::endl;
		free(sysroot);
		return -1;
	}
	std::string modulePath = std::string(sysroot) + std::string("\\System32\\SimpleLib.dll");

	std::cout << modulePath << std::endl;
	HINSTANCE hModule = ::LoadLibraryA(modulePath.c_str());
	if (NULL == hModule) {
		std::cout << "Cannot load DLL" << std::endl;
		return -1;
	}

	return 0;
}
