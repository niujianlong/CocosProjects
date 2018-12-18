#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Spirits/SpiritsPlayer.h"
#include "GameData/GetNPCData.h"

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
	if (!Layer::init())
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
SpiritsPlayer* role_main = NULL;
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
		
		player = Sprite::create("player.jpg");
		//Player *player = Player::create();
		//player->BindSprite(sprite);

		map->addChild(player, 1);
	
		TMXObjectGroup * objGroup = map->getObjectGroup("player");
		auto  SpawnPoint = objGroup->getObject("SpawnPoint");
		float x = SpawnPoint["x"].asFloat();
		float y = SpawnPoint["y"].asFloat();
		//�������
		GetNPCData* basedatas = new GetNPCData();
		basedatas->GetNPCchapter1();
		basedatas->role_player.nowpoint = CCPointMake(x + 20, y + 20);
		role_main = new SpiritsPlayer(basedatas->role_player, 1, false);
		role_main->npc->retain();
		map->addChild(role_main->npc, 2);

		player->setPosition(Vec2(x, y));
		//role_main->setPosition(Vec2(x + 10, y + 10));
		sceneScroll(player->getPosition());

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
	Size winSize = Director::getInstance()->getWinSize();

	//�����������Ļ�������߻����ұߣ�x��ֵ���Ǿ��鵱ǰ��xֵ������x��ֵ������Ļ��ȵ�һ�롣
	int x = MAX(position.x, winSize.width / 2);
	//TMXTiledMap  *map = TMXTiledMap::create("firstmap.tmx");
	//��ȡ������ͼ�ĳߴ�
	Size mapSize = map->getMapSize();

	//��ȡÿһ��ͼ��Ŀ��
	Size tileSize = map->getTileSize();

	log("%lf, %lf, %lf, %lf", mapSize.width, mapSize.height, tileSize.width, tileSize.height);

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
	//setViewpointCenter(player->getPosition());
	//setPosition(player->getPosition());
	sceneScroll(player->getPosition());



}

void HelloWorld::sceneScroll(Point position)
{
	//��ȡ��Ļ�ߴ�   
	Size screenSize = Director::getInstance()->getWinSize();
	//����Tilemap�Ŀ�ߣ���λ������
	Size mapSize = map->getMapSize();
	Size tileSize = map->getTileSize();
	Size mapSizeInPixel = Size(mapSize.width * tileSize.width, mapSize.height * tileSize.height); //Size(MapLayer::getInstance()->getTileMap()->getMapSize().width*MapLayer::getInstance()->getTileMap()->getTileSize().width,
		//MapLayer::getInstance()->getTileMap()->getMapSize().height*MapLayer::getInstance()->getTileMap()->getTileSize().height);
	//ȡӢ�۵�ǰx�������Ļ�е�x�����ֵ�����Ӣ�۵�xֵ�ϴ�������   
	float x = MAX(position.x, screenSize.width / 2.0f);
	float y = MAX(position.y, screenSize.height / 2.0f);
	//��̨��Χȡ��Ļ��Χ,������1tile,����������.
	float w = screenSize.width + tileSize.width;
	float h = screenSize.height + tileSize.height;

	//��ͼ�ܿ�ȴ�����Ļ��ȵ�ʱ����п��ܹ���   
	if (mapSizeInPixel.width > screenSize.width)
	{
		x = MIN(x, mapSizeInPixel.width - screenSize.width / 2.0f);
	}
	else
	{
		w = mapSizeInPixel.width;
	}
	if (mapSizeInPixel.height > screenSize.height)
	{


		y = MIN(y, mapSizeInPixel.height - screenSize.height / 2.0f);
	}
	else
	{
		h = mapSizeInPixel.height;
	}
	//Ӣ�۵�ʵ��λ��   
	Point heroPosition = Point(x, y);
	//��Ļ�е�λ��   
	Point screenCenter = Point(screenSize.width / 2.0f, screenSize.height / 2.0f);
	//����Ӣ��ʵ��λ�ú��е�λ�õľ���   
	Point scrollPosition = screenCenter - heroPosition;

	//�������ƶ�����Ӧλ��   
	this->setPosition(scrollPosition);
	//������̨��Χ������Խ�����̨�ڵ�������и���
	//Rect veiwpoint = Rect(-scrollPosition.x, -scrollPosition.y, -scrollPosition.x + w, -scrollPosition.y + h);
	//UnitManager::getInstance()->setStageView(veiwpoint);
}
