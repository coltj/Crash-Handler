#include "CrashHandler.h"

LONG WINAPI WriteDump(EXCEPTION_POINTERS* pException)
{
	if (pException != 0)
	{
		HANDLE hFile = CreateFile((L"MiniDump.dmp"), GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		
		if((hFile != NULL) && (hFile != INVALID_HANDLE_VALUE)) 
		{
			// Create the minidump 
			MINIDUMP_EXCEPTION_INFORMATION mdei; 
			mdei.ThreadId           = GetCurrentThreadId(); 
			mdei.ExceptionPointers  = pException;
			mdei.ClientPointers     = FALSE; 
		  
			MINIDUMP_TYPE mdt       = (MINIDUMP_TYPE)(MiniDumpNormal | MiniDumpWithDataSegs | MiniDumpWithIndirectlyReferencedMemory | MiniDumpWithFullMemory);

		  
			BOOL rv = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, mdt, &mdei, 0, 0); 
		  
			if(!rv) 
				printf(("MiniDumpWriteDump failed. Error: %u \n"), GetLastError()); 
		  
			else 
				printf(("Minidump created.\n") ); 
		  
			// Close the file 
			CloseHandle(hFile); 
		}
		else 
		{
			printf(("CreateFile failed. Error: %u \n"), GetLastError()); 
		}
	}
	return EXCEPTION_CONTINUE_SEARCH;
}