#include "PlayHUD.h"

USING_NS_CC;

PlayHUD::PlayHUD()
{

}

PlayHUD::~PlayHUD()
{

}

bool PlayHUD::init()
{
	if (!HUD::init())
	{
		return false;
	}


	return true;
}

void PlayHUD::TouchMove(Vec2 distance, Touch* touch)
{
	
}
