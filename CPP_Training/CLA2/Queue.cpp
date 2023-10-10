#include"Queue.h"
#include <iostream>
#include<cstdlib>
//Customer
void Customer::set(int when) {
	arrive = when;
	processtime = std::rand() % 3 + 1;//0~3的随机数
}
Customer::Customer(int when) {
	arrive = when;
	processtime = std::rand() % 3 + 1;//0~3的随机数
}
ostream& operator<<(ostream& os, const Customer& _c) {
	os << _c.arrive << "," << _c.processtime << std::endl;
	return os;
}
//Queue
Queue::Queue() {
	rear =front =new Node;
	front->next = nullptr;
	nums = 0;
}
Queue::~Queue() {
	Node *p;
	while (front!= nullptr) {
		p = front;
		front = front->next;
		delete p;
	}
}
Queue& Queue::enQueue(const Customer &c) {
	if (!isFull()) {//新建节点
		Node *p = new Node;
		p->data = c;
		p->next = nullptr;
		//插入
		rear->next = p;
		rear = p;
		nums++;
	}
	return *this;
}
Queue& Queue::deQueue() {
	if (!isEmpty()) {
		Node *p;
		p = front->next;
		front->next = p->next;
		delete p;
		nums--;
	}
	return *this;
}

ostream& operator<<(ostream& os, const Queue& _q) {
	if (_q.isEmpty()) {
		os << "The Queue is null.";
		return os;
	}
	else {
		Queue::Node *p = _q.front->next;
		while (p != nullptr) {
			os << p->data;
			p = p->next;
		}
		return os;
	}
}