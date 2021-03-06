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

	SetFollowCamera();

	return true;
}

void HUD::SetFollowCamera()
{
	schedule(CC_SCHEDULE_SELECTOR(HUD::FollowCamera));
}


void HUD::FollowCamera(float delta)
{
	this->setPosition(CameraHelper::GetInstance()->getPosition());
}