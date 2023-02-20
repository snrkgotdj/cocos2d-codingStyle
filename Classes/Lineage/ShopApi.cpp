#include "pch.h"
#include "ShopApi.h"

USING_NS_NC

#define API_SERVER "api/server"

cocos2d::network::HttpRequest* ShopApi::get(std::function<void()> success, std::function<void()> fail)
{
	using namespace cocos2d::network;

	std::ostringstream oss;
	oss << API_SERVER << "/shop";

	HttpRequest* pRequest = new HttpRequest;
	pRequest->setUrl(oss.str());
	pRequest->setRequestType(cocos2d::network::HttpRequest::Type::GET);

	//여기까지 구현하려면 너무 오래걸려서 생략.... 알아서 호출된다고 가정
	//pRequest->getCallback(success, fail);

	return nullptr;
}

cocos2d::network::HttpRequest* ShopApi::buy(int itemNo, std::function<void()> success, std::function<void()> fail)
{
	using namespace cocos2d::network;

	std::ostringstream oss;
	oss << API_SERVER << "/shop/buy/" << itemNo;

	HttpRequest* pRequest = new HttpRequest;
	pRequest->setUrl(oss.str());
	pRequest->setRequestType(cocos2d::network::HttpRequest::Type::POST);

	//여기까지 구현하려면 너무 오래걸려서 생략.... 알아서 호출된다고 가정
	//pRequest->getCallback(success, fail);

	return nullptr;

}