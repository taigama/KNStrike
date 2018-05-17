#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__


#include "AudioEngine.h"
#define AUDIO experimental::AudioEngine

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "NodeFreezer.h"

// base class of all GameObject
class GameObject : public cocos2d::Node, public NodeFreezer<GameObject>
{
public:

	enum OBJECT_TYPE
	{
		NONE = 0,
		CHARACTER = 1,			// 0000 0001
		PROJECTILE = 1 << 1,	// 0000 0010
		BLOCK = 1 << 2,			// 0000 0100
		ITEM = 1 << 3,			// 0000 1000
		ZONE = 1 << 4,			// 0001 0000
		EFFECT = 1 << 5,		// 0010 0000
		DUMMY = 1 << 6,			// 0100 0000
		TEXT_EFFECT = 1 << 7	// 1000 0000
	};

	virtual ~GameObject();

	CREATE_FUNC(GameObject);

	/**
	 * Initializes the class ; called automatically by "create" function
	 */
	bool init() override;

	/**
	 * Called every frame if "scheduleUpdate()" is callled and the node is "live"
	 * Overrides the "update()" function of Cocos2d
	 * @param delta : float; time in seconds between each frame
	 */
	void update(float) override;

	/**
	 * Returns the Rect bouding the node
	 */
	cocos2d::Rect getBoundingBox() const override;

	/**
	 * For pool manager management ("RE-USE" concept)
	 * Enemy dies? -> Make it in-active
	 * @param active : bool; determine to enable (make active) or disable (make in-active) the object
	 */
	void SetActive(bool active);
	bool IsActive() const;

	/*Implemented by inherited classes that are handle by PoolManager
	 *
	 * @param params :	0 - x position
	 *					1 - y position
	 *					2 - based on type
	 */
	virtual void reset(float params[10]) {};// if use PURE here => can't use CREATE_FUNC


	virtual void ContactBegin(b2Contact* contact, GameObject* target) {};
	virtual void ContactEnd(b2Contact* contact, GameObject* target) {};
	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold, GameObject* target) {};
	virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse, GameObject* target) {};


	// -------------------

	// _type : enum OBJECT_TYPE ; specifies the type of object
	// To get -> getType()
	CC_SYNTHESIZE_READONLY(OBJECT_TYPE, _type, Type);

	// _body : cocos2d::PhysicsBody* ; contains the physics body of current object (sprite/node)
	// To get -> getBody()
	CC_SYNTHESIZE_READONLY(b2Body*, _body, Body);

	// _sprite : cocos2d::Sprite* ; contains the current sprite of the object
	// To get -> getSprite()
	CC_SYNTHESIZE_READONLY(cocos2d::Sprite*, _sprite, Sprite);

	// send a message to this object
	virtual void Message(std::string your_message) {};

	virtual void StopBody();
	virtual void ResumeBody();

protected:

	bool _isStopBody;

	// For pool manager management
	bool _isActive;

	// Current Action of the object (init -> nullptr)
	cocos2d::ActionInterval* _action;

	// Runs on active
	virtual void OnEnable();
	// Runs on in-active
	virtual void OnDisable();

	static b2Filter CreateB2Filter(
		uint16 categoryBits,
		uint16 maskBits = 0xFFFF,
		uint16 groupIndex = 0
	);

	static b2FixtureDef CreateFixtureDef(
		b2Filter filter,
		float32 density = 10,
		float32 friction = 1,
		float32 restitution = 0,
		bool isSensor = false
		);

	static b2BodyDef CreateBodyDef(
		b2Vec2 position,
		float32 angle = 0,
		bool isFixedRotation = false,
		bool isBullet = false,
		b2BodyType type = b2_staticBody,
		float32 gravityScale = 1.0f
	);

	void CreateB2Body(const b2Shape& shape,
		b2FixtureDef fixtureDef,
		b2BodyDef bodyDef
		);
	void CreateCircleBody(float32 radius,
		b2FixtureDef fixtureDef,
		b2BodyDef bodyDef
	);

	void CreateBoxBody(float32 hx,
		float32 hy,
		b2FixtureDef fixtureDef,
		b2BodyDef bodyDef
	);



	// called in GameObject::init()
	virtual void InitPhysics();
	// called in GameObject::init()
	virtual void InitSprites();
};

#endif // !__GAME_OBJECT_H__
