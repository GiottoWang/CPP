#pragma once
#include<string>
#include <iostream>
using std::string;
namespace cla {
	//类模板没有自动类型推导
	//类模板的模板参数列表中可以有默认参数,默认参数必须放在列表末尾
	template<class T1 = string, class T2 = int>
	class Base {
	private:
		T1 a;
		T2 b;
	public:
		Base() = default;
		explicit Base(T1 _a, T2 _b) :a(_a), b(_b) {}
		T1 get_a() { return a; };
		T2 get_b() { return b; };
		Base& operator=(const Base& _b);//类内声明，类外实现
		friend std::ostream& operator<<(std::ostream& os,  const Base& _b) {//类模板的友元函数尽量类内实现，类外实现很麻烦
			os << "a = "<<_b.a<<"  b = "<<_b.b<<std::endl;
			return os;
		};
	};
	//派生类继承类模板时
	//1.指定基类模板类型
	class Derive1 :public Base<string, int> {
	public:
		void func() {
			std::cout << "Base的派生类：Derive1" << std::endl;
		}

	};
	//2.派生类也做类模板
	template<class T3, class T1 = string, class T2 = int>
	class Derive2:public Base<T1,T2>{
		T3 c;
	public:
		void func() {
			std::cout << "Base的派生类：Derive2" << std::endl;
		}
	};
	//成员函数的类外实现,注意加上模板参数列表
	//成员函数在编译阶段并不生成，被调用后才生成，与普通类不同
	template<class T1, class T2>
	Base<T1, T2>& Base<T1, T2>::operator=(const Base& _b) {
		a = _b.a;
		b = _b.b;
		return *this;
	}

	//类模板对象做函数参数
	//1.指定传入类型
	//2.参数模板化
	//3.类模板化
	//1.指定传入类型
	void swap1(Base<string, int> &_b1, Base<string, int>&_b2) {
		Base<string, int> temp;
		temp = _b1;
		_b1 = _b2;
		_b2 = temp;
		std::cout << "swap1的调用" << std::endl;
	}
	//2.参数模板化
	template<class T1, class T2>
	void swap2(Base<T1, T2>&_b1, Base<T1, T2>&_b2) {
		Base<T1, T2> temp;
		temp = _b1;
		_b1 = _b2;
		_b2 = temp;
		std::cout << "swap2的调用" << std::endl;
	}
	//3.类模板化
	template<class T>
	void swap3(T&_b1, T&_b2) {
		//调用了重载运算符=
		T temp;
		temp = _b1;
		_b1 = _b2;
		_b2 = temp;
		std::cout << "swap3的调用" << std::endl;
	}
}
