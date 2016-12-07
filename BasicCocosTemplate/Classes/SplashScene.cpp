#include "SplashScene.h"
#include "Definitions.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* Splash::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Splash::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Splash::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	this->scheduleOnce(schedule_selector(Splash::goToMainMenuScene), DISPLY_TIME_SPLASH_SCENCE);

	auto back = Sprite::create("background.png");
	back->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(back);

	auto backgroundSprite = Sprite::create("splash-logo.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

}

void Splash::goToMainMenuScene(float dt)
{
	auto scene = MainMenu::createScene();

	Director::getInstance()->replaceScene( TransitionFade::create(TRANSITION_TIME, scene));
}