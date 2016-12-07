#include "LevelOne.h"
#include "PauseScene.h"

USING_NS_CC;

Scene* LevelOne::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	
	// 'layer' is an autorelease object
	auto layer = LevelOne::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LevelOne::init()
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
	auto menu_item_pause = MenuItemImage::create("pause.png", "pause02.png", CC_CALLBACK_1(LevelOne::Pause, this));
	menu_item_pause->setPosition(Point(visibleSize.width - 50, visibleSize.height - 50));

	//// create menu, add menu items and add to the game scene
	auto *menu = Menu::create(menu_item_pause, NULL);
	menu->setPosition(Point(0, 0));
	this->addChild(menu);

	auto label = Label::create("Level One", "Helvetica", 18);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 10);

	// call the schedule update in order to run this layers update function
	this->scheduleUpdate();


	return true;
}

/*
	Level One update function. You can add game loop/logic here.
*/
void LevelOne::update(float delta)
{

}

/*
Pause button creates a new pause scene and pushes it over the game scene

@param cocos2d::Ref *pSender pointer used by the engine
*/
void LevelOne::Pause(cocos2d::Ref *pSender)
{
	CCLOG("Pause");
	auto scene = PauseScene::createScene();
	Director::getInstance()->pushScene(TransitionFade::create(1, scene));

}
