#include "EffectsCommen.h"


EffectsCommen::EffectsCommen(CCPoint basepoint,CCString* imgurl,float actiontime,float maxnum,int showtype,int zOrder)
{

	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	CCString* publictouming = CCString::create("0049-ecd97d89-");
	
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	CCString* publictouming = CCString::create("/effects/part1/shentan1/0049-ecd97d89-");
#endif

	act_moveto = NULL;
	char indeximg[100] = {0};
	sprintf(indeximg,"%s00000.png",publictouming->getCString());
	effects_main = EffectsCommen::create(indeximg);
	effects_main->setPosition(basepoint);
	if(effects_main==NULL)
	{
		log("图层路径有误，请检查路径");
		return;
	}

	CCAnimation* thisdonghua = CCAnimation::create();
	CCAnimation* thisdonghua_return = CCAnimation::create();

	for(int i = 0; i<= maxnum ; i++)
	{
		char donghuaurl[100] = {0};
		sprintf(donghuaurl,"%s00%03d.png",imgurl->getCString(),i);
		thisdonghua->addSpriteFrameWithFileName(donghuaurl);
	}

	if(actiontime>0)
	{
		thisdonghua->setDelayPerUnit(actiontime/maxnum);
	}
	else  
	{
		thisdonghua->setDelayPerUnit(2.0f/15.0f);//执行默认时间
	}
	thisdonghua->setRestoreOriginalFrame(true);

	//特效显示方式
	if(showtype==0)
	{
		//无限循环
		thisdonghua->setLoops(-1);
		CCAnimate* playdonghua = CCAnimate::create(thisdonghua);
		actall = CCSequence::create(playdonghua,NULL);
	}
	else if(showtype==1)
	{
		//只播放一次
		thisdonghua->setLoops(1);
		CCAnimate* playdonghua = CCAnimate::create(thisdonghua);
		actall = CCSequence::create(playdonghua,NULL);
	}
	else if(showtype==2)
	{
		//循环一次之后消失
		thisdonghua->setLoops(1);
		CCFiniteTimeAction *actbackfun = CCCallFunc::create(this, callfunc_selector(EffectsCommen::moveoverCallBack_setvisible));
	    CCAnimate* playdonghua = CCAnimate::create(thisdonghua);
		actall = CCSequence::create(playdonghua,actbackfun,NULL);
	}
	else if(showtype==3)
	{
		//循环一次之后消失
		thisdonghua->setLoops(2);
		CCFiniteTimeAction *actbackfun = CCCallFunc::create(this, callfunc_selector(EffectsCommen::moveoverCallBack_setvisible));
	    CCAnimate* playdonghua = CCAnimate::create(thisdonghua);
		actall = CCSequence::create(playdonghua,actbackfun,NULL);
	}
	
	effects_main->runAction(actall);

}


EffectsCommen::~EffectsCommen(void)
{

}


void EffectsCommen::moveoverCallBack_setvisible(void)
{
	//播放完成隐藏
	effects_main->setVisible(false);
}


EffectsCommen::EffectsCommen(CCString* imgurl0,CCString* imgurl,int num1, CCString* imgurl2,int num2,CCString* imgurl3,int num3,CCPoint newpoint)
{
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	CCString* publictouming = CCString::create("0049-ecd97d89-");
	
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	CCString* publictouming = CCString::create("/effects/part1/shentan1/0049-ecd97d89-");
#endif
	act_moveto = NULL;
	char indeximg[100] = {0};
	sprintf(indeximg,"%s00000.png",publictouming->getCString());
	effects_main = EffectsCommen::create(indeximg);
	effects_main->setPosition(newpoint);
	if(effects_main==NULL)
	{
		log("图层路径有误，请检查路径");
		return;
	}

	CCAnimation* thisdonghua = CCAnimation::create();

	for(int i = 0; i<= num1 ; i++)
	{
		char donghuaurl2[100] = {0};
		sprintf(donghuaurl2,"%s00%03d.png",imgurl->getCString(),i);
		thisdonghua->addSpriteFrameWithFileName(donghuaurl2);
	}
	thisdonghua->setDelayPerUnit(3.0f/18.0f);//执行默认时间
	thisdonghua->setRestoreOriginalFrame(true);
	CCAnimate* playdonghua = CCAnimate::create(thisdonghua);
	thisdonghua->setLoops(1);

	CCAnimation* thisdonghua2 = CCAnimation::create();

	for(int i = 0; i<= num2 ; i++)
	{
		char donghuaurl[100] = {0};
		sprintf(donghuaurl,"%s00%03d.png",imgurl2->getCString(),i);
		thisdonghua2->addSpriteFrameWithFileName(donghuaurl);
	}
	thisdonghua2->setDelayPerUnit(2.0f/18.0f);//执行默认时间
	thisdonghua2->setRestoreOriginalFrame(true);
	CCAnimate* playdonghua2 = CCAnimate::create(thisdonghua2);
	thisdonghua2->setLoops(1);

	CCAnimation* thisdonghua3 = CCAnimation::create();

	for(int i = 0; i<= num3 ; i++)
	{
		char donghuaurl[100] = {0};
		sprintf(donghuaurl,"%s00%03d.png",imgurl3->getCString(),i);
		thisdonghua3->addSpriteFrameWithFileName(donghuaurl);
	}
	thisdonghua3->setDelayPerUnit(2.5f/18.0f);//执行默认时间
	thisdonghua3->setRestoreOriginalFrame(true);
	thisdonghua3->setLoops(1);
	CCAnimate* playdonghua3 = CCAnimate::create(thisdonghua3);
	CCFiniteTimeAction *actbackfun = CCCallFunc::create(this, callfunc_selector(EffectsCommen::moveoverCallBack_setvisible));
	actall = CCSequence::create(playdonghua,playdonghua2,playdonghua3,actbackfun,NULL);
	actall->retain();
	effects_main->runAction(actall);

}
