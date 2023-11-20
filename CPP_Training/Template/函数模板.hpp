#pragma once
#include <iostream>
namespace func{
	//函数模板的两种调用方法
	//1.自动类型推导
	//2.显式指定类型，使用此调用方法时，可以发生隐式类型转换
	template <typename T>
	void Swap(T&a, T&b) {//引用做参数时，不能发生类型转换，强制与隐式都不行
		T temp = a;
		a = b;
		b = temp;
		std::cout << "函数模板调用" << std::endl;
	}
	//与普通函数共存时，优先调用普通函数
	void Swap(int &a, int &b) {
		int temp = a;
		a = b;
		b = temp;
		std::cout << "普通函数调用" << std::endl;
	}

	//函数模板可以重载
	template <typename T>
	T plus(T a, T b) {
		std::cout << "函数模板调用" << std::endl;
		return a + b;
	}
	template <typename T>
	T plus(T a, T b, T c) {
		std::cout << "模板重载调用" << std::endl;
		return a + b + c;
	}
	//函数模板的局限性（不能处理特殊数据类型）的解决方法
	//1.运算符重载
	//2.实例化模板
	class T {
		char a;
		int b;
	public:
		T(const char &_a = ' ', const int&_b = 0) :a(_a), b(_b) {};
		//void set_a(const char &_a) { a = _a; }
		//void ste_b(const int &_b) { b = _b; }
		char get_a() const { return a; }
		int get_b() const { return b; }
		T& operator=(T& _t) {//1.运算符重载
			a = _t.get_a();
			b = _t.get_b();
			return *this;
		}
	};

	template <>
	T plus(T a, T b) {//2.实例化模板
		T t(a.get_a() + b.get_a(), a.get_b() + b.get_b());
		return t;
	}

}
