#include "renderSystem.h"
#include <cstdio>

renderSystem::renderSystem()
{
	m_consoleHandle = 0;
	for( int r = 0; r < kScreenRows; r++ )
	{
		for( int c = 0; c < kScreenColumns; c++ )
		{
			m_backBuffer[r][c].symbol = 0;
			m_backBuffer[r][c].symbolColor = ConsoleColor_Gray;
			m_backBuffer[r][c].backgroundColor = ConsoleColor_Black;
			m_screenBuffer[r][c] = m_backBuffer[r][c];
		}
	}
}

void renderSystem::initialize()
{
	// пишем название свое
	system("title Tank Battle");
	//размер консоли
	system("mode con cols=80 lines=25");
	// Get console handle
	m_consoleHandle = GetStdHandle( STD_OUTPUT_HANDLE );
	// Hide console cursor
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(m_consoleHandle, &cursorInfo);
}

void renderSystem::clear()
{
	for( int r = 0; r < kScreenRows; r++ )
	{
		for( int c = 0; c < kScreenColumns; c++ )
		{
			m_backBuffer[r][c].symbol = 0;
			m_backBuffer[r][c].backgroundColor = ConsoleColor_Black;
		}
	}
}

void renderSystem::drawChar( int r, int c, char symbol, consoleColor symbolColor, consoleColor backgroundColor )
{
	if( r < 0 || c < 0 || r >= kScreenRows || c >= kScreenColumns )
		return;
	m_backBuffer[r][c].symbol = symbol;
	m_backBuffer[r][c].symbolColor = symbolColor;
	m_backBuffer[r][c].backgroundColor = backgroundColor;
}

void renderSystem::drawText( int r, int c, const char* text, consoleColor symbolColor, consoleColor backgroundColor )
{
	int column = c;
	char symbol = *text;
	while( symbol != 0 )
	{
		drawChar(r, column, symbol, symbolColor, backgroundColor);
		text++;
		column++;
		symbol = *text;
	}
}

void renderSystem::flush()
{
	bool screenBufferModified = false;
	for( int r = 0; r < kScreenRows; r++ )
	{
		for( int c = 0; c < kScreenColumns; c++ )
		{
			if(    ( m_backBuffer[r][c].symbol			!= m_screenBuffer[r][c].symbol )
				|| ( m_backBuffer[r][c].symbolColor		!= m_screenBuffer[r][c].symbolColor )
				|| ( m_backBuffer[r][c].backgroundColor	!= m_screenBuffer[r][c].backgroundColor ) )
			{
				// Copy symbol data from back to screen buffer
				m_screenBuffer[r][c] = m_backBuffer[r][c];
				// Draw symbol in (r,c) position
				setConsoleCursor( r, c );
				setConsoleColor( m_screenBuffer[r][c].symbolColor, m_screenBuffer[r][c].backgroundColor );				
				printf("%c", m_screenBuffer[r][c]);
				screenBufferModified = true;
			}
		}
	}
	// Return console cursor to (0,0)
	if( screenBufferModified )
		setConsoleCursor( 0, 0 );
}

void renderSystem::setConsoleCursor( int r, int c )
{
	COORD cursorCoord;
	cursorCoord.X = c;
	cursorCoord.Y = r;
    SetConsoleCursorPosition( m_consoleHandle, cursorCoord );
}

void renderSystem::setConsoleColor( consoleColor symbolColor, consoleColor backgroundColor )
{
	unsigned char consoleColor = symbolColor | (backgroundColor << 4);
	SetConsoleTextAttribute( m_consoleHandle, consoleColor );
}