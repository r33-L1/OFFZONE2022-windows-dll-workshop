#include <Windows.h>
#include <iostream>

typedef int(__stdcall* f_print_hello)();

int main() {

	HINSTANCE hSimpleLib = ::LoadLibraryExW(L"SimpleLib.dll", NULL, LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);
	// HINSTANCE hSimpleLib = ::LoadLibraryExW(L"SimpleLib.dll", NULL, LOAD_LIBRARY_SEARCH_APPLICATION_DIR);
	// HINSTANCE hSimpleLib = ::LoadLibraryExW(L"SimpleLib.dll", NULL, LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR);
	// HINSTANCE hSimpleLib = ::LoadLibraryExW(L"SimpleLib.dll", NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
	// HINSTANCE hSimpleLib = ::LoadLibraryExW(L"SimpleLib.dll", NULL, LOAD_LIBRARY_SEARCH_USER_DIRS);
	// HINSTANCE hSimpleLib = ::LoadLibraryExW(L"SimpleLib.dll", NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
	// HINSTANCE hSimpleLib = ::LoadLibraryExW(L"SimpleLib.dll", NULL, LOAD_LIBRARY_SAFE_CURRENT_DIRS);
	// HINSTANCE hSimpleLib = ::LoadLibraryExW(L"SimpleLib.dll", NULL, LOAD_LIBRARY_REQUIRE_SIGNED_TARGET);

	if (!hSimpleLib) {
		std::cout << "Cannot load Dll" << std::endl;
		return -1;
	}

	f_print_hello print_hello = (f_print_hello)GetProcAddress(hSimpleLib, "print_hello");
	if (!print_hello) {
		std::cout << "could not locate the function" << std::endl;
		return EXIT_FAILURE;
	}

	print_hello();

	return EXIT_SUCCESS;

	return 0;
}
