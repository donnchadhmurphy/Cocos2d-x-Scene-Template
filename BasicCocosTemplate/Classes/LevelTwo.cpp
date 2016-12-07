#include "LevelTwo.h"
#include "PauseScene.h"

USING_NS_CC;

Scene* LevelTwo::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); // draw debug lines around objects in the world

	// 'layer' is an autorelease object
	auto layer = LevelTwo::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LevelTwo::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// pause button
	auto menu_item_pause = MenuItemImage::create("pause.png", "pause-push.png", CC_CALLBACK_1(LevelTwo::Pause, this));
	menu_item_pause->setPosition(Point(visibleSize.width - 50, visibleSize.height - 50));

	//// create menu, add menu items and add to the game scene
	auto *menu = Menu::create(menu_item_pause, NULL);
	menu->setPosition(Point(0, 0));
	this->addChild(menu);

	auto label = Label::create("Level Two", "Helvetica", 18);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 10);

	// call the schedule update in order to run this layers update function
	this->scheduleUpdate();

	return true;
}


/*
	You can add level code here or game logic.
*/
void LevelTwo::update(float delta)
{

}












































/*
Pause button creates a new pause scene and pushes it over the game scene

@param cocos2d::Ref *pSender pointer used by the engine
*/
void LevelTwo::Pause(cocos2d::Ref *pSender)
{
	CCLOG("Pause");
	auto scene = PauseScene::createScene();
	Director::getInstance()->pushScene(TransitionFade::create(1, scene));

}

/*
EndGame button creates a new game game scene and replaces the game scene

@param cocos2d::Ref *pSender pointer used by the engine
*/
//void GameScene::EndGame(cocos2d::Ref *pSender)
//{
//	CCLOG("End Game");
//	auto scene = EndScene::createScene();
//	Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
//}

void LevelTwo::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}