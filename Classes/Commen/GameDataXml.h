#ifndef __GAME_DATA_XML__
#define __GAME_DATA_XML__

#include <iostream>  
#include "cocos2d.h"  
#include <string>
using namespace cocos2d;  
using namespace std;  
class GameDataXml
{
public:
	GameDataXml();
	static bool ishavedata();
	~GameDataXml(void);
	void GetDataXml(void);
	static const char* ceshi(bool flag);
};

#endif//__GAME_DATA_XML__
