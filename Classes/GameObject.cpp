#include "GameObject.h"
#include "MyPhysicsWorld.h"

USING_NS_CC;

GameObject::~GameObject()
{
	if(_body)
	{
		MyPhysicsWorld::GetInstance()->GetPhysics()->DestroyBody(_body);
	}
}

Rect GameObject::getBoundingBox() const
{ 
    if (_sprite)
        return getSprite()->getBoundingBox();
    return Rect();
}

bool GameObject::init()
{
	if (!Node::init())
		return false;

	// yeu cau cocos auto goi ham update
	//
	// Instructs Cocos2d to call "update()" function every frame
	this->scheduleUpdate();

	// ================ init start

	_type = GameObject::NONE;

	_isActive = true;

	_body = nullptr;
	_isStopBody = false;
	_sprite = nullptr;
	_action = nullptr;

	InitSprites();
	InitPhysics();

	return true;
}

void GameObject::update(float delta) {}


b2Filter GameObject::CreateB2Filter(
	uint16 categoryBits,
	uint16 maskBits,
	uint16 groupIndex)
{
	b2Filter b2filter;
	b2filter.categoryBits = categoryBits;
	b2filter.maskBits = maskBits;
	b2filter.groupIndex = groupIndex;
	return b2filter;
}

b2FixtureDef GameObject::CreateFixtureDef(
	b2Filter filter,
	float32 density,
	float32 friction,
	float32 restitution,
	bool isSensor)
{
	b2FixtureDef b2fixtureDef;
	b2fixtureDef.filter = filter;
	b2fixtureDef.density = density;
	b2fixtureDef.friction = friction;
	b2fixtureDef.restitution = restitution;
	b2fixtureDef.isSensor = isSensor;
	return b2fixtureDef;
}

b2BodyDef GameObject::CreateBodyDef(
	b2Vec2 position,
	float32 angle,
	bool isFixedRotation,
	bool isBullet,
	b2BodyType type,
	float32 gravityScale
)
{
	b2BodyDef b2bodyDef;
	b2bodyDef.position = position;
	b2bodyDef.angle = angle;
	b2bodyDef.fixedRotation = isFixedRotation;
	b2bodyDef.bullet = isBullet;
	b2bodyDef.type = type;
	b2bodyDef.gravityScale = gravityScale;
	return b2bodyDef;
}

void GameObject::CreateB2Body(
	const b2Shape& shape,
	b2FixtureDef fixtureDef,
	b2BodyDef bodyDef
)
{
	fixtureDef.shape = &shape;
	bodyDef.userData = this;
	_body = MyPhysicsWorld::GetInstance()->GetPhysics()->CreateBody(&bodyDef);
	_body->CreateFixture(&fixtureDef);
}

void GameObject::CreateCircleBody(
	float32 radius,
	b2FixtureDef fixtureDef,
	b2BodyDef bodyDef
)
{
	b2CircleShape shape;
	shape.m_radius = radius;
	fixtureDef.shape = &shape;
	bodyDef.userData = this;
	_body = MyPhysicsWorld::GetInstance()->GetPhysics()->CreateBody(&bodyDef);
	_body->CreateFixture(&fixtureDef);
}

void GameObject::CreateBoxBody(float32 hx, float32 hy, b2FixtureDef fixtureDef, b2BodyDef bodyDef)
{
	b2PolygonShape shape;
	shape.SetAsBox(hx, hy);
	fixtureDef.shape = &shape;
	bodyDef.userData = this;
	_body = MyPhysicsWorld::GetInstance()->GetPhysics()->CreateBody(&bodyDef);
	_body->CreateFixture(&fixtureDef);
}


void GameObject::InitPhysics() {}
void GameObject::InitSprites() {}

void GameObject::StopBody()
{
	if (!_body)
		return;

	if(_isStopBody)
	{
		return;
	}

	_isStopBody = true;
	_body->SetActive(false);
}

void GameObject::ResumeBody()
{
	if (!_body)
		return;

	if (!_isStopBody)
	{
		return;
	}

	_isStopBody = false;
	_body->SetActive(true);
}

bool GameObject::IsActive() const { return _isActive; }
void GameObject::OnEnable()
{
	// ################ ADD - TO - PARENT

	if(!_isStopBody)
	{
		ResumeBody();
	}
}
void GameObject::OnDisable()
{
	// dem toi 1 noi xa xoi
	//
	// Moves the current object outside of the visible windows
	
	//this->setVisible(false); // ??

	// no need to do this
	//this->setPosition(Vec2(-9999, -9999));

	StopBody();
	this->removeFromParent();

}


void GameObject::SetActive(bool active)
{
	// neu thay doi trang thai active -> goi ham onEnable hoac onDisable
	//
	// If active state changes -> calls onEnable() if active == true; Otherwise, calls onDisable()
	if (_isActive != active)
	{
		if (active)
		{
			OnEnable();
		}
		else
		{
			OnDisable();
		}
		_isActive = active;
	}
}
