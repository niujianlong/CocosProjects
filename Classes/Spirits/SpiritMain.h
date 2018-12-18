#ifndef _SPIRIT_MAIN_
#define _SPIRIT_MAIN_

#include "cocos2d.h"
#include "../Commen_ActionToDo.h"
#include "../Commen_Direction.h"
#include "../GameData/MainRoledata.h"
#include "../Commen/PublicShowUI.h"

USING_NS_CC;

class SpiritMain :public cocos2d::CCSprite
{
public: 
	PublicShowUI* p_ui;
	SpiritMain(CCLayer* layer,MainRoledata roledata,int zOrder);
	~SpiritMain(void);
	CCAnimation* getNowAnt(MainRoledata roledata);

};
#endif//_SPIRIT_MAIN_
