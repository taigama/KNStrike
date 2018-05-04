#ifndef __CAMERA_HELPER_H__
#define __CAMERA_HELPER_H__

#include "cocos2d.h"
#include "SingleTon.h"


// should delete on destructor of the scene
// automatic update position of camera and provide Screen info for shorter get
class CameraHelper : public SingleTon<CameraHelper>
{
public:


	// player will call this
	void UpdatePosition(cocos2d::Vec2);
	// or call this
	void MovePosition(cocos2d::Vec2);


	cocos2d::Vec2 ScreenToWorld(const cocos2d::Vec2&);

	//void setMargin(float marginLength);

	// Rect of the map
	//CC_SYNTHESIZE_READONLY(cocos2d::Rect, _area, Area);

	// visible size of the screen
	CC_SYNTHESIZE_READONLY(cocos2d::Size, _visSize, VisibleSize);

	// origin of the view (bottom-left corner)
	CC_SYNTHESIZE_READONLY(cocos2d::Size, _origin, Origin);

	// current camera position info
	CC_SYNTHESIZE_READONLY(cocos2d::Vec2, _pos, Position);


	CameraHelper();
	~CameraHelper();
private:

	cocos2d::Camera* m_camera;

	float m_offsetY;
};

#endif // !__CAMERA_HELPER_H__
