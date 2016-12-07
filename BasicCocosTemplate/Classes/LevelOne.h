#ifndef __LEVELONE_H__
#define __LEVELONE_H__

#include "cocos2d.h"

class LevelOne : public cocos2d::Layer
{
public:

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// update the game scene
	void update(float) override;

	// implement the "static create()" method manually
	CREATE_FUNC(LevelOne);

	void Pause(Ref *pSender);

private:

};

#endif // __LEVELONE_H__
