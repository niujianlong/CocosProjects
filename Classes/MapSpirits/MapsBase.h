#ifndef _MAPS_BASE_
#define _MAPS_BASE_

#include "cocos2d.h"
#include "../Commen_ActionToDo.h"
#include "../Commen_Direction.h"
#include "../GameData/MainRoledata.h"
#include "../Spirits/SpiritsPlayer.h"
#include "../GameData/GetNPCData.h"
#include "../Commen/FDPixelSprite.h"
#include "../Effects/EffectsCommen.h";
#include "../ImagePaths.h"
#include "../StoryTips/TipsForStory.h"



USING_NS_CC;

class MapsBase : public cocos2d::CCSprite
{
public: 

	MapsBase(CCLayer* layer,CCString mapsurl,int zOrder,CCPoint cp);
	~MapsBase(void);

	CCSprite* nowmap;

	bool moveMapto(CCPoint cp,FDPixelSprite* mainmap_Touch);


	//地图NPC列表
	SpiritsPlayer* npc_taiyizhengren ;
	SpiritsPlayer* npc_taishanglaojun ;
	SpiritsPlayer* npc_chijiaodaxian ;
	SpiritsPlayer* npc_qingxunzhenjun ;

	void playerstroy_part1_show(float times);
	void playerstroy_part1_show2(float times);

private:
	//基本数据
	float lastmove_x,lastmove_y;
	CCActionInterval* act_moveto_maps;
	CCActionInterval* act_moveto_maps_touch; 
	CCFiniteTimeAction *actall;
	GetNPCData* basedatas ; 
	SpiritsPlayer* role_main;

	//移动时间
	float movetime; 

	//特效
	EffectsCommen* eff1;//神台特效
	EffectsCommen* eff2;//神台特效
	EffectsCommen* eff_yun1;//云雾效果
	EffectsCommen* eff_yun2;
	EffectsCommen* eff_yun3;
	EffectsCommen* eff_yun4;

};
#endif//_MAPS_BASE_
