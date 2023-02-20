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

    ShopLayer::changeView();

    return false;
}


