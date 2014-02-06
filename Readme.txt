
The crash hander can be integrated into any C++ project easily. The crash hander records useful information for in the event of a crash, it generates a MinidDump which can be used to analyze in amortem information. The following values are stored:

Exception Type
Current Register States
Call Stack
Loaded Modules

Debugging with a live debugger does NOT inhibit a live debugger is present.



To use:
Just wrap your code that you want to trap in a try except block like the following

	__try 
	{

		...

	
	} __except(WriteDump(GetExceptionInformation()))  { }