#include "cocos2d.h"

USING_NS_CC;
		//ÎüÑªòùòðÆÕÍ¨¹¥»÷
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	 CCString* skill_xixue = CCString::create("skill_xixue_");
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	 CCString* skill_xixue = CCString::create("/skills/xixue/skill_xixue_");
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	 CCString* skill_kongjumo = CCString::create("skill_kongjimo_");
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	 CCString* skill_kongjumo = CCString::create("/skills/kongjumo/skill_kongjimo_");
#endif

