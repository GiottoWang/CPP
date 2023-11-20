#include"3.4_多态_动态内存分配.h"
#include <iostream>
using namespace std;
void test1() {
	T t1(1, -1);
	T t2(t1);
	cout << t1 << endl;
	cout << t2 << endl;
}
void test2() {
	T t1(1, 1);
	T1 t2(t1, 0);//走T的拷贝构造函数
	T1 t3(99, 77, 88);//走T的有参构造函数
	cout << t1 << endl;
	cout << t2 << endl;
	cout << t3 << endl;
}
void test3() {
	T1 t1(1, 2, 3);
	T1 t2(t1);//先走T的拷贝，再走T的拷贝
	T1 t3;//默认构造
	t3 = t2;
	cout << t1 << endl;
	cout << t2 << endl;
	cout << t3 << endl;
}

int main() {
	//test1();
	//test2();
	test3();
}