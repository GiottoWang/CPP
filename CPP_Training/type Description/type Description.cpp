#include <iostream>
using namespace std;

int main()
{
	const int c1 = 0, &cr = c1;
	auto a = c1;// a int
	auto b = cr;// b int
	auto c = &c1;// c const int*
	const auto d = c1;//const int
	auto &e = c1;//const int reference
	const auto &f = 0;//const int reference,但不能写成auto f=0，这样写左值必须为变量
	/*
	使用 auto a b; 定义a b时，必须保证a b的类型相同
	*/
	auto m= 1;
	auto n = 2.22;
	//decltype,返回操作数数据类型
	/*
	1.decltype(变量)，返回变量的类型
	2.decltype(表达式)，返回表达式值的类型
	3.decltype(函数)，返回函数返回值的类型
	*/
	decltype(cr) x=0;//cr为 const int reference 必须 所以X必须赋初值
	decltype(c) y;
	decltype(*c) z = 0;//解引用后，为reference

	cout << a << b << *c << endl;
	cout << m + n << endl;
	cout << x<<endl;
}
