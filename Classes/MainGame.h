#ifndef __MAIN_GAME_H__
#define __MAIN_GAME_H__

#include "cocos2d.h"
#include "SingleTon.h"

class MainGame : public cocos2d::Node, public SingleInstance<MainGame>
{	
	//Won't allow public access
	MainGame() {};
	virtual ~MainGame() {};

	Node* m_background;
	Node* m_world;
	Node* m_HUD;


	// this function show loading screen, and schedule InitTruly
	bool init() override;
public:

	// implement the "static create()" method manually
	CREATE_FUNC(MainGame);
};

#endif//__MAIN_GAME_H__