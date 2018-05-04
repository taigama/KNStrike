#ifndef __MY_PHYSICS_WORLD_H__
#define __MY_PHYSICS_WORLD_H__
 
#include "cocos2d.h"
#include "SingleTon.h"
#include "Box2D/Box2D.h"

class MyPhysicsWorld : public cocos2d::Node, public SingleInstance<MyPhysicsWorld>
{
private:
	b2World* m_world;

	



public:
	CREATE_FUNC(MyPhysicsWorld);
	bool init() override;

	void update(float dt) override;

	b2World* GetPhysics() const
	{
		return m_world;
	}

	// ---------------------------------
	// http://www.box2d.org/forum/viewtopic.php?t=4396
	// Position iterations improve overlap resolution.
	int m_positionIteration, m_velocityIteration;

	//CC_PROPERTY(int, _positionIteration, PositionIterations);
	//// Velocity iterations improve stability. 
	//CC_PROPERTY(int, _velocityIteration, VelocityIteration);
};
#endif // __PHYSICS_WORLD_H__
