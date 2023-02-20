#pragma once

NS_NC_BEGIN

class ShopMainData;

class ShopLayer : public cocos2d::Layer
{
private:
	std::string_view dataName_;
	std::shared_ptr<ShopMainData> pInfo_;

	int curCategory_;

public:
	static void changeView();

private:
	static ShopLayer* innerCreate(std::string_view dataName);
	bool init(std::string_view dataName);

public:
	void refresh();
	void refreshTab();
	void refreshItemList();

private:
	void onTabClick(int categoryNo);
	void onItemClick(int itemNo);
};

NS_NC_END
