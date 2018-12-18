#include "SpiritMain.h"
#include "../ImagePaths.h"

SpiritMain::SpiritMain(CCLayer* layer,MainRoledata roledata,int zOrder)
{
	CCSprite* npc = SpiritMain::create(roledata.spiritUrl->getCString());
	if(npc==NULL)
	{
		CCLog("图层路径有误，请检查路径");
		return;
	}
	//设置NPC初始位置坐标（该坐标取决于当前画层）
	npc->setPosition(roledata.nowpoint);
	//NPC动画
	CCAnimation* donghua = SpiritMain::getNowAnt(roledata);
	if(roledata.actiontime>0)
	{
		donghua->setDelayPerUnit(roledata.actiontime/roledata.maxcut_zhan);
	}
	else
	{
	    donghua->setDelayPerUnit(2.0f/15.0f);//执行默认时间
	}
	donghua->setRestoreOriginalFrame(true);
	donghua->setLoops(-1);
	CCAnimate* playdonghua = CCAnimate::create(donghua);
	npc->runAction(playdonghua);
	layer->addChild(npc,zOrder); 
	//
	p_ui = new PublicShowUI();

	p_ui->setGameText(layer,roledata.spiritname,ccp(roledata.nowpoint.x,roledata.nowpoint.y+(int)(npc->getTexture()->getPixelsHigh()*0.3f)),12);

	//添加NPC人物脚下阴影
	CCSprite* yinzi = CCSprite::create(p_yinzi);
	if(yinzi==NULL)
	{
		CCLog("图层路径有误，请检查路径");
		return;
	}
	yinzi->setZOrder(0);
	yinzi->setPosition(ccp(roledata.nowpoint.x,roledata.nowpoint.y-(int)(npc->getTexture()->getPixelsHigh()*0.2f)));
	layer->addChild(yinzi);

	//添加NPC人物聊天背景
	CCSprite* sp_liaotianbd = CCSprite::create(p_liaotianbd);
	//sp_liaotianbd->setContentSize(CCSize(200,200));
	sp_liaotianbd->setZOrder(2);
	sp_liaotianbd->setPosition(ccp(roledata.nowpoint.x,roledata.nowpoint.y-(int)(npc->getTexture()->getPixelsHigh()*0.2f)));
	layer->addChild(sp_liaotianbd);


}



CCAnimation* SpiritMain::getNowAnt(MainRoledata roledata)
{
	CCAnimation* thisdonghua = CCAnimation::create();
	switch (roledata.dir)
	{
	case up:

		switch (roledata.acttodo)
		{
		case run:
			for(int i = 0; i<=roledata.maxcut_pao ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s06%03d.png",roledata.spiritUrl_pao->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case stand:
			for(int i = 0; i<=roledata.maxcut_zhan ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s06%03d.png",roledata.spiritUrl_zhan->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case attack:
			break;
		case death:
			break;
		case funny:
			break;
		default:
			break;
		}

		break;
	case down:
		switch (roledata.acttodo)
		{
		case run:
			for(int i = 0; i<=roledata.maxcut_pao ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s04%03d.png",roledata.spiritUrl_pao->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case stand:
			for(int i = 0; i<=roledata.maxcut_zhan ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s04%03d.png",roledata.spiritUrl_zhan->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case attack:
			break;
		case death:
			break;
		case funny:
			break;
		default:
			break;
		}
		break;
	case lefts:
		switch (roledata.acttodo)
		{
		case run:
			for(int i = 0; i<=roledata.maxcut_pao ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s07%03d.png",roledata.spiritUrl_pao->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case stand:
			for(int i = 0; i<=roledata.maxcut_zhan ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s07%03d.png",roledata.spiritUrl_zhan->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case attack:
			break;
		case death:
			break;
		case funny:
			break;
		default:
			break;
		}
		break;
	case rigth:
		switch (roledata.acttodo)
		{
		case run:
			for(int i = 0; i<=roledata.maxcut_pao ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s05%03d.png",roledata.spiritUrl_pao->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case stand:
			for(int i = 0; i<=roledata.maxcut_zhan ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s05%03d.png",roledata.spiritUrl_zhan->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case attack:
			break;
		case death:
			break;
		case funny:
			break;
		default:
			break;
		}
		break;
	case rigth_up:
		switch (roledata.acttodo)
		{
		case run:
			for(int i = 0; i<=roledata.maxcut_pao ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s03%03d.png",roledata.spiritUrl_pao->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case stand:
			for(int i = 0; i<=roledata.maxcut_zhan ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s03%03d.png",roledata.spiritUrl_zhan->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case attack:
			for(int i = 0; i<=roledata.maxcut_attack ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s03%03d.png",roledata.spiritUrl_attack->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case death:
			break;
		case funny:
			break;
		default:
			break;
		}
		break;
	case rigth_down:
		switch (roledata.acttodo)
		{
		case run:
			for(int i = 0; i<=roledata.maxcut_pao ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s00%03d.png",roledata.spiritUrl_pao->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case stand:
			for(int i = 0; i<=roledata.maxcut_zhan ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s00%03d.png",roledata.spiritUrl_zhan->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case attack:
			for(int i = 0; i<=roledata.maxcut_attack ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s00%03d.png",roledata.spiritUrl_attack->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case death:
			break;
		case funny:
			break;
		default:
			break;
		}
		break;
	case left_down:
		switch (roledata.acttodo)
		{
		case run:
			for(int i = 0; i<=roledata.maxcut_pao ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s01%03d.png",roledata.spiritUrl_pao->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case stand:
			for(int i = 0; i<=roledata.maxcut_zhan ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s01%03d.png",roledata.spiritUrl_zhan->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case attack:
			for(int i = 0; i<=roledata.maxcut_attack ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s01%03d.png",roledata.spiritUrl_attack->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case death:
			break;
		case funny:
			break;
		default:
			break;
		}
		break;
	case left_up:
		switch (roledata.acttodo)
		{
		case run:
			for(int i = 0; i<=roledata.maxcut_pao ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s02%03d.png",roledata.spiritUrl_pao->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case stand:
			for(int i = 0; i<=roledata.maxcut_zhan ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s02%03d.png",roledata.spiritUrl_zhan->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case attack:
			for(int i = 0; i<=roledata.maxcut_attack ; i++)
			{
				char donghuaurl[100] = {0};
				sprintf(donghuaurl,"%s02%03d.png",roledata.spiritUrl_attack->getCString(),i);
				thisdonghua->addSpriteFrameWithFileName(donghuaurl);
			}
			break;
		case death:
			break;
		case funny:
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

	return thisdonghua;
}



SpiritMain::~SpiritMain(void)
{
}

