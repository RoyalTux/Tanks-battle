#pragma once
#include "renderSystem.h"
#include <ctime>
#include "gameObject.h"
#include "gameObjectType.h"

const int kObjectsCountMax = 1024;
// Forward declaration
class gameObject;
// Class Game
class game
{
public:
	game();
	void setupSystem();
	void initialize();
	bool loop();
	void shutdown();
	void start();
	gameObject* createObject( gameObjectType type, float x, float y );
	void destroyObject( gameObject* object );
	gameObject* checkIntersects( float x, float y, float width, float height, gameObject* exceptObject );
	bool moveObjectTo( gameObject* object, float x, float y );
	int getObjectsCount( gameObjectType type );
	int getDiedEnemiesCount(){ return m_diedEnemiesCount; }
	void increaseDiedEnemiesCount();
private:
	void render();
	void update( float dt );
private:
	bool m_isGameActive;
	clock_t m_clockLastFrame;
	renderSystem m_renderSystem;
	gameObject* m_objects[kObjectsCountMax];
	gameObject* m_base;
	gameObject* m_player1;
	gameObject* m_player2;
	int m_diedEnemiesCount;
};