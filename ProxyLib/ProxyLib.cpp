#include <Windows.h>
#include <iostream>
#include "intercepts.h"

typedef int(__stdcall* f_print_hello)();

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		::MessageBoxW(NULL, L"ProxyLib DllMain", L"ProxyLib", 0);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

extern "C" int print_hello() {
	HINSTANCE			hSimpleLib;

	hSimpleLib = LoadLibraryA("SimpleLib_1.dll");
	if (hSimpleLib == NULL) {
		std::cout << "Error: Couldn't load Target DLL" << std::endl;
		return -1;
	}

	f_print_hello intrcpt_print_hello = (f_print_hello)GetProcAddress(hSimpleLib, "print_hello");
	if (!intrcpt_print_hello) {
		std::cout << "Cannot locate the function print_hello" << std::endl;
		return -1;
	}

	// any code
	::MessageBoxW(NULL, L"print_hello_intercepted", L"ProxyLib", 0);
	

	// Call original print_hello can be done here
	intrcpt_print_hello();

	return 0;

}
