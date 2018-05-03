#include "InputLayer.h"

USING_NS_CC;

#ifdef ENABLE_KEY_INPUT
std::map<KEY_CODE, bool> Input::m_keyDown = std::map<KEY_CODE, bool>();
std::map<KEY_CODE, bool> Input::m_key = std::map<KEY_CODE, bool>();
std::map<KEY_CODE, bool> Input::m_keyUp = std::map<KEY_CODE, bool>();
#endif

bool Input::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

#ifdef ENABLE_KEY_INPUT
	InitKey();
#endif
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	setTouchEnabled(true);
	return true;
}

void Input::onTouchMoved(Touch* touch, Event* e)
{// empty
}

void Input::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* unused_event)
{
	
}

#ifdef ENABLE_KEY_INPUT
void Input::InitKey()
{
	for (int i = 0; i <= int(KEY_CODE::KEY_PLAY); i++)
	{
		m_keyDown[KEY_CODE(i)] = false;
		m_key[KEY_CODE(i)] = false;
		m_keyUp[KEY_CODE(i)] = false;
	}
}

bool Input::GetKeyDown(KEY_CODE key)
{
	return m_keyDown[key];
}

bool Input::GetKeyUp(KEY_CODE key)
{
	return m_keyUp[key];
}

bool Input::GetKey(KEY_CODE key)
{
	return m_key[key];
}
/* Clean the stored key event
* clean key_down & key_up
* the events will stored again after MAIN_UPDATE & before MAIN_UPDATE (look at the kernel)
* MUST BE CALLED AT THE END OF MAIN_UPDATE, JUST BEFORE the event re-polling
*/
void Input::CleanKeyEvent()
{
	for (int i = 0; i <= (int)KEY_CODE::KEY_PLAY; i++)
	{
		m_keyDown[(KEY_CODE)i] = false;
		m_keyUp[(KEY_CODE)i] = false;
	}
}
#endif
