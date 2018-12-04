#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
//使用UI引用的命名空间
using namespace cocos2d::ui;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    /**  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    **/
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("FirstScene.csb");

    addChild(rootNode);

	//通过按钮的名字获得按钮
	Button* button1 = dynamic_cast<Button*>(rootNode->getChildByName("Button_1"));
	Button* button2 = dynamic_cast<Button*>(rootNode->getChildByName("Button_2"));
	//添加监听
	button1->addTouchEventListener(CC_CALLBACK_2(HelloWorld::Option, this));
	button2->addTouchEventListener(CC_CALLBACK_2(HelloWorld::Option2, this));

    return true;
}


//按钮响应函数
void HelloWorld::Option(Ref* pSender, Widget::TouchEventType type)
{
	switch (type)
	{
		//按下按钮
	case Widget::TouchEventType::BEGAN:
	{
		log("Down !");
		auto rootNode = CSLoader::createNode("MainScene.csb");

		//addChild(rootNode);
		Director::getInstance()->replaceScene(TransitionFade::create(0.5, (Scene*)rootNode, Color3B(0, 255, 255)));
	}
	break;

	//松开按钮
	case Widget::TouchEventType::ENDED:
	{
		log("Up !");
	}
	break;

	//在按钮上移动
	case Widget::TouchEventType::MOVED:
	{
		log("Move !");
	}
	break;

	//取消按钮
	case Widget::TouchEventType::CANCELED:
	{
		log("Cancel !");
	}
	break;
	default:
		break;
	}
}

//按钮响应函数
void HelloWorld::Option2(Ref* pSender, Widget::TouchEventType type)
{
	switch (type)
	{
		//按下按钮
	case Widget::TouchEventType::BEGAN:
	{
		log("Down !");
		//auto rootNode = CSLoader::createNode("MainScene.csb");

		//addChild(rootNode);
	}
	break;

	//松开按钮
	case Widget::TouchEventType::ENDED:
	{
		log("Up !");
	}
	break;

	//在按钮上移动
	case Widget::TouchEventType::MOVED:
	{
		log("Move !");
	}
	break;

	//取消按钮
	case Widget::TouchEventType::CANCELED:
	{
		log("Cancel !");
	}
	break;
	default:
		break;
	}
}
