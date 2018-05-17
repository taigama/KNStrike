#include "MainHUD.h"
#include "CameraHelper.h"

//#include "ui/CocosGUI.h"
USING_NS_CC;

MainHUD::MainHUD()
{
	
}

MainHUD::~MainHUD()
{
	
}

bool MainHUD::init()
{
	if(!HUD::init())
	{
		return false;
	}

	/*Node* a = Scene::create();
	a->retain();*/
	/*ui::Button* btn = ui::Button::create("CloseNormal.png", "CloseSelected.png");
	btn->addTouchEventListener([&](Ref*, ui::Widget::TouchEventType type)
	{
		
	});*/

	MenuItemImage* btn = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(MainHUD::OnClickHahaha, this));

	auto size = CameraHelper::GetInstance()->getVisibleSize();
	Vec2 pos = CameraHelper::GetInstance()->getPosition() + CameraHelper::GetInstance()->getOrigin();
	pos.x += size.width / 2.0f;
	pos.y += size.height / 2.0f;
	btn->setPosition(pos);
	Menu* menu = Menu::create(btn, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	return true;
}

void MainHUD::OnClickHahaha(cocos2d::Ref* sender)
{
	MessageBox("Hahaha!", "Congrats");
}
