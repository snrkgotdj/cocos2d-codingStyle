#pragma once

NS_NC_BEGIN

class ShopApi final
{
public:
	static cocos2d::network::HttpRequest* get(std::function<void()> success, std::function<void()> fail);
	static cocos2d::network::HttpRequest* buy(int itemNo, std::function<void()> success, std::function<void()> fail);


private:
	ShopApi() = delete;
};


NS_NC_END