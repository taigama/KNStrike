#include "World.h"

//#include "Block.h"
#include "ResourceManager.h"
#include "MyPoolManager.h"
#include "CameraHelper.h"

USING_NS_CC;



World::World()
{
}

// on "init" you need to initialize your instance
bool World::init()
{

    //////////////////////////////
    // 1. super init first
    if ( !Node::init() )
    {
        return false;
    }

	//m_instance = this;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	this->scheduleUpdate();


	//////////////////////////////////////
	// 2. res Loading

	auto resManager = ResourceManager::GetInstance();
	resManager->LoadSprites();
	//resManager->loadTiledMap("prologue_tutorial.tmx", this);



    return true;
}



void World::ExitGame(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

Player* World::GetPlayer()
{
	return m_mainPlayer;
}

World::~World()
{
}