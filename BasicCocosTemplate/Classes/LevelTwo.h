#ifndef __LEVELTWO_H__
#define __LEVELTWO_H__

#include "cocos2d.h"

class LevelTwo : public cocos2d::Layer
{
public:

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// update the game scene
	void update(float) override;


	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(LevelTwo);

	void Pause(Ref *pSender);


private:



};

#endif// __LEVELTWO_H__

