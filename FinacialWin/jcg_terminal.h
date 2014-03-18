#ifndef _CUSTOM_CONSOLE_
#define _CUSTOM_CONSOLE_

#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <windows.h>

class Console
{
public:
 Console();
 Console(LPCTSTR lpszTitle, SHORT ConsoleHeight = 300, SHORT ConsoleWidth = 80);
 ~Console();

private:
 void Attach(SHORT ConsoleHeight, SHORT ConsoleWidth);
 static BOOL IsExistent;
};

#endif