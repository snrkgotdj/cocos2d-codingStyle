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

	//������� �����Ϸ��� �ʹ� �����ɷ��� ����.... �˾Ƽ� ȣ��ȴٰ� ����
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

	//������� �����Ϸ��� �ʹ� �����ɷ��� ����.... �˾Ƽ� ȣ��ȴٰ� ����
	//pRequest->getCallback(success, fail);

	return nullptr;

}