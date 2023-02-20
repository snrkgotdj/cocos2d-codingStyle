#pragma once

#include "ncsoft.h"

#define NS_SHOP_BEGIN namespace shop {	
#define NS_SHOP_END	}		
#define USING_NS_SHOP using namespace shop;

NS_NC_BEGIN

namespace shop
{
	namespace ui
	{
		const char* shopMain = "shopMain";
		const char* shopItemName = "shopItemName";
		const char* shopItemTab = "shopItemTab";
	}
	
	enum tag
	{
		SHOP_TAB_CONTAINER_TAG,
		SHOP_ITEM_SLOT_CONTAINER_TAG,
	};
}


NS_NC_END