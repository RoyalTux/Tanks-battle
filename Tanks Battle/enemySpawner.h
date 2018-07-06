#pragma once
#include "gameObject.h"
#include "level.h"
// Class Tank
class enemySpawner
	: public gameObject
{
public:
	enemySpawner();
	virtual void update( float dt );
private:
	float m_spawnTimer;
	float m_spawnTime;
};
