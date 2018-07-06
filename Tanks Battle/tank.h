#pragma once
#include "gameObject.h"
#include "level.h"

class tank
	: public gameObject
{
public:
	tank();
	virtual void update( float dt );
	virtual void render( renderSystem* rs );
	void setColor( consoleColor tankColor1, consoleColor tankColor2 );
	void move( direction direction );
	void fire();
protected:
	void calculateFrontCellPosition( float* x, float* y );
protected:
	ConsoleSymbolData m_tankImage[Direction_MAX][kTankSize][kTankSize];
	float m_fireCooldownTime;
	float m_speed;
};
