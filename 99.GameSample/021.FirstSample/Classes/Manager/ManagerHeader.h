//
//  ManagerHeader.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/17.
//
//

#ifndef _21_FirstSample_ManagerHeader_h
#define _21_FirstSample_ManagerHeader_h

// シーン遷移履歴
#define USING_NS_SCENE_HISTORY                      using namespace Manager::History::Scene;
#define NS_BEGIN_SCENE_HISTORY                      namespace Manager {                              \
                                                        namespace History {                          \
                                                            namespace Scene {
#define NS_END_SCENE_HISTORY                                }                                        \
                                                        }                                            \
                                                    }

#endif
