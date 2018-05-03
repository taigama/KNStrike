#include "DebugDraw.h"
#include "MyPhysicsWorld.h"
#include "GlobalSetting.h"

USING_NS_CC;


bool DebugDraw::init()
{
	if (!Layer::init())
	{
		return false;
	}
	// set up box2d ratio and debug flags
	float32 ratio = 32;// LIKE THE HELLO WORLD SCENE
	m_debugDraw = new GLESDebugDraw(ratio);
	m_world = MyPhysicsWorld::GetInstance()->GetPhysics();
	m_world->SetDebugDraw(m_debugDraw);
	uint32 flags = 0;
	flags += b2Draw::e_shapeBit | b2Draw::e_jointBit;
	//	flags += b2Draw::e_jointBit;
	//	flags += b2Draw::e_centerOfMassBit;
	//  flags += b2Draw::e_aabbBit;
	//	flags += b2Draw::e_pairBit;
	m_debugDraw->SetFlags(flags);

	return true;
}

void DebugDraw::draw(Renderer* renderer, const Mat4& transform, uint32_t flags)
{
#ifdef ENABLE_DEBUG_DRAW
	cocos2d::Layer::draw(renderer, transform, flags);


	GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION);
	Director::getInstance()->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
	// Translate the debug draw so it matches our visible world...
	/*auto p = Utils::screenPointFromPoint(Globals::getVisibleWorldLeftBottomInMeters());
	kmGLTranslatef(-p.x, -p.y, 0);*/

	m_world->DrawDebugData();

	Director::getInstance()->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);

#endif
}


DebugDraw::DebugDraw()
{

}

DebugDraw::~DebugDraw()
{

}