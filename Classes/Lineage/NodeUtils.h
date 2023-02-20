#pragma once

NS_NC_BEGIN

class NodeUtils final
{
public:
	static cocos2d::Node* findNodeByTagNullable(int tag) { /* 태그로 자식노드를 찾는 함수*/ return nullptr;  }
	static cocos2d::Node* initNode(cocos2d::Node* pNode, std::string_view dataName) { /* 데이터를 가져와 노드를 초기화 해주는 함수 */ return nullptr; }
	static cocos2d::Node* makeNode(std::string_view dataName) { return nullptr; }
	static void changeView(cocos2d::Node* pNode) { /* 화면 전환 */ }

private:
	// 생성자 삭제 객체화 용도가 아님
	NodeUtils() = delete;
};

NS_NC_END