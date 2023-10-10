#include <iostream>
using namespace std;
//static 静态成员
//static 成员变量，在编译阶段分配内存；数据所有对象共享；类内声明，类外定义	
//static 成员函数，数据所有对象共享；只能访问static变量
//const  常量修饰符
//const 常函数，不可以修改成员属性（mutable除外）
//const 常对象，只能调用常函数
//this 指针的本质是顶层const，常量指针，this指向的地址不能改变，但其指向对象的值可以通过指针访问改变

class T {
public:
	static int a;
	mutable int c;
	int get_B() {
		return b;
	}
	static int  get_BB(int _b) {//只能访问static变量
		 //c = 1;不能访问
		b = _b;
		return b;
	}
	void fun() const {//换函数中不可以修改成员属性
		a = 50;//静态变量可以
		c = 100;//mutable可以
		//d = 500; 本质 this->d 为T* const this，外加了一个const修饰 
		//变为 const T* const this 指针：底层+顶层指针 this指向的地址和对应的值都不能改变
		cout << a << c << endl;
	}
private:
	static int b;//作用在私有域下的静态成员类外同样被封装
	int d;
};
//类外初始化
int T::a = 1;
int T::b = -1;
void test1() {//数据共享
	T t1,t2;
	cout << t1.a << endl;
	t2.a=2;
	cout << t1.a << endl;
}
void test2() {//静态成员变量不属于任一对象
	//通过对象访问
	T t1;
	cout << t1.a << endl;
	cout << t1.get_B() << endl;
	//通过类名访问
	cout << T::a << endl;
	cout << T::get_BB(-3) << endl;//静态函数的调用
}
void test3() {//常对象只能调用常函数
	const T t1;
	t1.a = 1000;
	t1.fun();
	//t1.get_B(); 不能调用非常函数
}
int main() {
	test1();
	test2();
	test3();
}