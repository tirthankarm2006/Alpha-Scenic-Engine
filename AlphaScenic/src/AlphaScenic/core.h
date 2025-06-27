#pragma once

#ifdef AS_PLATFORM_WINDOWS
     #ifdef AS_BUILD_DLL
          #define AS_API __declspec(dllexport)
     #else 
          #define AS_API __declspec(dllimport) 
     #endif
#else
     #error Alpha Scenic supports Windows only for now
#endif

