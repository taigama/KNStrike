#include "HUD.h"
#include "CameraHelper.h"

bool HUD::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Node::init())
	{
		return false;
	}

	return true;
}

void HUD::InitAfter(float)
{
	SetFollowCamera();	
}

void HUD::SetFollowCamera()
{
	schedule(CC_SCHEDULE_SELECTOR(HUD::FollowCamera));
}


void HUD::FollowCamera(float delta)
{
	this->setPosition(CameraHelper::GetInstance()->getPosition());
}