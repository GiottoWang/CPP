#pragma once
#include <iostream>
//���а����������Եģ���Ҫ�Զ��忽�����캯���Լ���������
class T {
private:
	int *a1;
	int a2;
public:
	T(int _a1 = 0, int _a2 = 0) ;//Ĭ�ϲ�����������д��֮�󣬶���ʱ��Ҫ��д�� �мǣ�����
	T(const T& _t);
	virtual ~T();
	T& operator=(const T& _t);
	friend std::ostream& operator<<(std::ostream& os, const T& _t);
};

class T1 :public T {
private:
	int *b;
public:
	T1(int _a1 = 0, int _a2 = 0, int _b = 0);
	T1(const T& _t, int _b = 0);
	T1(const T1& _T);
	virtual ~T1();
	T1& operator=(const T1& _t);
	friend std::ostream& operator<<(std::ostream& os, const T1& _t);
};
