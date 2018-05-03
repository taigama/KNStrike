#include "MyPhysicsWorld.h"
#include "GlobalSetting.h"
USING_NS_CC;

bool MyPhysicsWorld::init()
{
	if (!Node::init())
		return  false;

	scheduleUpdate();
	m_world = new b2World(b2Vec2(0.0f, GRAVITY));
	return true;
}

void MyPhysicsWorld::update(float dt)
{


					// Mô phỏng chuyển động vật lý theo thời gian, hãy nghiên cứu ở đây http://www.box2d.org/manual.html và đây http://www.iforce2d.net/b2dtut/worlds\

					// Có thể hiểu thế này, mỗi Step xảy ra trong dt giây , dt này trong file AppDelegate.cpp định nghĩa = dòng lệnh director->setAnimationInterval(1.0 / 60); Bạn thử thay 1/60 = 1/1 xem, rơi cực chậm theo từng giây

	m_world->Step(dt, _velocityIteration, _positionIteration);

	// Duyệt tất cả body của world
	for (b2Body *body = m_world->GetBodyList(); body != NULL; body = body->GetNext())
		// Xét những body có gắn vào Sprite
		if (body->GetUserData())
		{

			// Trả về sprite quả bóng ( có mỗi sprite trong bài này )
			Sprite *sprite = (Sprite *)body->GetUserData();
			// Đặt lại vị trí của Sprite này theo vị trí của body ( body sẽ bị rơi dần theo time), nhớ nhân RATIO để chuyển sang tọa độ pixel
			sprite->setPosition(Point(body->GetPosition().x * Global::SCALE_PHYSICS, body->GetPosition().y * Global::SCALE_PHYSICS));
			// Đặt khả năng quay tròn
			sprite->setRotation(-1 * CC_RADIANS_TO_DEGREES(body->GetAngle()));

		}
	m_world->ClearForces(); // Xóa mọi áp đặt cho Body
}
