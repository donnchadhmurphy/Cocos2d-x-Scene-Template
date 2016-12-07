#include "MainMenuScene.h"
#include "LevelSelect.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();
	
    // add layer as a child to scene
    scene->addChild(layer);
	
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
		
	auto backGround =  Sprite::create("background.png");
	backGround->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backGround);

	// create the main menu items
	auto menu_item_1 = MenuItemFont::create("Play", CC_CALLBACK_1(MainMenu::Play, this)); // start the game scene
	auto menu_item_2 = MenuItemFont::create("Quit", CC_CALLBACK_1(MainMenu::menuCloseCallback, this)); // start the game scene

	
	// position the menu buttons on screen
	menu_item_1->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 1.2) ));
	menu_item_2->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 1.6)));


	// create menu and add menu items
	auto *menu = Menu::create(menu_item_1, menu_item_2, NULL);

	// position the main menu
	menu->setPosition(Point(0, 0));

	// add the menu to the scene
	this->addChild(menu);

	pressed = false;

	
    return true;
}

/* 
	Play button creates a new game scene and replaces the main menu.

	@param cocos2d::Ref *pSender pointer used by the engine
*/
void MainMenu::Play(cocos2d::Ref *pSender)
{
	CCLOG("Play");
	auto scene = LevelSelect::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
}

	
void MainMenu::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
	
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
