#include "SimpleLib.h"

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		::MessageBoxW(NULL, L"Hello from DllMain SimpleLib!", L"SimpleLib", 0);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

int add_numbers(int a, int b) {
	::MessageBoxW(NULL, L"Hello from add_numbers!", L"SimpleLib", 0);
	return a + b;
}

int print_hello() {
	::MessageBoxW(NULL, L"Hello from print_hello!", L"SimpleLib", 0);
	return 0;
}

int ordinal_test() {
	::MessageBoxW(NULL, L"Hello from ordinal_test!", L"SimpleLib", 0);
	return 0;
}
