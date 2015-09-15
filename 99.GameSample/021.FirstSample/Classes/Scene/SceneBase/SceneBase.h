//
//  SceneBase.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/14.
//
//

#ifndef ___21_FirstSample__SceneBase__
#define ___21_FirstSample__SceneBase__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

namespace UScene
{
    
    // 変数の自動設定マクロ
#define CCS_MEMBER_VARIABLE_ASSIGNER(TARGET, MEMBERNAME, MEMBERTYPE, MEMBER)    \
    if ( TARGET && (strcmp(MEMBERNAME, "") != 0) )                                          \
    {                                                                           \
        MEMBER = static_cast<MEMBERTYPE>(TARGET->getChildByName(MEMBERNAME));   \
    }
    
    class SceneBase
    : public cocos2d::Node
    , public cocostudio::WidgetCallBackHandlerProtocol
    {
    public:
        CREATE_FUNC(SceneBase)
        SceneBase();
        ~SceneBase();
        
        // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
        virtual void onEnter() override;
        
        virtual cocos2d::ui::Widget::ccWidgetTouchCallback onLocateTouchCallback(const std::string &callBackName);
        virtual cocos2d::ui::Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
        virtual cocos2d::ui::Widget::ccWidgetEventCallback onLocateEventCallback(const std::string &callBackName);
        virtual void onSceneTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type, const std::string &callBackName);
        virtual void onSceneClick(cocos2d::Ref* sender, const std::string &callBackName);
        virtual void onSceneEvent(cocos2d::Ref* sender, int eventType, const std::string &callBackName);
        
        /**
         * @brief 変数一覧の初期化
         */
        virtual void initCcsMemberVariables() {};
        
        /**
         * @brief タッチコールバックの初期化
         * @param[in] iCallBackName コールバック名
         */
        virtual cocos2d::ui::Widget::ccWidgetTouchCallback initCcsOnTouchCallbackInfo(const std::string& iCallBackName);
        
        /**
         * @brief クリックコールバックの初期化
         * @param[in] iCallBackName コールバック名
         */
        virtual cocos2d::ui::Widget::ccWidgetClickCallback initCcsOnClickCallbackInfo(const std::string& iCallBackName);
        
        /**
         * @brief イベントコールバックの初期化
         * @param[in] iCallBackName コールバック名
         */
        virtual cocos2d::ui::Widget::ccWidgetEventCallback initCcsOnEnentCallbackInfo(const std::string& iCallBackName);
                
    private:
        
        cocos2d::CCLayer* uiLayer_;
    };
}

#endif /* defined(___21_FirstSample__SceneBase__) */
