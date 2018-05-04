#include "RootScene.h"
#include "InputLayer.h"
#include "MyPhysicsWorld.h"
#include "MainGame.h"
#include "DebugDraw.h"
#include "FrameCleaner.h"

#include "ResourceManager.h"
#include "MyPoolManager.h"
#include "CameraHelper.h"

bool Root::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	// show the loading screen here
	
	scheduleOnce(CC_SCHEDULE_SELECTOR(Root::InitBase), 0.0f);
	return true;
}

void Root::InitBase(float)
{
	CameraHelper::GetInstance();

	m_inputLayer = Input::create();
	this->addChild(m_inputLayer);
	m_physics = MyPhysicsWorld::create();
	this->addChild(m_physics);
	m_mainGame = MainGame::create();
	this->addChild(m_mainGame);
	m_debugDraw = DebugDraw::create();
	this->addChild(m_debugDraw);
	m_frameCleaner = FrameCleaner::create();
	this->addChild(m_frameCleaner);

	ResourceManager::GetInstance();
	MyPoolManager::GetInstance();

	scheduleOnce(CC_SCHEDULE_SELECTOR(Root::InitObject), 0.0f);
}

void Root::InitObject(float)
{
	//CameraHelper::GetInstance()-> preload
	//ResourceManager::GetInstance()->preload
	//MyPoolManager::GetInstance()->preload
	
}

Root::~Root()
{
	CameraHelper::CleanInstance();
	ResourceManager::CleanInstance();
	MyPoolManager::CleanInstance();
}