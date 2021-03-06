#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Spirits/SpiritsPlayer.h"
#include "GameData/GetNPCData.h"

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
	if (!Layer::init())
	{
		return false;
	}
	//map = TMXTiledMap::create("firstmap.tmx");
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

		addChild(rootNode);
		//removeFromParent();
		//Director::getInstance()->replaceScene(TransitionFade::create(0.5, (Scene*)rootNode, Color3B(0, 255, 255)));
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
SpiritsPlayer* role_main = NULL;
//按钮响应函数
void HelloWorld::Option2(Ref* pSender, Widget::TouchEventType type)
{
	switch (type)
	{
		//按下按钮
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
		//加载猪脚
		GetNPCData* basedatas = new GetNPCData();
		basedatas->GetNPCchapter1();
		basedatas->role_player.nowpoint = CCPointMake(x + 20, y + 20);
		role_main = new SpiritsPlayer(basedatas->role_player, 1, false);
		role_main->npc->retain();
		map->addChild(role_main->npc, 2);

		player->setPosition(Vec2(x, y));
		//role_main->setPosition(Vec2(x + 10, y + 10));
		sceneScroll(player->getPosition());

		//添加触控消息
		auto listener = EventListenerTouchOneByOne::create();
		listener->onTouchBegan = [&](Touch *touch, Event *unused_event)->bool {return true; };
		listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
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

void HelloWorld::setViewpointCenter(Point position)
{
	//获取当前屏幕的尺寸
	Size winSize = Director::getInstance()->getWinSize();

	//如果精灵在屏幕中央的左边或者右边，x的值就是精灵当前的x值，否则x的值就是屏幕宽度的一半。
	int x = MAX(position.x, winSize.width / 2);
	//TMXTiledMap  *map = TMXTiledMap::create("firstmap.tmx");
	//获取整个地图的尺寸
	Size mapSize = map->getMapSize();

	//获取每一个图块的宽高
	Size tileSize = map->getTileSize();

	log("%lf, %lf, %lf, %lf", mapSize.width, mapSize.height, tileSize.width, tileSize.height);

	//mapSize.width是地图的x轴方向上有多少个瓦片,当前是30
	//mapSize.height是地图的y轴方向上有多少个瓦片，当前是10

	//重新规划x的值。
	x = MIN(x, mapSize.width * tileSize.width - winSize.width / 2);

	//获取屏幕中心点的位置
	Point centerPoint = Point(winSize.width / 2, winSize.height / 2);

	//重新规划的位置
	Point actualPoint = Point(x, winSize.height / 2);

	//地图最终要移动到的位置
	Point viewPoint = centerPoint - actualPoint;

	//重新规划当前视图的位置。
	this->setPosition(viewPoint);
}

bool HelloWorld::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	//获取当前触摸到的点的位置
	Point point = pTouch->getLocation();

	//将openGL坐标系转化为结点做标系，可以定位到节点真实（距离地图最左边的位置而不是距离屏幕左下角的位置）的位置
	beginPoint = convertToNodeSpace(point);

	return true;
}

void HelloWorld::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	//获取当前用户的点击结束点
	Point point = pTouch->getLocation();

	Point endPoint = convertToNodeSpace(point);




	//获取精灵原来的位置
	Point playerPos = player->getPosition();

	//得到用户触摸点与原来精灵点的位置的差距
	Point disPos = endPoint - playerPos;

	//判断偏移的距离是偏上下，还是偏左右。画图理解很容易
	//偏左右
	if (abs(disPos.x) >= abs(disPos.y))
	{
		if (disPos.x > 0)
		{
			//每次偏移一个图块的宽度。
			playerPos.x += map->getTileSize().width;
		}
		else
		{
			playerPos.x -= map->getTileSize().width;
		}
	}
	else //偏上下
	{
		if (disPos.y > 0)
		{
			//每次偏移一个图块的高度
			playerPos.y += map->getTileSize().height;
		}
		else
		{
			playerPos.y -= map->getTileSize().height;
		}
	}
	player->setPosition(playerPos);

	//地图随精灵移动
	//setViewpointCenter(player->getPosition());
	//setPosition(player->getPosition());
	sceneScroll(player->getPosition());



}

void HelloWorld::sceneScroll(Point position)
{
	//获取屏幕尺寸   
	Size screenSize = Director::getInstance()->getWinSize();
	//计算Tilemap的宽高，单位是像素
	Size mapSize = map->getMapSize();
	Size tileSize = map->getTileSize();
	Size mapSizeInPixel = Size(mapSize.width * tileSize.width, mapSize.height * tileSize.height); //Size(MapLayer::getInstance()->getTileMap()->getMapSize().width*MapLayer::getInstance()->getTileMap()->getTileSize().width,
		//MapLayer::getInstance()->getTileMap()->getMapSize().height*MapLayer::getInstance()->getTileMap()->getTileSize().height);
	//取英雄当前x坐标和屏幕中点x的最大值，如果英雄的x值较大，则会滚动   
	float x = MAX(position.x, screenSize.width / 2.0f);
	float y = MAX(position.y, screenSize.height / 2.0f);
	//舞台范围取屏幕范围,加外扩1tile,这里是像素.
	float w = screenSize.width + tileSize.width;
	float h = screenSize.height + tileSize.height;

	//地图总宽度大于屏幕宽度的时候才有可能滚动   
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
	//英雄的实际位置   
	Point heroPosition = Point(x, y);
	//屏幕中点位置   
	Point screenCenter = Point(screenSize.width / 2.0f, screenSize.height / 2.0f);
	//计算英雄实际位置和中点位置的距离   
	Point scrollPosition = screenCenter - heroPosition;

	//将场景移动到相应位置   
	this->setPosition(scrollPosition);
	//设置舞台范围，方便对进入舞台内的生物进行更新
	//Rect veiwpoint = Rect(-scrollPosition.x, -scrollPosition.y, -scrollPosition.x + w, -scrollPosition.y + h);
	//UnitManager::getInstance()->setStageView(veiwpoint);
}
