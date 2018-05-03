#ifndef __FRAME_CLEANER_H__
#define __FRAME_CLEANER_H__

#include "cocos2d.h"

class FrameCleaner : public cocos2d::Node
{

	bool init() override;

public:
	CREATE_FUNC(FrameCleaner);
	void update(float delta) override;
};

#endif//__FRAME_CLEANER_H__