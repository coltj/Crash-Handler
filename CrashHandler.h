#pragma once

#include <Windows.h>
#include <dbghelp.h>
#include <cstdio>


LONG WINAPI WriteDump(EXCEPTION_POINTERS* pException);