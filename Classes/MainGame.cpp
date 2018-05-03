#include "MainGame.h"
#include "Background.h"
#include "World.h"
#include "HUD.h"

bool MainGame::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Node::init())
	{
		return false;
	}

	m_background = Background::create();
	this->addChild(m_background);
	m_world = World::create();
	this->addChild(m_world);
	m_HUD = HUD::create();
	this->addChild(m_HUD);

	
	return true;
}