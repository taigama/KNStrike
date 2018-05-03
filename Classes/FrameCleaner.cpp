#include "FrameCleaner.h"
#include "GlobalSetting.h"//ENABLE_KEY_INPUT here
#include "InputLayer.h"

bool FrameCleaner::init()
{
	if (!Node::init())
		return false;


	scheduleUpdate();

	return true;
}

void FrameCleaner::update(float delta)
{
#ifdef ENABLE_KEY_INPUT
	Input::GetInstance()->CleanKeyEvent();
#endif
}

