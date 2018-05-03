#ifndef __NODE_FREEZER_H__
#define __NODE_FREEZER_H__
#include "deprecated/CCArray.h"

// this CCNode* can be freezed, must be manual un-freezed
template <class T>
class NodeFreezer
{
public:
	void Freeze()
	{
		this->pauseSchedulerAndActions();
		CCArray* childs = this->getChildren();
		CCObject* child;
		CCARRAY_FOREACH(childs, child)
		{
			NodeFreezer* node = (NodeFreezer)child;
			child->Freeze();
		}
	}

	void UnFreeze()
	{
		this->resumeSchedulerAndActions();
		CCArray* childs = this->getChildren();
		CCObject* child;
		CCARRAY_FOREACH(childs, child)
		{
			NodeFreezer* node = (NodeFreezer)child;
			child->UnFreeze();
		}
	}
};
#endif//__NODE_FREEZER_H__