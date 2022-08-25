#include <Windows.h>
#include <stdio.h>
#include <string>

extern "C" __declspec(dllexport) int __stdcall add_numbers(int a, int b);

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		::MessageBoxW(NULL, L"Hello from DllMain HijackDLL!", L"HijackLib", 0);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

int add_numbers(int a, int b) {
	::MessageBoxW(NULL, L"Hijacked now", L"HijackDLL", 0);
	// place for code
	return 2;
}
