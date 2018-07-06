#pragma once
#include "gameObject.h"
#include "level.h"
// Class Tank
class Bullet
	: public gameObject
{
public:
	Bullet();
	virtual void render( renderSystem* rs );
	virtual void intersect( gameObject* object );
	void setImage( char symbol, consoleColor symbolColor, consoleColor bgColor );
	void setOwnerType( gameObjectType ownerType ){ m_ownerType = ownerType; }
	gameObjectType getOwnerType(){ return m_ownerType; }
private:
	ConsoleSymbolData m_image;
	gameObjectType m_ownerType;
};
