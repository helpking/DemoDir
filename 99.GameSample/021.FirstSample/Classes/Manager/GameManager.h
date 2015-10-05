//
//  GameManager.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/17.
//
//

#ifndef _21_FirstSample_GameManager_h
#define _21_FirstSample_GameManager_h

#include "ManagerHeader.h"
#include "ResInfoPool.h"
#include "Singleton.h"

USING_NS_COMMON
//USING_NS_RESINFO_POOL
using namespace Manager::ResInfo;

NS_BEGIN_MANAGER

/**
 * @brief マネジャー
 */
class GameManager
{
public:
    
    /**
     * @brief コンストラクター
     */
    GameManager();
    
    /**
     * @brief デストラクタ
     */
    ~GameManager();
    
    /**
     * @brief リソース情報プールを取得する
     * @return リソース情報プール
     */
    inline static ResInfoPool* getResInfoPool()
    {
        return Singleton<ResInfoPool>::getInstance();
    };
    
private:
    
    /**
     * @brief 初期化する
     */
    void init();
    
};

NS_END_MANAGER

#endif
