//
//  TopScene.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/14.
//
//

#ifndef ___21_FirstSample__TopScene__
#define ___21_FirstSample__TopScene__

#include "UICommon.h"

#include "CsbBase.h"
#include "UIButton.h"

USING_NS_COMMON_CSB;

NS_BEGIN_UISCENE

class TopScene
: public CsbBase
{
public:
    CREATE_FUNC(TopScene)
    TopScene();
    ~TopScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual void onEnter() override;
    
    virtual void onWalkBtnTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    virtual void onAttackBtnTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    
    /**
     * @brief 変数一覧の初期化
     */
    virtual void initCcsMemberVariables() override;
    
    /**
     * @brief タッチコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual cocos2d::ui::Widget::ccWidgetTouchCallback initCcsOnTouchCallbackInfo(const std::string& iCallBackName) override;
    
private:
    
    cocostudio::timeline::ActionTimeline* demoPlayerAction_;
    
    cocos2d::ui::Button* walkBtn_;
    
};

// CSBファイルのローダー
CSB_CREATE_LOADER(TopScene);

NS_END_UISCENE

#endif /* defined(___21_FirstSample__TopScene__) */
