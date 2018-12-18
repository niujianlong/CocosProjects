#ifndef _SPIRIT_PLAYER_
#define _SPIRIT_PLAYER_

#include "cocos2d.h"
#include "../Commen_ActionToDo.h"
#include "../Commen_Direction.h"
#include "../GameData/MainRoledata.h"
#include "../Commen/PublicShowUI.h"
#include "../Effects/EffectsCommen.h"



USING_NS_CC;

class SpiritsPlayer : public cocos2d::CCSprite 
{
public: 
	
	CCSprite* npc;
	CCSprite* yinzi;
	CCSprite* sp_liaotianbd;

	PublicShowUI* p_ui_name;
	
	CCArray *stringArray;
	CCAnimate* playdonghua;
	CCAnimate* playdonghua2;
	Commen_Direction move_dir;

	bool endflag;
	bool endflag2;
	bool thiszhujiao_flag;


	void Spirits_talkabout_hid();

	SpiritsPlayer(MainRoledata roledata,int zOrder,bool zhujiaoflag);
	~SpiritsPlayer(void);
	static CCAnimation* getNowAnt(MainRoledata roledata);
	CCAnimate* updateNowAnt(MainRoledata roledata);
	static CCAnimate* updateNowAnt_change(MainRoledata roledata,int RepeatNum);
	void updateNpcPoint(CCPoint newpoint);
	void moveTomap_dir(CCPoint newpoint);
	static void attckTomap_dir(CCPoint newpoint,CCSprite* npc,MainRoledata role_player);
	void moveTomap_move(int uestime,CCPoint newpoint,bool npcflag);
	//人物移动完成的回调
	void moveoverCallBack(void);
	//普通NPC移动完成的回调
	void moveoverCallBackforNpc(void);
	//根据点击坐标获得人物的朝向
	Commen_Direction getNowPointDir(CCPoint newpoint);
	static Commen_Direction getNowPointDir_change(CCPoint newpoint,CCSprite* npc);
	// 触摸点是否在精灵上
    bool isTouchInside(CCPoint thisPos);
	//移动方式
	void movemethod(int uestime,CCPoint newpoint);

private:
	//角色基本数据
	MainRoledata thisroledata;
	CCFiniteTimeAction *actall;
	CCActionInterval* act_moveto_zi;
	CCActionInterval* act_moveto_npc;
	CCActionInterval* act_moveto_yinzi;
	CCActionInterval* act_moveto_eff;
	CCActionInterval* act_moveto_eff_zhujiao;
	CCFiniteTimeAction *actbackfun; 
	int flag ;

private:
    CCRect rect();
    
 
};
#endif//_SPIRIT_PLAYER_
