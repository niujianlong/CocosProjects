#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocostudio::timeline;
//ʹ��UI���õ������ռ�
using namespace cocos2d::ui;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	//��ť��Ӧ����
	void Option(Ref* pSender, Widget::TouchEventType type);
	void Option2(Ref* pSender, Widget::TouchEventType type);
	//�����ӽ�
	void setViewpointCenter(Point position);
	//touch ʱ��Ļص�����
	bool onTouchBegan(Touch *pTouch, Event *pEvent);
	void onTouchEnded(Touch *pTouch, Event *pEvent);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
private:
	TMXTiledMap  *map;
	Vec2 beginPoint;
	Sprite *player;
};

#endif // __HELLOWORLD_SCENE_H__
