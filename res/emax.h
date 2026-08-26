#ifndef EMAX_H
#define EMAX_H

#define GLOBAL(TYPE, NAME)\ 
    TYPE    g_##NAME;\
    TYPE    g_get_##NAME() { return g_##NAME; }\
    void    g_set_##NAME(TYPE newval) { g_##NAME = newval; }
#define GLOBAL_I(TYPE, NAME, VAL)\
    TYPE    g_##NAME = VAL;\
    TYPE    g_get_##NAME() { return g_##NAME; }\
    void    g_set_##NAME(TYPE newval) { g_##NAME = newval; }
#define ELSEDF(TYPE, NAME) extern TYPE NAME;
#define GET(NAME) g_get_##NAME()
#define SET(NAME, VAL) g_set_##NAME(VAL)
#define REF(NAME) g_##NAME
#define CONSTANT(TYPE, NAME, VALUE)\
    const TYPE g_##NAME = VALUE;\
    const TYPE g_get_##NAME() { return g_##NAME; } 

#ifdef __cplusplus
    #define EMPTY(OBJ) (nullptr == OBJ)
    #define LATER(NAME) class NAME;
#else
    #define EMPTY(OBJ) (NULL == OBJ)
    #define LATER(NAME) struct NAME;
#endif

#ifdef _WIN32
#include <Windows.h>
typedef HMODULE Dylib
#define EXPORT __declspec(dllexport)
#define OpenModule(PATH) LoadLibraryA(PATH)
#define GetSymbol(MODULE, NAME) GetProcAddress(MODULE, NAME)
#define CloseModule(MODULE) FreeLibrary(MODULE)
#else
#include <dlfcn.h>
#define EXPORT __attribute__((visibility("default")))
typedef void* Dylib;
#define OpenModule(PATH) dlopen(PATH, RTLD_LAZY)
#define GetSymbol(MODULE, NAME) dlsym(MODULE, NAME)
#define CloseModule(MODULE) dlclose(MODULE)
#endif



#endif
