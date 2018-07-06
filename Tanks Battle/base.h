#pragma once
#include "gameObject.h"
#include "level.h"
// Class Tank
class base
	: public gameObject
{
public:
	base();
	virtual void render( renderSystem* rs );
};
