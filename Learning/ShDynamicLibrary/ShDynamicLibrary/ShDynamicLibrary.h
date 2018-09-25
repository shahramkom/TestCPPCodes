// ShLibrary.h - Contains declarations of math functions
#pragma once

#ifdef SHDYNAMICLIBRARY_EXPORTS
#define SHDYNAMICLIBRARY_API __declspec(dllexport)
#else
#define SHDYNAMICLIBRARY_API __declspec(dllimport)
#endif
#include <string>

using std::string;

extern "C" SHDYNAMICLIBRARY_API unsigned long ipFromStringToDword(const string& inputIP);
extern "C" SHDYNAMICLIBRARY_API string ipFromDwordToString(const unsigned long& inputIP);
extern "C" SHDYNAMICLIBRARY_API bool isIpInRange(const unsigned long& inputIP, const unsigned long& rangeIP, const unsigned long& rangeMask);
extern "C" SHDYNAMICLIBRARY_API unsigned long countIpInRange(const unsigned long& rangeIP, const unsigned long& rangeMask);