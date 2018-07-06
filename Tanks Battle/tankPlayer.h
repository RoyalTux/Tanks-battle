#pragma once
#include "tank.h"

class tankPlayer
	: public tank
{
public:
	tankPlayer();
	void update( float dt );
	void setKeys( int keyLeft, int keyRight, int keyUp, int keyDown, int keyFire );
protected:
	int m_keyLeft;
	int m_keyRight;
	int m_keyUp;
	int m_keyDown;
	int m_keyFire;
};
