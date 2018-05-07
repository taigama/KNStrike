#ifndef __MAIN_GAME_H__
#define __MAIN_GAME_H__

#include "cocos2d.h"
#include "SingleTon.h"

class MainGame : public cocos2d::Node, public SingleInstance<MainGame>
{
	Node* m_background;
	Node* m_world;
	Node* m_HUD;

	cocos2d::Vector<Node*> m_HUDs;


	// this function show loading screen, and schedule InitTruly
	bool init() override;
public:

	MainGame();
	virtual ~MainGame();

	// implement the "static create()" method manually
	CREATE_FUNC(MainGame);
};

#endif//__MAIN_GAME_H__