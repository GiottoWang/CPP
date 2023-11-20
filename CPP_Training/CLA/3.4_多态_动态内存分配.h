#pragma once
#include <iostream>
//类中包含堆区属性的，需要自定义拷贝构造函数以及析构函数
class T {
private:
	int *a1;
	int a2;
public:
	T(int _a1 = 0, int _a2 = 0) ;//默认参数在声明是写了之后，定义时不要再写了 切记！！！
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
