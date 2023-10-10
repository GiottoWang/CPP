#pragma once
#include<iostream>
#include<string.h>
using std::ostream;
class Customer{
	int arrive;
	int processtime;
public:
	Customer() :arrive(0), processtime(0) {};
	Customer(int when);
	void set(int when);
	int get_when() const{ return arrive; }
	int get_Ptime() const{ return processtime; }
	friend ostream& operator<<(ostream& os, const Customer& _c);
};
class Queue {//链式存储的队列
private:
	enum { size_Q = 10 };
	struct Node{
		Customer data;
		Node *next;
	};
	Node *front;//头结点，不存数据，即front->next为首元节点
	Node *rear;//尾指针，指向末尾
	int nums;
public:
	Queue();
	~Queue();
	bool isEmpty() const{ return nums == 0; };//判断队列是否为空
	bool isFull() const{ return nums == size_Q; };//判断队列是为满
	int num_Count() const { return nums; };//当前在队列中的对象的个数
	Queue& enQueue(const Customer &_c);//入队
	Queue& deQueue();//出队
	friend ostream& operator<<(ostream& os, const Queue& _q);
};