#ifndef __MAIN_HUD__
#define __MAIN_HUD__

#include "HUD.h"

class MainHUD : public HUD
{
private:
	void OnClickHahaha(cocos2d::Ref* sender);

protected:
	bool init() override;

public:
	MainHUD();
	~MainHUD();

	CREATE_FUNC(MainHUD);

};





#endif//__MAIN_HUD__