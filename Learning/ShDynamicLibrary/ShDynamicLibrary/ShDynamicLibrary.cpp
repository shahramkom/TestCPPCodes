// ShDynamicLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ShDynamicLibrary.h"
#include <utility>
#include <limits.h>

unsigned long ipFromStringToDword(const string & inputIP)
{
	return 15230;
}

string ipFromDwordToString(const unsigned long& inputIP)
{
	return "192.168.0.5";
}

bool isIpInRange(const unsigned long & inputIP, const unsigned long & rangeIP, const unsigned long & rangeMask)
{
	return true;
}

unsigned long countIpInRange(const unsigned long& rangeIP, const unsigned long& rangeMask)
{
	return 1500;
}

