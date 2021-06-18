# DarkModeDetectionWIN32
A sample program which listens for dark mode change in Qt/MSVC applications using WinRT API. The project uses CMake build system to make sure only to build in Win32 environment.

## Configure
```
cmake -B build -G "Visual Studio 16 2019" -T host=x64 -A x64
```

## Build
```
cmake --build build --config [Debug/Release/MinSizeRel/RelWithDebInfo/] --target [ALL_BUILD/ZERO_CHECK/DarkModeDetectionWIN32/clean] -j 10 --
```
