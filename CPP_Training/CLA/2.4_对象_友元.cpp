#include <iostream>
using namespace std;
//友元 friend：让类外对象可以访问类中的私有成员
//三种实现方式：全局函数做友元、类做友元、成员函数做友元
class T1;
class T3 {
public:
	T3(int a, int b);
	T3() = default;
	void visit();
private:
	T1 *T;
};

class T1{
	friend void func(T1 &_t);
	friend class T2;
	friend void T3::visit();
public:
	T1(int a,int b) :a(a), b(b) {};
	T1() :T1(1, 1) {};
private:
	int a;
	int b;
	int sum() { return a + b; }
};
//1.成员函数被做友元的类(T3)应定义在前,T1应声明在前
//2.T3中用到T1的函数应先声明，后定义在T1之后
T3::T3(int a, int b) {
	T = new T1(a, b);
}
void T3::visit(){
	cout << T->sum() << endl;
}


class T2 {
public:
	T2(int a,int b) {
		T = new T1(a,b);
	}
	T2() = default;
	void visit() {
		cout << T->sum() << endl;
	}
private:
	T1 *T;
};


void func(T1 &_t) {
	cout << _t.sum() << endl;
}


void test1() {//全局函数做友元
	T1 t;
	func(t);
}
void test2() {//类做友元
	T2 t(1,-1);
	t.visit();
}
void test3() {//成员函数做友元
	T3 t(2, 2);
	t.visit();
}
int main() {
	test1();
	test2();
	test3();
}
