#pragma once
#include "gameObject.h"
#include "level.h"
// Class Tank
class Wall
	: public gameObject
{
public:
	Wall();
	virtual void render( renderSystem* rs );
	void setImage( unsigned char symbol, consoleColor symbolColor, consoleColor bgColor );
private:
	ConsoleSymbolData m_image;
};
