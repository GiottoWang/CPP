#include "函数模板.hpp"
#include "类模板.hpp"
#include <iostream>

void test(void(*p)()) {
	p();
}

//test0 函数模板
//两种调用方法
void test01() {
	char a = 'b';
	char b = 'a';
	int c = 10;
	func::Swap(a, b);//自动类型推导
	std::cout << "a = "<<a <<"\tb = "<< b << std::endl;
	std::cout<<"a + b = "<<func::plus<int>(a, b)<<std::endl;//显式指定类型，且发生隐式类型转换
	std::cout << "a + b + c = " << func::plus<int>(a,b,c) << std::endl;//调用重载函数

}
//函数模板与普通函数
void test02() {
	int a = 7;
	int b = -7;
	func::Swap(a, b);
	std::cout << "a = " << a << "\tb = " << b << std::endl;
	func::Swap<>(a, b);//使用空模板参数列表强制调用模板函数
	std::cout << "a = " << a << "\tb = " << b << std::endl;
}
//特殊数据类型如何调用函数模板
void test03() {
	func::T t1('a', 10);
	func::T t2('z', 99);
	//通过运算符重载实现
	func::Swap(t1, t2);
	std::cout << "t1.a = " << t1.get_a() << "  t1.b = " << t1.get_b() << std::endl;
	std::cout << "t2.a = " << t2.get_a() << "  t2.b = " << t2.get_b() << std::endl;
	//通过实例化函数模板实现
	std::cout << "t1.a + t2.a = " << func::plus(t1, t2).get_a() << "  t1.b + t2.b = " << func::plus(t1, t2).get_b() << std::endl;
}

//test1 类模板

void test11() {
	cla::Base<int, string> a(10, "Tom");
	cla::Base<string, int> b("Jerry", 8);
	std::cout << a << b;
	//继承
	cla::Derive1 c;
	c.func();
	cla::Derive2<int, string, bool> d;
	d.func();
}
void test12() {
	cla::Base<string, int> a("Tom",18);
	cla::Base<> b("Jerry", 10);//使用默认模板参数
	std::cout << a << b;
	cla::swap1(a, b);
	std::cout << a << b;
	cla::swap2<string,int>(a, b);
	std::cout << a << b;
	cla::swap3(a, b);
	std::cout << a << b;
}
int main()
{
	test(test12);
}
