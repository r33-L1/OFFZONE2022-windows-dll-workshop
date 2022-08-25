# Windows DLL Hijacking Workshop
> Resources

There are a few options that I used to set when working with this kind of code:
1. Project Properties -> C/C++ -> Code Generation -> Runtime Library -> Multi-threaded Debug
2.  Project Properties -> General -> Configuration Type -> (DLL or EXE)

### DLLs:
 - SimpleLib
 - HijackLib
 - ProxyLib

### EXEs:
 - SimpleExe
 - SimpleExePrintHello
 
You can use Visual Studio CE to compile samples. You can create create one solution and add projects one by one.

## Notes
The code may vary depending on the architecture of the processor (x86 or ARM64). If you are using Windows 11 on an Apple M1, you may need to modify the code slightly.
