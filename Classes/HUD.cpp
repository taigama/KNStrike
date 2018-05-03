#include "HUD.h"

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

}