#include "MainGame.h"
#include "Background.h"
#include "World.h"
#include "PlayHUD.h"
#include "MainHUD.h"


MainGame::MainGame()
{
	
}

MainGame::~MainGame()
{
	m_HUDs.clear();
}

bool MainGame::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Node::init())
	{
		return false;
	}

	m_HUDs.pushBack(MainHUD::create());
	m_HUDs.pushBack(PlayHUD::create());

	m_background = Background::create();
	this->addChild(m_background);
	m_world = World::create();
	this->addChild(m_world);
	m_HUD = m_HUDs.at(0);// main HUD
	this->addChild(m_HUD);

	
	return true;
}