#include <Windows.h>
#include <iostream>

typedef int(__stdcall* f_add_numbers)(int a, int b);

int main() {

	HINSTANCE hSimpleLib = ::LoadLibraryExW(L"SimpleLib.dll", NULL, LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);
	// HINSTANCE hSimpleLib = ::LoadLibraryExW(L"SimpleLib.dll", NULL, LOAD_LIBRARY_SEARCH_APPLICATION_DIR);
	// HINSTANCE hSimpleLib = ::LoadLibraryExW(L"SimpleLib.dll", NULL, LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR);
	// HINSTANCE hSimpleLib = ::LoadLibraryExW(L"SimpleLib.dll", NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
	// HINSTANCE hSimpleLib = ::LoadLibraryExW(L"SimpleLib.dll", NULL, LOAD_LIBRARY_SEARCH_USER_DIRS);
	// HINSTANCE hSimpleLib = ::LoadLibraryExW(L"SimpleLib.dll", NULL, LOAD_LIBRARY_SAFE_CURRENT_DIRS);
	// HINSTANCE hSimpleLib = ::LoadLibraryExW(L"SimpleLib.dll", NULL, LOAD_LIBRARY_REQUIRE_SIGNED_TARGET);

	if (!hSimpleLib) {
		std::cout << "Cannot load Dll" << std::endl;
		return -1;
	}

	f_add_numbers add_numbers = (f_add_numbers)GetProcAddress(hSimpleLib, "add_numbers");
	if (!add_numbers) {
		std::cout << "could not locate the function" << std::endl;
		return EXIT_FAILURE;
	}

	int res = add_numbers(3, 5);

	std::cout << "add_numbers(3,5) returned " << res << std::endl;

	return EXIT_SUCCESS;

	return 0;
}
