//#ifndef __CAMERA_HELPER_H__
//class CameraHelper;
//#endif
//
//#ifndef __HELLOWORLD_SCENE_H__
//#define __HELLOWORLD_SCENE_H__
//
//#include "cocos2d.h"
//#include "Box2D\Box2D.h"
//
//#include "ContactListener.h"
//
//class HelloWorld : public cocos2d::Scene
//{
//	CameraHelper* _camera;
//	static HelloWorld* _instance;
//	bool _showB2Debug = false;
//
//	// implement the "static create()" method manually
//	static HelloWorld* create();
//	b2Body* barBody;
//public:
//	static HelloWorld* getInstance();
//	bool isShowB2Debug() { return _showB2Debug; };
//    static cocos2d::Scene* createScene();
//
//    virtual bool init();
//    
//    // a selector callback
//    void menuCloseCallback(cocos2d::Ref* pSender);
//
//	cocos2d::EventListenerTouchOneByOne* toucher;
//	cocos2d::EventListenerTouchOneByOne* toucherBall;
//    
//	// ------- physics world
//	b2World* world;// World with physics
//
//	// -------- single
//	b2Body* ballBody;// Body of ball
//	//b2BodyDef bodyDef;// Define the above body
//	//b2FixtureDef fixtureDef;// Define some physics attributes
//	//b2CircleShape bodyShape;// shape of the body
//	// _______________________________
//
//	void delayLoad(float);
//	void onKeyEnter(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
//
//	cocos2d::Sprite* ball;
//	float deltaTime;
//	
//	cocos2d::Vec2 m_vecMove;
//	
//	void addWall(float w, float h, float px, float py);// create a wall that keep the ball inside
//	void update(float timeDelta);
//};
//
//#endif // __HELLOWORLD_SCENE_H__
