#pragma once
#include <Windows.h>
#include "consoleColor.h"

const int kScreenRows = 25;
const int kScreenColumns = 80;
struct ConsoleSymbolData
{
	char symbol;
	consoleColor symbolColor;
	consoleColor backgroundColor;
};

class renderSystem
{
public:
	renderSystem();
	void initialize();
	void clear();
	void drawChar( int r, int c, char symbol, consoleColor symbolColor, consoleColor backgroundColor );
	void drawText( int r, int c, const char* text, consoleColor symbolColor, consoleColor backgroundColor );
	void flush();
private:
	void setConsoleCursor( int r, int c );
	void setConsoleColor( consoleColor symbolColor, consoleColor backgroundColor );
private:
	HANDLE m_consoleHandle;
	ConsoleSymbolData m_backBuffer[kScreenRows][kScreenColumns];
	ConsoleSymbolData m_screenBuffer[kScreenRows][kScreenColumns];
};