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
class Queue {//��ʽ�洢�Ķ���
private:
	enum { size_Q = 10 };
	struct Node{
		Customer data;
		Node *next;
	};
	Node *front;//ͷ��㣬�������ݣ���front->nextΪ��Ԫ�ڵ�
	Node *rear;//βָ�룬ָ��ĩβ
	int nums;
public:
	Queue();
	~Queue();
	bool isEmpty() const{ return nums == 0; };//�ж϶����Ƿ�Ϊ��
	bool isFull() const{ return nums == size_Q; };//�ж϶�����Ϊ��
	int num_Count() const { return nums; };//��ǰ�ڶ����еĶ���ĸ���
	Queue& enQueue(const Customer &_c);//���
	Queue& deQueue();//����
	friend ostream& operator<<(ostream& os, const Queue& _q);
};