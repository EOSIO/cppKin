#pragma once

#if defined(WIN32)
    #ifdef CORE_DLL
    #define CORE_EXPORT __declspec(dllexport)
    #else
    #define CORE_EXPORT __declspec(dllimport)
    #endif
    #ifdef CPPKIN_DLL
    #define CPPKIN_EXPORT __declspec(dllexport)
    #else
    #define CPPKIN_EXPORT __declspec(dllimport)
    #endif
#else
    #define CORE_EXPORT
    #define CPPKIN_EXPORT
#endif