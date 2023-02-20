#pragma once

NS_NC_BEGIN

class ShopService
{
public:
	static void requestShopMain(const std::function<void()>& func);
	static void requestBuy(int itemNo, const std::function<void()>& func);

private:
	static void processError();

};

NS_NC_END