#include "LevelSelect.h"
#include "LevelOne.h"
#include "LevelTwo.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* LevelSelect::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LevelSelect::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LevelSelect::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();



	auto backGround = Sprite::create("background.png");
	backGround->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backGround);

	// create the main menu items
	auto menu_item_1 = MenuItemFont::create("Level One", CC_CALLBACK_1(LevelSelect::LevelOne, this)); // start the game scene
	auto menu_item_2 = MenuItemFont::create("Level Two", CC_CALLBACK_1(LevelSelect::LevelTwo, this)); // start the game scene
	auto menu_item_3 = MenuItemFont::create("Back to Main Menu", CC_CALLBACK_1(LevelSelect::MainMenu, this)); // start the game scene
	

	// position the menu buttons on screen
	menu_item_1->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 1.2) ));
	menu_item_2->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 1.6) ));
	menu_item_3->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 2.4) ));

	// create menu and add menu items
	auto *menu = Menu::create(menu_item_1, menu_item_2, menu_item_3, NULL);

	// position the main menu
	menu->setPosition(Point(0, 0));

	// add the menu to the scene
	this->addChild(menu);

	pressed = false;

	return true;
}

/*
Level One button creates a new level (Level One).

@param cocos2d::Ref *pSender pointer used by the engine
*/
void LevelSelect::LevelOne(cocos2d::Ref *pSender)
{
	CCLOG("Level One");

	auto scene = LevelOne::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
}

/*
Level One button creates a new level (Level Two).

@param cocos2d::Ref *pSender pointer used by the engine
*/
void LevelSelect::LevelTwo(cocos2d::Ref *pSender)
{
	CCLOG("Level Two");

	auto scene = LevelTwo::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
}

/*
Play button creates a new game scene and replaces the main menu.

@param cocos2d::Ref *pSender pointer used by the engine
*/
void LevelSelect::MainMenu(cocos2d::Ref *pSender)
{
	CCLOG("Main Menu");

	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
}
