#pragma once

NS_NC_BEGIN

// 이 클래스는 잘 구현됬다고 가정...
template <typename T>
class Singleton
{
	

public:
	static T* pInst;

public:
	static T* getInst() { return pInst; }
}; 

template <typename T>
T* Singleton<T>::pInst = nullptr;

// 임시로 만든 상점 데이터
struct ShopMainData
{
	std::vector<int> vecCategory;
	std::vector<int> vecItem;

}; using ShopMainDataPtr = std::shared_ptr<ShopMainData>;

class ShopData : public Singleton<ShopData>
{
private:
	ShopMainDataPtr pShopMainData_;

public:
	void setShopMainData(const ShopMainDataPtr& pData) { pShopMainData_ = pData; };

public:
	ShopMainDataPtr getShopMainData() inline { return pShopMainData_; }

};

NS_NC_END