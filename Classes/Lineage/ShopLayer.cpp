#include "pch.h"
#include "ShopLayer.h"

#include "ShopService.h"
#include "ShopDefine.h"
#include "ShopData.h"

USING_NS_NC
USING_NS_SHOP

void ShopLayer::changeView()
{
	// 상점을 그리기위해 필요한 정보 요청
	ShopService::requestShopMain([]() {
		// 요청 성공 화면 전환
		cocos2d::Node* pNode = innerCreate(ui::shopMain);
		NodeUtils::changeView(pNode);
	});	
}

ShopLayer* ShopLayer::innerCreate(std::string_view dataName)
{
	ShopLayer* pRet = new(std::nothrow) ShopLayer();
	if (pRet && pRet->init(dataName))
	{
		pRet->autorelease();
		return pRet;
	}

	return nullptr;
}

bool ShopLayer::init(std::string_view dataName)
{
	if (Layer::init() == false)
		return false;

	dataName_ = dataName;

	refresh();

	return true;
}

void ShopLayer::refresh()
{
	pInfo_ = ShopData::getInst()->getShopMainData();

	removeAllChildren();

	NodeUtils::initNode(this, dataName_);

	refreshTab();

	refreshItemList();
}

void ShopLayer::refreshTab()
{
	Node* pContainer = NodeUtils::findNodeByTagNullable(SHOP_TAB_CONTAINER_TAG);
	if (nullptr == pContainer)
		return;

	pContainer->removeAllChildren();

	for (int categoryNo : pInfo_->vecCategory)
	{
		Node* pNode = NodeUtils::makeNode(ui::shopItemTab + std::to_string(categoryNo));
		if (nullptr == pNode)
			continue;
		
		// 탭 클릭시 콜백 연결함수가 있다고 가정
		// pNode->setCallback(CC_CALLBACK_0(ShopLayer::onTabClick, this, categoryNo));

		pContainer->addChild(pNode);
	}
}

void ShopLayer::refreshItemList()
{
	Node* pContainer = NodeUtils::findNodeByTagNullable(SHOP_ITEM_SLOT_CONTAINER_TAG);
	if (nullptr == pContainer)
		return;

	pContainer->removeAllChildren();

	for (int itemNo : pInfo_->vecItem)
	{
		Node* pNode = NodeUtils::makeNode(ui::shopItemName + std::to_string(itemNo));
		if (nullptr == pNode)
			continue;

		// 아이템 클릭시 콜백 연결함수가 있다고 가정
		// pNode->setCallback(CC_CALLBACK_0(ShopLayer::onItemClick, this, itemNo));

		pContainer->addChild(pNode);
	}
}

void ShopLayer::onTabClick(int categoryNo)
{
	curCategory_ = categoryNo;
	refreshItemList();
}

void ShopLayer::onItemClick(int itemNo)
{
	// 구매요청
	ShopService::requestBuy(itemNo, [this]() {
		// 요청 성공 후 화면 갱신
		this->refresh();
	});

}
