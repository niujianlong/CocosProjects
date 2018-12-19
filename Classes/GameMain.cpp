#include "GameMain.h"
#include "AppMacros.h"
#include "PublicScenes/Scene_Diyu.h"
#include "PublicScenes/ToScene.h"
#include "ImagePaths.h"
//#include "Commen/GameDataXml.h"
#include "Commen/HXmlParse.h"
#include "Commen/PublicCommen.h"
extern int storyplayflag_caozuo;

USING_NS_CC;

CCScene* GameMain::scene()
{
	CCScene *scene = CCScene::create();

	GameMain *layer = GameMain::create();

	scene->addChild(layer);

	return scene;
}


bool GameMain::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize(); 
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	//CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
	//	"CloseNormal.png",
	//	"CloseSelected.png",
	//	this,
	//	menu_selector(GameMain::menuCloseCallback));

	//pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
	//	origin.y + pCloseItem->getContentSize().height/2));

	//CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	//pMenu->setPosition(CCPointZero);
	//this->addChild(pMenu, 1);


	//string url = "txt/b.txt";
	////读取文件
	//string str  = PublicCommen::getFileByName(url);

	//vector<string> ss = PublicCommen::split(str,"aa");

	//string aa = ss.at(0);


	//if(!GameDataXml::ishavedata())
	//{
	//	bool ss = GameDataXml::ishavedata();
	//	GameDataXml();
	//}
	//else
	//{

	//}

	map_y =visibleSize.height/2;
	map_x = visibleSize.width/2;

	mainmap = new MapsBase(this,"map_shengjie.jpg",0,ccp(map_x,map_y-66));
	mainmap_Touch =  mainmap_Touch->create("map_shengjie0.png");
	mainmap_Touch->setimg("map_shengjie0.png");
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	mainmap_Touch->setPosition(ccp(map_x,map_y-66));
	mainmap_Touch->setVisible(false);//是否显示点击层
	this->addChild(mainmap_Touch, 0);

	float map_fornpc_x,map_fornpc_y;
	map_fornpc_x= mainmap->nowmap->getContentSize().width/2;
	map_fornpc_y=mainmap->nowmap->getContentSize().height/2;
	//故事里面的NPC列表
	npclist =  CCArray::createWithCapacity(4);
	//故事NPC
	GetNPCData npcdata = GetNPCData();
	npcdata.GetNPCchapter1();
	npcdata.role_taiyizhengren.dir=rigth_down;
	SpiritsPlayer* npc_taiyizhengren1 = new SpiritsPlayer(npcdata.role_taiyizhengren,0,false);
	npcdata.role_taishanglaojun.dir=rigth_down;
	SpiritsPlayer* npc_taishanglaojun1 = new SpiritsPlayer(npcdata.role_taishanglaojun,0,false);
	npcdata.role_chijiaodaxian.dir=rigth_down;
	SpiritsPlayer* npc_chijiaodaxian1 = new SpiritsPlayer(npcdata.role_chijiaodaxian,0,false);
	npcdata.role_qingxuzhenjun.dir=rigth_down;
	SpiritsPlayer* npc_qingxunzhenjun1 = new SpiritsPlayer(npcdata.role_qingxuzhenjun,0,false);
	npcdata.role_player.dir=rigth_down;
	SpiritsPlayer* npc_zhujiao = new SpiritsPlayer(npcdata.role_player,0,false);

	npclist->addObject(npc_taiyizhengren1->npc);
	npclist->addObject(npc_taishanglaojun1->npc);
	npclist->addObject(npc_chijiaodaxian1->npc);
	npclist->addObject(npc_qingxunzhenjun1->npc);
	npclist->addObject(npc_zhujiao->npc);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	static CCString* strpart1 = CCString::create("part1.txt");
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	static CCString* strpart1 = CCString::create("stroytxt/part1.txt");
#endif
	//读取文件
	string stroy_part1 = PublicCommen::getFileByName(strpart1->getCString());

	vector<string> talkstroynum = PublicCommen::split(stroy_part1,"\n");
	vector<string> talkstroynum_list ;
	CCArray* talkstroy_name =  CCArray::createWithCapacity(talkstroynum.size());
	CCArray* talkstroy_npcflag =  CCArray::createWithCapacity(talkstroynum.size());
	CCArray* talkstroy_about =  CCArray::createWithCapacity(talkstroynum.size());
	CCArray* talkstroy_todo =  CCArray::createWithCapacity(talkstroynum.size());
	CCArray* talkstroy_progress =  CCArray::createWithCapacity(talkstroynum.size());
	for (int i = 0; i < talkstroynum.size(); i++)
	{
		talkstroynum_list = PublicCommen::split(talkstroynum.at(i),"@");
		talkstroy_name->addObject(CCString::create(talkstroynum_list.at(0)));
		talkstroy_npcflag->addObject(CCString::create(talkstroynum_list.at(1)));
		talkstroy_about->addObject(CCString::create(talkstroynum_list.at(2)));
		talkstroy_todo->addObject(CCString::create(talkstroynum_list.at(3)));
		talkstroy_progress->addObject(CCString::create(talkstroynum_list.at(4)));
	}

	//故事对话框
	storyTips_part1 = new TipsForStory(this,CCPointMake(map_x,map_y),CCString::create(p_storytipbd),2,npclist,talkstroy_name,talkstroy_npcflag,talkstroy_about,talkstroy_todo,talkstroy_progress);
	//启动定时器监听事件
	this->schedule(schedule_selector(GameMain::storyplaydataflag), 1.0f); 

	CCMenuItemImage *item1 = CCMenuItemImage::create(p_toscene, p_toscene0, this, menu_selector(GameMain::GoToCcene) );
	item1->setPosition(ccp(visibleSize.width/2+220, visibleSize.height/2+150));
	CCMenu *menu = CCMenu::create(item1, NULL);
	menu->setPosition( CCPointZero );
	this->addChild(menu, 0);

	//开启点击事件
	setTouchEnabled(true);
	return true;
}

