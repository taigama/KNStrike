//#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"
//#include "DebugDraw.h"
//#include "CameraHelper.h"
//
//USING_NS_CC;
//#define SCALE_RATIO 32.0
//
//
//HelloWorld* HelloWorld::_instance = nullptr;
//Scene* HelloWorld::createScene()
//{	
//	if (!_instance) {
//		HelloWorld::create();
//	}
//	else {
//		MessageBox("The instance has already exist!", "WORLD ERROR");
//	}
//
//    return _instance;
//}
//
//HelloWorld* HelloWorld::getInstance() {
//	return _instance;
//}
//
//HelloWorld* HelloWorld::create()
//{
//	 _instance = new(std::nothrow) HelloWorld();
//
//	if (_instance && _instance->init())
//	{
//		_instance->autorelease();
//
//		return _instance;
//	}
//	else
//	{
//		delete _instance;
//		_instance = nullptr;
//		return nullptr;
//	}
//}
//
//// Print useful error message instead of segfaulting when files are not there.
//static void problemLoading(const char* filename)
//{
//    printf("Error while loading: %s\n", filename);
//    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
//}
//
//// on "init" you need to initialize your instance
//bool HelloWorld::init()
//{
//    //////////////////////////////
//    // 1. super init first
//    if ( !Scene::init() )
//    {
//        return false;
//    }
//
//
//    auto visibleSize = Director::getInstance()->getVisibleSize();
//    Vec2 origin = Director::getInstance()->getVisibleOrigin();
//
//    /////////////////////////////
//    // 2. add a menu item with "X" image, which is clicked to quit the program
//    //    you may modify it.
//
//    // add a "close" icon to exit the progress. it's an autorelease object
//    auto closeItem = MenuItemImage::create(
//                                           "CloseNormal.png",
//                                           "CloseSelected.png",
//                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
//
//    if (closeItem == nullptr ||
//        closeItem->getContentSize().width <= 0 ||
//        closeItem->getContentSize().height <= 0)
//    {
//        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
//    }
//    else
//    {
//        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
//        float y = origin.y + closeItem->getContentSize().height/2;
//        closeItem->setPosition(Vec2(x,y));
//    }
//
//    // create menu, it's an autorelease object
//    auto menu = Menu::create(closeItem, NULL);
//    menu->setPosition(Vec2::ZERO);
//    this->addChild(menu, 1);
//
//    /////////////////////////////
//    // 3. add your codes below...
//
//    // add a label shows "Hello World"
//    // create and initialize a label
//
//    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
//    if (label == nullptr)
//    {
//        problemLoading("'fonts/Marker Felt.ttf'");
//    }
//    else
//    {
//        // position the label on the center of the screen
//        label->setPosition(Vec2(origin.x + visibleSize.width/2,
//                                origin.y + visibleSize.height - label->getContentSize().height));
//
//        // add the label as a child to this layer
//        this->addChild(label, 1);
//    }
//
//    
//
//	b2Vec2 gravity = b2Vec2(0.0f, -55.0f); // Vector gia tốc ( dấu - là chỉ hướng xuống, vì trục y hướng lên trên)
//
//	world = new b2World(gravity); // Tạo world với vector gia tốc
//
//								  // Tạo 1 Sprite quả bóng
//	this->ball = Sprite::create("ball.png");
//
//	// Đặt vị trí giữa màn hình
//	this->ball->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
//
//	// Đoạn này quan trọng nhất để app body trong Box2D
//
//	//---------------------KHUNG VAT LY BOX2D--------------------
//	b2CircleShape bodyShape;
//	bodyShape.m_radius = 45 / SCALE_RATIO; // Bán kính của khối body
//
//
//	b2FixtureDef fixtureDef;				
//	//fixtureDef
//	fixtureDef.density = 10; // Trọng lượng
//	fixtureDef.friction = 1; // Ma sát
//	fixtureDef.restitution = 0.2; // Đàn hồi
//	fixtureDef.shape = &bodyShape; // Trỏ vào bodyShape
//	
//	
//	b2BodyDef bodyDef;
//	//bodyDef
//	bodyDef.bullet = true;
//	bodyDef.type = b2_dynamicBody; // Va chạm động
//	bodyDef.active = true;
//	bodyDef.userData = ball; // gắn với Sprite ball
//
//							 // Đặt vị trí, và nhớ chuyển đổi đơn vị
//	bodyDef.position.Set(ball->getPosition().x / SCALE_RATIO, ball->getPosition().y / SCALE_RATIO);
//
//	//ballBody
//	ballBody = world->CreateBody(&bodyDef); // Tạo Body
//	ballBody->CreateFixture(&fixtureDef); // Tạo các thuộc tính tĩnh
//	ballBody->SetGravityScale(10); // Đặt tỷ lệ gia tốc, càng cao rơi càng nhanh
//
//								   //-----------------------------------------------------------
//
//								   // Đặt quả bóng vào layer của Scene
//	this->addChild(ball, 0);
//
//	
//
//	this->addChild(DebugDraw::create(), 1);
//
//	_showB2Debug = true;
//
//	addWall(18, 0.01f, 800, 100);
//
//
//	ContactListener* myContactListener = new ContactListener();
//	world->SetContactListener(myContactListener);
//
//
//
//	toucher = EventListenerTouchOneByOne::create();
//	toucher->setSwallowTouches(true);
//	toucher->onTouchBegan = [&](Touch* touch, Event* event)
//	{
//		auto posTouch = CameraHelper::GetInstance()->ScreenToWorld(touch->getLocation());
//		ballBody->SetTransform(b2Vec2(posTouch.x / SCALE_RATIO, posTouch.y / SCALE_RATIO), 0);
//		barBody->SetActive(true);
//		//ballBody->SetActive(false);
//		return true;// false won't swall touch, will swall if return true
//	};
//	_eventDispatcher->addEventListenerWithSceneGraphPriority(toucher, this);
//
//
//
//	toucherBall = EventListenerTouchOneByOne::create();
//	toucherBall->setSwallowTouches(true);
//	toucherBall->onTouchBegan = [&](Touch* touch, Event* event)
//	{
//		auto posTouch = CameraHelper::GetInstance()->ScreenToWorld(touch->getLocation());
//		if (ball->getBoundingBox().containsPoint(posTouch))
//		{
//			ballBody->SetLinearVelocity(b2Vec2(0, 11));
//			barBody->SetActive(false);
//			//ballBody->SetActive(true);
//			return true;
//		}		
//		return false;// false won't swall touch, will swall if return true
//	};
//	_eventDispatcher->addEventListenerWithSceneGraphPriority(toucherBall, ball);
//
//	scheduleOnce(CC_SCHEDULE_SELECTOR(HelloWorld::delayLoad), 0);
//
//    return true;
//}
//
//void HelloWorld::delayLoad(float)
//{
//	m_vecMove.setPoint(0, 0);
//	EventListenerKeyboard* keyListener = EventListenerKeyboard::create();
//	keyListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyEnter, this);
//	_eventDispatcher->addEventListenerWithFixedPriority(keyListener, 1);
//	_camera = CameraHelper::getInstance();
//
//	scheduleUpdate(); // Update lại scene theo thời gian, phải có cái này nhé
//}
//
//void HelloWorld::onKeyEnter(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* e)
//{
//	switch (key) {
//	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
//	case EventKeyboard::KeyCode::KEY_A:
//		m_vecMove.x = -10;
//		break;
//	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
//	case EventKeyboard::KeyCode::KEY_D:
//		m_vecMove.x = 10;
//		break;
//	case EventKeyboard::KeyCode::KEY_UP_ARROW:
//	case EventKeyboard::KeyCode::KEY_W:
//		m_vecMove.y = 10;
//		break;
//	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
//	case EventKeyboard::KeyCode::KEY_S:
//		m_vecMove.y = -10;
//		break;
//	}
//}
//
//void HelloWorld::addWall(float w, float h, float px, float py) {
//	b2PolygonShape* boxShape = new b2PolygonShape();
//	boxShape->SetAsBox(w, h);
//	b2FixtureDef* boxFixture = new b2FixtureDef();
//	boxFixture->density = 10;
//	boxFixture->friction = 1.0;
//	boxFixture->restitution = 0.5;
//	boxFixture->shape = boxShape;
//	b2BodyDef* boxDef = new b2BodyDef();
//
//	auto bar = new Node();
//	bar->init();
//	bar->setPosition(px, py);
//	boxDef->type = b2_kinematicBody;
//	boxDef->userData = bar;
//	boxDef->position.Set(px/32.0f, py/32.0f);
//
//	barBody = world->CreateBody(boxDef);
//	barBody->CreateFixture(boxFixture);
//	this->addChild(bar, 1, "AAA");
//}
//
//void HelloWorld::update(float dt) {
//	int positionIterations = 3;  // step vận tốc
//	int velocityIterations = 8; // step vị trí
//	// http://www.box2d.org/forum/viewtopic.php?t=4396
//
//	deltaTime = dt; // Bước thời gian
//
//					// Mô phỏng chuyển động vật lý theo thời gian, hãy nghiên cứu ở đây http://www.box2d.org/manual.html và đây http://www.iforce2d.net/b2dtut/worlds\
//
//					// Có thể hiểu thế này, mỗi Step xảy ra trong dt giây , dt này trong file AppDelegate.cpp định nghĩa = dòng lệnh director->setAnimationInterval(1.0 / 60); Bạn thử thay 1/60 = 1/1 xem, rơi cực chậm theo từng giây
//
//	world->Step(dt, velocityIterations, positionIterations);
//
//	// Duyệt tất cả body của world
//	for (b2Body *body = world->GetBodyList(); body != NULL; body = body->GetNext())
//		// Xét những body có gắn vào Sprite
//		if (body->GetUserData())
//		{
//
//			// Trả về sprite quả bóng ( có mỗi sprite trong bài này )
//			Sprite *sprite = (Sprite *)body->GetUserData();
//			// Đặt lại vị trí của Sprite này theo vị trí của body ( body sẽ bị rơi dần theo time), nhớ nhân RATIO để chuyển sang tọa độ pixel
//			sprite->setPosition(Point(body->GetPosition().x * SCALE_RATIO, body->GetPosition().y * SCALE_RATIO));
//			// Đặt khả năng quay tròn
//			sprite->setRotation(-1 * CC_RADIANS_TO_DEGREES(body->GetAngle()));
//
//		}
//	world->ClearForces(); // Xóa mọi áp đặt cho Body
//
//	_camera->MovePosition(m_vecMove);
//	m_vecMove.setPoint(0, 0);
//}
//
//void HelloWorld::menuCloseCallback(Ref* pSender)
//{
//    //Close the cocos2d-x game scene and quit the application
//    Director::getInstance()->end();
//
//    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//
//    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
//
//    //EventCustom customEndEvent("game_scene_close_event");
//    //_eventDispatcher->dispatchEvent(&customEndEvent);
//
//
//}
