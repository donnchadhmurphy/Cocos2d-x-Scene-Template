#include "GameScene.h"
#include "MainMenuScene.h"
#include "PauseScene.h"
#include "Definitions.h"
#include "AppDelegate.h"

USING_NS_CC;

//int score = 0;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); // draw debug lines around objects in the world
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
	
    // add layer as a child to scene
    scene->addChild(layer);
		
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	

	// pause button
	auto menu_item_pause = MenuItemImage::create("pause.png", "pause02.png", CC_CALLBACK_1(GameScene::Pause, this));
	menu_item_pause->setPosition(Point(visibleSize.width - 50, visibleSize.height - 50));

	//// end game button
	//auto menu_item_endScene = MenuItemImage::create("cancel20.png", "cancel20.png", CC_CALLBACK_1(GameScene::EndGame, this));
	//menu_item_endScene->setPosition(Point(visibleSize.width - 50, 50));

	//// create menu, add menu items and add to the game scene
	auto *menu = Menu::create(menu_item_pause, NULL);	
	menu->setPosition(Point(0, 0));	
	this->addChild(menu);
	
	// call the schedule update in order to run this layers update function
	this->scheduleUpdate();


    return true;
}



void GameScene::update(float delta)
{	
	
}












































/*
	Pause button creates a new pause scene and pushes it over the game scene

	@param cocos2d::Ref *pSender pointer used by the engine
*/
void GameScene::Pause(cocos2d::Ref *pSender)
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

void GameScene::menuCloseCallback(Ref* pSender)
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