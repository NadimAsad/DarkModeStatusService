# DarkModeStatusService
CMake based library which provides a service with an interface which allows you to query dark mode status for an operating system.

## Supports
win32

## Planned Support
macOS

## Configure
```
cmake -B build
```

## Build
```
cmake --build build --config [Debug/Release/MinSizeRel/RelWithDebInfo] --target [ALL_BUILD/ZERO_CHECK/DarkModeDetectionWIN32/clean] -j 10 --
```
