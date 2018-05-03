#ifndef __ROOT_SCENE_H__
#define __ROOT_SCENE_H__

#include "cocos2d.h"
#include "SingleTon.h"

class Root : public cocos2d::Scene, public SingleInstance<Root>
{	
	//Won't allow public access
	Root() {};
	virtual ~Root();

	// this function show loading screen, and schedule InitTruly
	bool init() override;


	Node* m_inputLayer;
	Node* m_physics;
	Node* m_mainGame;
	Node* m_debugDraw;
	Node* m_frameCleaner;

public:

	// initialize framework
	void InitBase(float);
	// initialize resources, object
	void InitObject(float);

	// implement the "static create()" method manually
	CREATE_FUNC(Root);
};

#endif