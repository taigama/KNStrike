#ifndef __PLAY_HUD__
#define __PLAY_HUD__
#include "HUD.h"
#include "SingleTon.h"

class PlayHUD : public HUD, public SingleInstance<PlayHUD>
{
protected:
	bool init() override;

public:
	PlayHUD();
	~PlayHUD();

	CREATE_FUNC(PlayHUD);


	void TouchMove(cocos2d::Vec2 distance, cocos2d::Touch* touch);
};
#endif//__PLAY_HUD__