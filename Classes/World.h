#ifndef __WORLD_SCENE_H__
#define __WORLD_SCENE_H__

#include "cocos2d.h"
#include "SingleTon.h"

class Player;

class World : public cocos2d::Node, public SingleInstance<World>
{
public:
	World();
	~World();

	enum WORLD_LAYER
	{		
		BACKGROUND = -3,
		EFFECT_BACKGROUND = -2,
		TILED_MAP = -1,
		GROUND = 0,
		EFFECT_BACK = 1,
		OBJECT = 2,
		PLAYER = 3,
		EFFECT_FRONT = 4
	};


    bool init() override;

    // a menu close callback
    void ExitGame(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(World);


	// Returns the main player of the game
	Player* GetPlayer();




private:

	Player* m_mainPlayer;
};

#endif // __WORLD_SCENE_H__
