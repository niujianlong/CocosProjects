#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
//ʹ��UI���õ������ռ�
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
	//map = TMXTiledMap::create("firstmap.tmx");
    auto rootNode = CSLoader::createNode("FirstScene.csb");

    addChild(rootNode);

	//ͨ����ť�����ֻ�ð�ť
	Button* button1 = dynamic_cast<Button*>(rootNode->getChildByName("Button_1"));
	Button* button2 = dynamic_cast<Button*>(rootNode->getChildByName("Button_2"));
	//��Ӽ���
	button1->addTouchEventListener(CC_CALLBACK_2(HelloWorld::Option, this));
	button2->addTouchEventListener(CC_CALLBACK_2(HelloWorld::Option2, this));

    return true;
}


//��ť��Ӧ����
void HelloWorld::Option(Ref* pSender, Widget::TouchEventType type)
{
	switch (type)
	{
		//���°�ť
	case Widget::TouchEventType::BEGAN:
	{
		log("Down !");
		auto rootNode = CSLoader::createNode("MainScene.csb");

		addChild(rootNode);
		//removeFromParent();
		//Director::getInstance()->replaceScene(TransitionFade::create(0.5, (Scene*)rootNode, Color3B(0, 255, 255)));
	}
	break;

	//�ɿ���ť
	case Widget::TouchEventType::ENDED:
	{
		log("Up !");
	}
	break;

	//�ڰ�ť���ƶ�
	case Widget::TouchEventType::MOVED:
	{
		log("Move !");
	}
	break;

	//ȡ����ť
	case Widget::TouchEventType::CANCELED:
	{
		log("Cancel !");
	}
	break;
	default:
		break;
	}
}

//��ť��Ӧ����
void HelloWorld::Option2(Ref* pSender, Widget::TouchEventType type)
{
	switch (type)
	{
		//���°�ť
	case Widget::TouchEventType::BEGAN:
	{
		log("Down !");
		map = TMXTiledMap::create("firstmap.tmx");
		addChild(map);
		//Director::getInstance()->replaceScene(TransitionFade::create(0.5, (Scene*)map, Color3B(0, 255, 255)));
		if (map == nullptr)
		{
			log("map file not found");
		}
		else
		{
			// position the sprite on the center of the screen
			//sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

			// add the sprite as a child to this layer
			//this->addChild(sprite, 0);
		}
		Size size = Director::sharedDirector()->getWinSize();
		player = Sprite::create("player.jpg");
		//Player *player = Player::create();
		//player->BindSprite(sprite);

		map->addChild(player,1);
		TMXObjectGroup * objGroup = map->getObjectGroup("player");
		auto  SpawnPoint = objGroup->getObject("SpawnPoint");
		float x = SpawnPoint["x"].asFloat();
		float y = SpawnPoint["y"].asFloat();
	
		player->setPosition(Vec2(x, y));
		setViewpointCenter(player->getPosition());

		//��Ӵ�����Ϣ
		auto listener = EventListenerTouchOneByOne::create();
		listener->onTouchBegan = [&](Touch *touch, Event *unused_event)->bool {return true; };
		listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	}
	break;

	//�ɿ���ť
	case Widget::TouchEventType::ENDED:
	{
		log("Up !");
	}
	break;

	//�ڰ�ť���ƶ�
	case Widget::TouchEventType::MOVED:
	{
		log("Move !");
	}
	break;

	//ȡ����ť
	case Widget::TouchEventType::CANCELED:
	{
		log("Cancel !");
	}
	break;
	default:
		break;
	}
}

void HelloWorld::setViewpointCenter(Point position)
{
	//��ȡ��ǰ��Ļ�ĳߴ�
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	//�����������Ļ�������߻����ұߣ�x��ֵ���Ǿ��鵱ǰ��xֵ������x��ֵ������Ļ��ȵ�һ�롣
	int x = MAX(position.x, winSize.width / 2);
	//TMXTiledMap  *map = TMXTiledMap::create("firstmap.tmx");
	//��ȡ������ͼ�ĳߴ�
	CCSize mapSize = map->getMapSize();

	//��ȡÿһ��ͼ��Ŀ��
	CCSize tileSize = map->getTileSize();

	CCLOG("%lf, %lf, %lf, %lf", mapSize.width, mapSize.height, tileSize.width, tileSize.height);

	//mapSize.width�ǵ�ͼ��x�᷽�����ж��ٸ���Ƭ,��ǰ��30
	//mapSize.height�ǵ�ͼ��y�᷽�����ж��ٸ���Ƭ����ǰ��10

	//���¹滮x��ֵ��
	x = MIN(x, mapSize.width * tileSize.width - winSize.width / 2);

	//��ȡ��Ļ���ĵ��λ��
	Point centerPoint = Point(winSize.width / 2, winSize.height / 2);

	//���¹滮��λ��
	Point actualPoint = Point(x, winSize.height / 2);

	//��ͼ����Ҫ�ƶ�����λ��
	Point viewPoint = centerPoint - actualPoint;

	//���¹滮��ǰ��ͼ��λ�á�
	this->setPosition(viewPoint);
}

bool HelloWorld::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	//��ȡ��ǰ�������ĵ��λ��
	Point point = pTouch->getLocation();

	//��openGL����ϵת��Ϊ�������ϵ�����Զ�λ���ڵ���ʵ�������ͼ����ߵ�λ�ö����Ǿ�����Ļ���½ǵ�λ�ã���λ��
	beginPoint = convertToNodeSpace(point);

	return true;
}

void HelloWorld::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	//��ȡ��ǰ�û��ĵ��������
	Point point = pTouch->getLocation();

	Point endPoint = convertToNodeSpace(point);

	

		//�����ʼ���������ͬһ���㣬��֤�ǵ����������ָ����
		if (1)
		{
			//��ȡ����ԭ����λ��
			Point playerPos = player->getPosition();

			//�õ��û���������ԭ��������λ�õĲ��
			Point disPos = endPoint - playerPos;

			//�ж�ƫ�Ƶľ�����ƫ���£�����ƫ���ҡ���ͼ��������
			//ƫ����
			if (abs(disPos.x) >= abs(disPos.y))
			{
				if (disPos.x > 0)
				{
					//ÿ��ƫ��һ��ͼ��Ŀ�ȡ�
					playerPos.x += map->getTileSize().width;
				}
				else
				{
					playerPos.x -= map->getTileSize().width;
				}
			}
			else //ƫ����
			{
				if (disPos.y > 0)
				{
					//ÿ��ƫ��һ��ͼ��ĸ߶�
					playerPos.y += map->getTileSize().height;
				}
				else
				{
					playerPos.y -= map->getTileSize().height;
				}
			}
			player->setPosition(playerPos);

			//��ͼ�澫���ƶ�
			setViewpointCenter(player->getPosition());
			//setPosition(player->getPosition());
		}
	

}