#ifndef __DEBUG_DRAW_H__
#define __DEBUG_DRAW_H__

#include "cocos2d.h"
#include "GLES-Render.h"
#include "Box2D\Box2D.h"

class DebugDraw : public cocos2d::Layer
{
private:
	GLESDebugDraw * m_debugDraw;
	b2World* m_world;

public:
	CREATE_FUNC(DebugDraw);

	virtual bool init();

	DebugDraw();

	~DebugDraw();

	void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags) override;

};


#endif //__DEBUG_DRAW_H__