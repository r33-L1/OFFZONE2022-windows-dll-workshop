#pragma once
#include <Windows.h>
#include <stdio.h>
#include <string>

extern "C" __declspec(dllexport) int __stdcall add_numbers(int a, int b);
extern "C" __declspec(dllexport) int __stdcall print_hello();
extern "C" __declspec(dllexport) int __stdcall ordinal_test();
