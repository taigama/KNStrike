#ifndef __NODE_FREEZER_H__
#define __NODE_FREEZER_H__
#include "deprecated/CCArray.h"
#include "cocos2d.h"
// this CCNode* can be freezed, must be manual un-freezed
template <class T>
class NodeFreezer
{
public:
	void Freeze()
	{
        ((cocos2d::Node*)this)->pauseSchedulerAndActions();
		cocos2d::Vector<cocos2d::Node*> childs = ((cocos2d::Node*)this)->getChildren();
        for (cocos2d::Node* child : childs) {
            ((NodeFreezer*)child)->Freeze();
        }
	}

	void UnFreeze()
	{
        ((cocos2d::Node*)this)->pauseSchedulerAndActions();
        cocos2d::Vector<cocos2d::Node*> childs = ((cocos2d::Node*)this)->getChildren();
        for (cocos2d::Node* child : childs) {
            ((NodeFreezer*)child)->UnFreeze();
        }
	}
};
#endif//__NODE_FREEZER_H__