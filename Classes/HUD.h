#ifndef __HUD_H__
#define __HUD_H__

#include "cocos2d.h"
#include "SingleTon.h"

class HUD : public cocos2d::Node, public SingleInstance<HUD>
{	
	//Won't allow public access
	HUD() {};
	virtual ~HUD() {};

	// this function show loading screen, and schedule InitTruly
	bool init() override;
public:

	// initialize object
	void InitAfter(float);

	// implement the "static create()" method manually
	CREATE_FUNC(HUD);
};

#endif//__HUD_H__