void GameMain::storyplaydataflag(float times)
{
	if(storyplayflag_caozuo==1)
	{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	static CCString* strpart2 = CCString::create("part2.txt");
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	static CCString* strpart2 = CCString::create("stroytxt/part2.txt");
#endif

		string url = strpart2->getCString();
		//读取文件
		string stroy_part1 = PublicCommen::getFileByName(url);

		vector<string> talkstroynum = PublicCommen::split(stroy_part1,"\n");
		vector<string> talkstroynum_list ;
		CCArray* talkstroy_name =  CCArray::createWithCapacity(talkstroynum.size());
		CCArray* talkstroy_npcflag =  CCArray::createWithCapacity(talkstroynum.size());
		CCArray* talkstroy_about =  CCArray::createWithCapacity(talkstroynum.size());
		CCArray* talkstroy_todo =  CCArray::createWithCapacity(talkstroynum.size());
		CCArray* talkstroy_progress =  CCArray::createWithCapacity(talkstroynum.size());
		for (int i = 0; i < talkstroynum.size(); i++)
		{
			talkstroynum_list = PublicCommen::split(talkstroynum.at(i),"@");
			talkstroy_name->addObject(CCString::create(talkstroynum_list.at(0)));
			talkstroy_npcflag->addObject(CCString::create(talkstroynum_list.at(1)));
			talkstroy_about->addObject(CCString::create(talkstroynum_list.at(2)));
			talkstroy_todo->addObject(CCString::create(talkstroynum_list.at(3)));
			talkstroy_progress->addObject(CCString::create(talkstroynum_list.at(4)));
		}

		//故事对话框
		storyTips_part2 = new TipsForStory(this,CCPointMake(map_x,map_y),CCString::create(p_storytipbd),2,npclist,talkstroy_name,talkstroy_npcflag,talkstroy_about,talkstroy_todo,talkstroy_progress);
		storyplayflag_caozuo=-1;
	}
	else if(storyplayflag_caozuo==2)
	{
		CCScene* s = new ToScene(true);
		CCLayer * pLayer = new Scene_Diyu();
		s->addChild(pLayer);
		pLayer->release();
		CCDirector::sharedDirector()->replaceScene(s);
		storyplayflag_caozuo=-1;
	}
}

void GameMain::GoToCcene(CCObject* pSender)
{
	CCScene* s = new ToScene(true);
	CCLayer * pLayer = new Scene_Diyu();
	s->addChild(pLayer);
	pLayer->release();
	CCDirector::sharedDirector()->replaceScene(s);
}

void GameMain::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}


void GameMain::registerWithTouchDispatcher()  
{  
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);  
}  


bool GameMain::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
	//taiyizhengren2->updateNpcPoint(pTouch->getLocation());
	//taiyizhengren2->moveTo(2,pTouch->getLocation());

	if(mainmap_Touch->ccTouchBegan("map_shengjie0.png",pTouch,pEvent)==true)
	{
		mainmap->moveMapto(pTouch->getLocation(),mainmap_Touch);
	}
	return true;  
}  

void GameMain::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
	//主角
	//GetNPCData npcdata11 = GetNPCData();
	//npcdata11.GetNPCchapter1();
	//npcdata11.role_player.nowpoint= pTouch->getLocation();
	//npcdata11.role_player.dir=rigth_down;
	//SpiritsPlayer taiyizhengren = SpiritsPlayer(this,npcdata11.role_player,0);
}  

void GameMain::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
}  

void GameMain::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)  
{  
}  
