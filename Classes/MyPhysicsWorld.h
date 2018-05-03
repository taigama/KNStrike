#ifndef __MY_PHYSICS_WORLD_H__
#define __MY_PHYSICS_WORLD_H__
 
#include "cocos2d.h"
#include "SingleTon.h"
#include "Box2D/Box2D.h"

#define GRAVITY -10

class MyPhysicsWorld : public cocos2d::Node, public SingleInstance<MyPhysicsWorld>
{
private:
	b2World* m_world;

	// ---------------------------------
	// http://www.box2d.org/forum/viewtopic.php?t=4396
	// Position iterations improve overlap resolution.
	CC_PROPERTY(int, _positionIteration = 3, PositionIterations);
	// Velocity iterations improve stability. 
	CC_PROPERTY(int, _velocityIteration = 8, VelocityIteration);



public:
	CREATE_FUNC(MyPhysicsWorld);
	bool init() override;

	void update(float dt) override;

	b2World* GetPhysics() const
	{
		return m_world;
	}
};
#endif // __PHYSICS_WORLD_H__
