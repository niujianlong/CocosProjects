#ifndef _EFFECTS_COMMEN_
#define _EFFECTS_COMMEN_
#include "cocos2d.h"

USING_NS_CC;
class EffectsCommen:public cocos2d::CCSprite
{
public:

	CCSprite* effects_main;
	CCActionInterval* act_moveto;

	EffectsCommen(CCPoint basepoint,CCString* imgurl,float actiontime,float maxnum,int showtype,int zOrder);
	~EffectsCommen(void);
	EffectsCommen(CCString* imgurl0,CCString* imgurl,int num1, CCString* imgurl2,int num2,CCString* imgurl3,int num3,CCPoint newpoint);
	


	//执行的最后动作
	CCFiniteTimeAction *actall; 

	//人物移动完成的回调
	void moveoverCallBack_setvisible(void);
};

#endif //_EFFECTS_COMMEN_