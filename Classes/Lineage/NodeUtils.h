#pragma once

NS_NC_BEGIN

class NodeUtils final
{
public:
	static cocos2d::Node* findNodeByTagNullable(int tag) { /* �±׷� �ڽĳ�带 ã�� �Լ�*/ return nullptr;  }
	static cocos2d::Node* initNode(cocos2d::Node* pNode, std::string_view dataName) { /* �����͸� ������ ��带 �ʱ�ȭ ���ִ� �Լ� */ return nullptr; }
	static cocos2d::Node* makeNode(std::string_view dataName) { return nullptr; }
	static void changeView(cocos2d::Node* pNode) { /* ȭ�� ��ȯ */ }

private:
	// ������ ���� ��üȭ �뵵�� �ƴ�
	NodeUtils() = delete;
};

NS_NC_END