#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "TopScene.h"
#include "ObjectFactory.h"
#include "GameManager.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    // マネジャーの初期化する
    
    
    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("TopSceneReader",(ObjectFactory::Instance)UIScene::TopSceneReader::getInstance);

    auto rootNode = CSLoader::createNode("Scene/TopScene.csb");
    addChild(rootNode);
    
    return true;
}