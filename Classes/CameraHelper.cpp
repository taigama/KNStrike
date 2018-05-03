#include "CameraHelper.h"

#include "World.h"
#include "ResourceManager.h"

USING_NS_CC;

#define CAMERA_BASE_OFFSET_Y 50.0f

CameraHelper::~CameraHelper()
{
}

CameraHelper::CameraHelper()
{

	m_camera = Camera::getDefaultCamera();

	//_area = ResourceManager::getInstance()->getArea();
	_visSize = Director::getInstance()->getVisibleSize();
	_origin = Director::getInstance()->getVisibleOrigin();

	m_offsetY = CAMERA_BASE_OFFSET_Y / Director::getInstance()->getContentScaleFactor();
}

Vec2 CameraHelper::ScreenToWorld(const Vec2& point)
{
	Vec2 result = m_camera->getPosition() + point;
	result.x -= _visSize.width / 2.0f;
	result.y -= _visSize.height / 2.0f;
	return result;
}

void CameraHelper::UpdatePosition(cocos2d::Vec2 newPosition)
{
	_pos = newPosition;
	//_pos.y += m_offsetY;// CAMERA_OFFSET_Y;

	/*if (m_camera)
	{*/
	// --- fix position by map-bounding ---

	//// if width of map > width of screen
	//if (_area.size.width > _visSize.width)
	//{
	//	// outside the bouding? move into bounding
	//	if (_pos.x < _area.getMinX() + _visSize.width / 2)
	//	{
	//		_pos.x = _area.getMinX() + _visSize.width / 2;
	//	}
	//	else if (_pos.x > _area.getMaxX() - _visSize.width / 2)
	//	{
	//		_pos.x = _area.getMaxX() - _visSize.width / 2;
	//	}
	//}
	//else // width of map < width of screen => fix 1 position x
	//{
	//	_pos.x = _area.getMinX() + _visSize.width / 2;
	//}

	//// if height of map > height of screen
	//if (_area.size.height > _visSize.height)
	//{
	//	// outside the bouding? move into bounding
	//	if (_pos.y < _area.getMinY() + _visSize.height / 2)
	//	{
	//		_pos.y = _area.getMinY() + _visSize.height / 2;
	//	}
	//	else if (_pos.y > _area.getMaxY() - _visSize.height / 2)
	//	{
	//		_pos.y = _area.getMaxY() - _visSize.height / 2;
	//	}
	//}
	//else // height of map < height of screen => fix 1 position y
	//{
	//	_pos.y = _area.getMinY() + _visSize.height / 2;
	//}

	// set camera position after fixed
	m_camera->setPosition(_pos);


	/*}
	else
	{
		m_camera = Camera::getDefaultCamera();

		_area = ResourceManager::getInstance()->getArea();
		_visSize = Director::getInstance()->getVisibleSize();
	}*/
}

void CameraHelper::MovePosition(cocos2d::Vec2 deltaPosition)
{
	_pos = m_camera->getPosition();
	_pos += deltaPosition;
	m_camera->setPosition(_pos);
}

//void CameraHelper::setMargin(float marginLength)
//{
//	//float scale_factor = ;
//	marginLength /= Director::getInstance()->getContentScaleFactor();
//
//	float center_x = _area.getMidX();
//	float center_y = _area.getMidY();
//
//	Size size = _area.size;
//	size.width -= marginLength * 2.0f;
//	size.height -= marginLength * 2.0f;
//
//	float min_x = center_x - size.width / 2.0f;
//	float min_y = center_y - size.height / 2.0f;
//
//	// new Rect
//	_area.setRect(min_x, min_y, size.width, size.height);
//}