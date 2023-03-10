#include "pch.h"
#include "ShopService.h"

#include "NodeUtils.h"

#include "ShopApi.h"
#include "ShopData.h"
#include "ShopDefine.h"

USING_NS_NC
USING_NS_SHOP

void ShopService::requestShopMain(const std::function<void()>& func)
{
	cocos2d::network::HttpRequest* pRequest = ShopApi::get([func](/*const JSONNode& node*/) {		
		// 성공 콜백
		// 데이터 저장 및 갱신
		ShopMainDataPtr pData = std::make_shared<ShopMainData>(/*node*/);
		ShopData::getInst()->setShopMainData(pData);

		// 각 레이어에서 전달받은 콜백을 실행
		if (func)
		{
			func();
		}

	}, ShopService::processError);

	// 이렇게 해서 api를 전달하는 객체가 있다고 가정
	//ApiServer::getInstance()->send(pRequest);
}

void ShopService::requestBuy(int itemNo, const std::function<void()>& func)
{
	cocos2d::network::HttpRequest* pRequest = ShopApi::buy(itemNo, [func](/*const JSONNode& node*/) {
		// 획득한 보상 팝업 띄움
		// Popup* pPopup = ReceieveRewardPopup::create(itemNo);
		// pPopup->show();

		// 각 레이어에서 전달받은 콜백을 실행
		if (func)
		{
			func();
		}
	}, ShopService::processError);

	// 이렇게 해서 api를 전달하는 객체가 있다고 가정
	//ApiServer::getInstance()->send(pRequest);
}

void ShopService::processError(/*std::string errorCode*/)
{
	if (/*errorCode == "ERROR_SOMETHING"*/ true)
	{
		// 에러처리
	}

}
