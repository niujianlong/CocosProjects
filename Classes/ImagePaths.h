#ifndef _PUBLIC_IMAGE_PATH_
#define _PUBLIC_IMAGE_PATH_
#include "cocos2d.h"  
USING_NS_CC;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	static CCString* strpart1 = CCString::create("part1.txt");
	static CCString* strpart2 = CCString::create("part2.txt");
	
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	static CCString* strpart1 = CCString::create("stroytxt/part1.txt");
	static CCString* strpart2 = CCString::create("stroytxt/part2.txt");

#endif

//公共UI图片
//登录界面
static const char p_loginallbd[] = "login_allbd.jpg";
static const char p_logo[] = "logo.png";
static const char p_login_bd1[] = "login_bd1.png";
static const char p_login_newrole[] = "login_newrole.png";
static const char p_login_start[] = "login_start.png";
//人物选择界面
static const char p_select_bd[] = "selec_roletbd.jpg";
static const char p_select_nv[] = "nv_zhu.png";
static const char p_select_nan[] = "nan_zhu.png";
static const char p_select_nv0[] = "nv_zhu0.png";
static const char p_select_nan0[] = "nan_zhu0.png";


//聊天按钮
static const char p_toscene[] = "js_chatbd.png";
static const char p_toscene0[] = "js_chatbd0.png";
//头像部分
static const char p_headbd[] = "headbd.png";
static const char p_head_xiaoxiao[] = "nv_head_xiaoxiao.png";
//经验条
static const char p_expbd[] = "expbd.png";
//摇杆
static const char p_yaoganbd[] = "yaoganbd.png";
//技能按键
static const char p_skillbarbd[] = "skillsbd.png";

//女角色技能
static const char p_skill_nv0[] = "nv_xx_skill0.png";
static const char p_skill_nv1[] = "nv_xx_skill1.png";
static const char p_skill_nv2[] = "nv_xx_skill2.png";
static const char p_skill_nv3[] = "nv_xx_skill3.png";

//人物脚下影子
static const char p_yinzi[] = "yinzi.png";
//怪物头上血条
static const char p_bloodline[] = "xuetiaobd.png";
//怪物头上血条
static const char p_bloodlinehong[] = "xuetiaohongbd.png";
//人物聊天背景
static const char p_liaotianbd[] = "duihuakuang.png";
//故事对话框
static const char p_storytipbd[] = "tipbd.png";
//伤害数值
static const char p_makenumberbd[] = "numbers1.png";

//地图资源
static const char map_shengjie[] = "map_shengjie.jpg";
static const char map_fangcunshan[] = "map_fangcunshan.jpg";
static const char map_dongfu[] = "map_dongfu.jpg";
static const char map_niumowang[] = "map_niumowang.jpg";
static const char map_fengjing1[] = "map_fengjing1.jpg";

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	static CCString* publictouming = CCString::create("0049-ecd97d89-");
	
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	static CCString* publictouming = CCString::create("/effects/part1/shentan1/0049-ecd97d89-");

#endif


//第一章特效集
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	static CCString* effpath_shentan1 = CCString::create("0049-ecd97d89-");
	static CCString* effpath_shentan2 = CCString::create("eff_part1_");
	static CCString* effpath_huanjing1 = CCString::create("eff_yun1_");
	static CCString* effpath_shownpc = CCString::create("show_npc1_");
	static CCString* effpath_shownpc2 = CCString::create("show_npc2_");
	static CCString* effpath_shownpc3 = CCString::create("show_npc3_");
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	static CCString* effpath_shentan1 = CCString::create("/effects/part1/shentan1/0049-ecd97d89-");
	static CCString* effpath_shentan2 = CCString::create("/effects/part1/shentan2/eff_part1_");
	static CCString* effpath_huanjing1 = CCString::create("/effects/part1/huanjing1/eff_yun1_");
	static CCString* effpath_shownpc = CCString::create("/effects/part1/shownpc/show_npc1_");
	static CCString* effpath_shownpc2 = CCString::create("/effects/part1/shownpc2/show_npc2_");
	static CCString* effpath_shownpc3 = CCString::create("/effects/part1/shownpc3/show_npc3_");

	static CCString* eff_cj1 = CCString::create("/effects/logineff1/eff_cj1_");
	static CCString* eff_cj2 = CCString::create("/effects/logineff2/eff_cj2_");
	static CCString* eff_cj3 = CCString::create("/effects/logineff3/eff_cj3_");
	static CCString* eff_cj4 = CCString::create("/effects/logineff4/eff_jc4_");
	
#endif

//NPC资源
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	static CCString* npc_select_flag1 = CCString::create("eff_select1_");
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	static CCString* npc_select_flag1 = CCString::create("/effects/public/select2/eff_select1_");

#endif


#endif//_PUBLIC_IMAGE_PATH_
