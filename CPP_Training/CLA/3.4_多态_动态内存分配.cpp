#include"3.4_多态_动态内存分配.h"
using std::cout;
using std::endl;
//注意事项
//1.派生类的拷贝构造函数
//2.派生类的运算符重构函数：1）成员函数；2）友元函数

//base class T
T::T(int _a1, int _a2) :a1(new int(_a1)), a2(_a2) 
{ cout << "T的有参构造函数调用" << endl; }
T::T(const T& _t) {
	a1 = new int(*_t.a1);
	a2 = _t.a2;
	cout << "T的拷贝构造函数调用" << endl;
};
T::~T() {
	if (a1 != nullptr) {
		delete a1;
	}
	cout << "T的析构函数调用" << endl;
}
T& T::operator=(const T& _t) {
	if (a1 != nullptr)delete a1;
	a1 = new int(*_t.a1);
	a2 = _t.a2;
	return *this;
};
std::ostream& operator<<(std::ostream& os, const T& _t) {
	if (_t.a1 == nullptr) os << "a1 = null" << endl;
	else
		os << "a1 = " << *_t.a1 << endl;
	os << "a2 = " << _t.a2 << endl;
	return os;
};

//class T1
T1::T1(int _a1, int _a2, int _b) :T(_a1, _a2), b(new int(_b)) {
	cout << "T1的有参构造函数1调用" << endl;
};
T1::T1(const T& _t, int _b):T(_t),b(new int (_b)){
	cout << "T1的有参构造函数2调用" << endl;
}
//注意点1
T1::T1(const T1& _t) :T(_t){//直接把基类的拷贝构造传进来，基类引用或指针可以指向派生类对象
	b = new int(*_t.b);
	cout << "T1的拷贝构造函数调用" << endl;
}
T1::~T1() {
	if (b != nullptr) delete b;
	cout << "T1的析构函数调用" << endl;
}
//注意点2.1
T1& T1::operator=(const T1& _t) {
	T ::operator=(_t);//基类引用或指针可以指向派生类对象
	b = new int(*_t.b);
	return *this;
};

//注意点2.2
std::ostream& operator<<(std::ostream& os, const T1& _t) {
	os << (const T&)_t;//但类外不可以，所以需要强制类型转换
	if(_t.b==nullptr)  os<< "b = null" << endl;
	else
	{
		os << "b = " << *_t.b << endl;
	}
	return os;

};
