
#include "stdafx.h"
#include "jcg_terminal.h"

#if 1
BOOL Console::IsExistent = FALSE;

 Console::Console()
 {
  if (IsExistent)
   return;

  AllocConsole();
  Attach(300, 80);

  IsExistent = TRUE;
 }

 Console::Console(LPCTSTR lpszTitle, SHORT ConsoleHeight, SHORT ConsoleWidth)
 {
  if (IsExistent)
   return;

  AllocConsole();
  SetConsoleTitle(lpszTitle);
  Attach(ConsoleHeight, ConsoleWidth);

  IsExistent = TRUE;
 }

 void Console::Attach(SHORT ConsoleHeight, SHORT ConsoleWidth)
 {
  HANDLE  hStd;
  int     fd;
  FILE    *file;

// �ض����׼������������µĿ���̨����

  hStd = GetStdHandle(STD_INPUT_HANDLE);
  fd = _open_osfhandle(reinterpret_cast<intptr_t>(hStd), _O_TEXT); // �ı�ģʽ
  file = _fdopen(fd, "r");
  setvbuf(file, NULL, _IONBF, 0); // �޻���
  *stdin = *file;

// �ض����׼�����������µĿ���̨����

  hStd = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD size;
  size.X = ConsoleWidth;
  size.Y = ConsoleHeight;
  SetConsoleScreenBufferSize(hStd, size);
  fd = _open_osfhandle(reinterpret_cast<intptr_t>(hStd), _O_TEXT); //�ı�ģʽ
  file = _fdopen(fd, "w");
  setvbuf(file, NULL, _IONBF, 0); // �޻���
  *stdout = *file;

// �ض����׼������������µĿ���̨����

  hStd = GetStdHandle(STD_ERROR_HANDLE);
  fd = _open_osfhandle(reinterpret_cast<intptr_t>(hStd), _O_TEXT); // �ı�ģʽ
  file = _fdopen(fd, "w");
  setvbuf(file, NULL, _IONBF, 0); // �޻���
  *stderr = *file;

 }

 Console::~Console()
 {
  if (IsExistent)
  {
   FreeConsole();
   IsExistent = FALSE;
  }
 }
#endif