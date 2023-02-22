#include "pch.h"
#include "LineageScene.h"

#include "ShopLayer.h"

USING_NS_NC

LineageScene* LineageScene::createNullable()
{
    LineageScene* pRet = new(std::nothrow) LineageScene();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet; 
    }

	return nullptr;
}

bool LineageScene::init()
{
    if (false == Scene::init())
        return false;

    // 진입과 동시에 상점으로 진입
    ShopLayer::changeView();

    return false;
}


