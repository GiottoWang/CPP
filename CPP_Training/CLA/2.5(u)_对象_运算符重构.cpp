#include<iostream>
#include"2.5_对象_运算符重构.h"
using namespace std;
void test1() {
	
	Time t1;
	cout << t1;
	t1.add_H(3);
	cout << t1;
	t1.add_M(100);
	cout << t1;
	cout << t1 * 7;
	
}
void test2() {
	
	Time t1(9, 55);
	Time t2(0, 45);
	cout << t1<<t2<<t1+t2<<t1-t2<<t2-t1;

}

void test3() {
	Time t1(23, 45);
	Time t2(5, 36);
	Time t3(t1);
	cout << (t1 < t2) << (t1 == t3) << endl;
}
void test4() {
	Time *t1 = new Time(24, 23);
	cout << *t1 << endl;
	delete t1;
}
int main() {
	cout << "the beginning of test1:\n" << endl;
	test1();
	cout << "-----------------------\n"<< "the beginning of test2:\n" << endl;
	test2();
	cout << "-----------------------\n" << "the beginning of test3:\n" << endl;
	test3();
	test4();
	char a[5];
	strcpy_s(a, "c++");

}