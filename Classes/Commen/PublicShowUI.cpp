#include "PublicShowUI.h"


PublicShowUI::PublicShowUI(void)
{
	//初始化
	act_moveto_label=NULL;
	act_moveto_labelback=NULL;
	
}


PublicShowUI::~PublicShowUI(void)
{
}

void PublicShowUI::setGameText(CCLayer* layer,CCString* str,CCPoint cp,int size)
{
	label = CCLabelTTF::create(str->getCString(), "微软雅黑",size);
	//label->setColor(ccc3(255, 255, 255));
	label->setColor(Color3B::WHITE);
	//label->setDirty(true);
	label->setPosition(ccp(cp.x,cp.y));
	layer->addChild(label,4);
	labelback = CCLabelTTF::create(str->getCString(), "微软雅黑",size);
	//labelback->setColor(ccc3(0, 0, 0));
	label->setColor(Color3B::BLACK);

	//labelback->setDirty(true);
	labelback->setPosition(ccp(cp.x+1,cp.y-1));
	layer->addChild(labelback,3);
}

void PublicShowUI::setGameTalkAbout(CCLayer* layer,CCPoint cp,int size,CCArray *stringArray,int zindex)
{
	p_ui_talkabout = new CCArray();
	p_ui_talkabout_back = new CCArray();
	if(stringArray->count()>0)
	{
		int j = stringArray->count()-1;
		for(int i = 0 ; i<stringArray->count();i++)
		{

			CCString* strthis = (CCString *)stringArray->objectAtIndex(i);
			CCLabelTTF* newlabels =  CCLabelTTF::create(strthis->getCString(), "微软雅黑",size);
			//newlabels->setColor(ccc3(255,255,255));//白色
			newlabels->setColor(Color3B::WHITE);//白色
			//newlabels->setDirty(true);
			newlabels->setPosition(ccp(cp.x,cp.y+j*20));
			p_ui_talkabout->addObject(newlabels);
			CCLabelTTF* newlabels2 =  CCLabelTTF::create(strthis->getCString(), "微软雅黑",size);
			//newlabels2->setColor(ccc3(0,0,0));//ccBLACK
			newlabels2->setColor(Color3B::BLACK);
			//newlabels2->setDirty(true);
			newlabels2->setPosition(ccp(cp.x+1,cp.y+1+j*20));
			p_ui_talkabout_back->addObject(newlabels2);
			j--;
			
		}
	}

	if(p_ui_talkabout->count()>0)
	{
		for(int i = 0; i<p_ui_talkabout->count();i++)
		{
			layer->addChild((CCLabelTTF *)p_ui_talkabout->objectAtIndex(i),zindex+1);
			layer->addChild((CCLabelTTF *)p_ui_talkabout_back->objectAtIndex(i),zindex);
			
		}
	}
}

void PublicShowUI::updataGameText(CCPoint cp)
{
	label->setPosition(ccp(cp.x,cp.y));
	labelback->setPosition(ccp(cp.x+1,cp.y-1));
}



void PublicShowUI::moveGameText(bool endflag,int uestime,CCPoint newpoint)
{
	log("______wwwwwwwwwwwwwwwwwwwwww_______");
	
	
	label->stopAction(act_moveto_label);
	labelback->stopAction(act_moveto_labelback);

	act_moveto_label = CCMoveTo::create(uestime,newpoint);
	act_moveto_label->retain();
	act_moveto_labelback = CCMoveTo::create(uestime,ccp(newpoint.x+1,newpoint.y-1));
	act_moveto_labelback->retain();
	label->runAction(act_moveto_label);
	labelback->runAction(act_moveto_labelback);
	log("______++++++++++++++++++++++_______");
}
