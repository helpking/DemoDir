//
//  TopScene.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/14.
//
//

#include "TopScene.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

namespace UScene
{
    
    TopScene::TopScene()
    : demoPlayerAction_(nullptr)
    , walkBtn_(nullptr)
    {
        
    }
    
    TopScene::~TopScene()
    {
        CC_SAFE_RELEASE_NULL(walkBtn_);
    }
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    void TopScene::onEnter()
    {
        SceneBase::onEnter();
        
        //加载动画：
        cocostudio::timeline::ActionTimeline *action = NULL;
        action = CSLoader::createTimeline("Role.csb");
        action->gotoFrameAndPlay(0, 25, true);
        this->runAction(action);
        
        action = CSLoader::createTimeline("WindMill.csb");
        action->gotoFrameAndPlay(0, 35, true);
        this->runAction(action);
        
        this->demoPlayerAction_ = CSLoader::createTimeline("DemoPlayer.csb");
        this->demoPlayerAction_->gotoFrameAndPlay(0, 316, true);
        this->runAction(this->demoPlayerAction_);
        
        if (this->walkBtn_)
        {
            this->walkBtn_->setEnabled(false);
            this->walkBtn_->setTouchEnabled(false);
        }
    }
    
    /**
     * @brief 変数一覧の初期化
     */
    void TopScene::initCcsMemberVariables()
    {
        CCS_MEMBER_VARIABLE_ASSIGNER(this, "walkBtn", cocos2d::ui::Button*, this->walkBtn_);
    }
    
    /**
     * @brief タッチコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    cocos2d::ui::Widget::ccWidgetTouchCallback TopScene::initCcsOnTouchCallbackInfo(const std::string& iCallBackName)
    {
        if (iCallBackName == "onWalkBtnTouch")
        {
            return CC_CALLBACK_2(TopScene::onWalkBtnTouch, this);
        }
        else if (iCallBackName == "onAttackBtnTouch")
        {
            return CC_CALLBACK_2(TopScene::onAttackBtnTouch, this);
        }
        return nullptr;
    }
    
    
    void TopScene::onWalkBtnTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
    {
        if (this->demoPlayerAction_)
        {
            this->stopAction(this->demoPlayerAction_);
        }
        
        this->demoPlayerAction_ = CSLoader::createTimeline("DemoPlayer.csb");
        this->demoPlayerAction_->gotoFrameAndPlay(115, 160, true);
        this->runAction(this->demoPlayerAction_);
    }
    
    void TopScene::onAttackBtnTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
    {
        if (this->demoPlayerAction_)
        {
            this->stopAction(this->demoPlayerAction_);
        }
        
        this->demoPlayerAction_ = CSLoader::createTimeline("DemoPlayer.csb");
        this->demoPlayerAction_->gotoFrameAndPlay(131, 250, true);
        this->runAction(this->demoPlayerAction_);
    }
    
    static TopSceneReader* _instanceTopSceneReader = nullptr;
    TopSceneReader* TopSceneReader::getInstance()
    {
        if (!_instanceTopSceneReader)
        {
            _instanceTopSceneReader = new TopSceneReader();
        }
        return _instanceTopSceneReader;
    }
    
    void TopSceneReader::purge()
    {
        CC_SAFE_DELETE(_instanceTopSceneReader);
    }
    
    Node* TopSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
    {
        TopScene* node = TopScene::create();
        setPropsWithFlatBuffers(node, nodeOptions);
        return node;
    }
}
