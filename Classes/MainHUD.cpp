#include "MainHUD.h"

USING_NS_CC;

MainHUD::MainHUD()
{
	
}

MainHUD::~MainHUD()
{
	
}

bool MainHUD::init()
{
	if(!HUD::init())
	{
		return false;
	}

	Node* a = Scene::create();
	a->retain();


	return true;
}
