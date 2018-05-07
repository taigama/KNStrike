#ifndef __HUD_H__
#define __HUD_H__

#include "cocos2d.h"

class HUD : public cocos2d::Node
{	
protected:
	//Won't allow public access
	HUD() {};
	virtual ~HUD() {};

	// this function show loading screen, and schedule InitTruly
	bool init() override;
	void SetFollowCamera();
public:
	void FollowCamera(float);

	// implement the "static create()" method manually
	CREATE_FUNC(HUD);
};

#endif//__HUD_H__