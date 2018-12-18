#include "GameDataXml.h"


GameDataXml::GameDataXml()
{
	CCLOG("*******************************华丽的分割线**********************************");
	CCUserDefault::sharedUserDefault()->setBoolForKey("isExisted",true);
	CCUserDefault::sharedUserDefault()->setStringForKey("name","杨胜杰");
	CCUserDefault::sharedUserDefault()->setStringForKey("age","18");
	CCUserDefault::sharedUserDefault()->setStringForKey("like","paly game");

	/*string name = CCUserDefault::sharedUserDefault()->getStringForKey("name");
	string age = CCUserDefault::sharedUserDefault()->getStringForKey("age");
	string like = CCUserDefault::sharedUserDefault()->getStringForKey("like");*/

	CCUserDefault::sharedUserDefault()->flush();
	CCLog(CCUserDefault::sharedUserDefault()->getXMLFilePath().c_str());
}

const char* GameDataXml::ceshi(bool flag)
{
	const char * filename = "ysj.xml" ;
	const char * pathfile = "this";
	const char * path = CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile(filename,pathfile);

	return path;
}

GameDataXml::~GameDataXml(void)
{
	
}

bool GameDataXml::ishavedata()
{
	CCUserDefault *save=CCUserDefault::sharedUserDefault();  
	if(!CCUserDefault::sharedUserDefault()->getBoolForKey("isExisted"))  
	{  
		CCLog("不存在");
		return false;
	}
	else
	{
		CCLog("文件存在,存在路径：");
		CCLog(CCUserDefault::sharedUserDefault()->getXMLFilePath().c_str());
		return true;
	}
}



void GameDataXml::GetDataXml(void)
{
	CCUserDefault *save=CCUserDefault::sharedUserDefault();  
	if(!CCUserDefault::sharedUserDefault()->getBoolForKey("isExisted"))  
	{  
		//相关操作  
		save->setBoolForKey("isExisted",true);  
	}
	else
	{

	}
}
