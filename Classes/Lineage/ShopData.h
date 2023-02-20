#pragma once

NS_NC_BEGIN

// �� Ŭ������ �� ������ٰ� ����...
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

// �ӽ÷� ���� ���� ������
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