#include <iostream>
using namespace std;
//浅拷贝，简单的值拷贝
//深拷贝，在堆区重新申请空间，进行拷贝
//深拷贝实现方式：1、重构拷贝构造函数；2、重构operator

class Person{
public:
	Person() = default;
	Person(int a, int b);
	//1、重构拷贝构造函数；用于初始化
	Person(const Person &p);
	//2、重构operator,用于赋值
	Person& operator=(const Person &_p);
	friend ostream& operator<<(ostream &cout, const Person &_p);
	~Person() {
		if (b != nullptr) {
			delete b;
			b = nullptr;
		}
		cout << "堆区指针已释放" << endl;
	}
	int get_A() const{
		return a;
	}
	int* get_B() const {
		return b;
	}
private:
	int a;
	int* b;
};
Person::Person(int a, int b) {
	this->a = a;
	this->b = new int(b);
}
Person::Person(const Person &p) {
	a = p.a;
	b = new int(*p.b);//在堆区重新申请空间，进行深拷贝
}
Person& Person::operator=(const Person &_p) {
	a = _p.a;
	if (b != nullptr) {
		delete b;
		b = nullptr;
	}
	b = new int(*_p.b);////在堆区重新申请空间，进行深拷贝
	return *this;
}
ostream& operator<<(ostream &cout, const Person &_p) {
	cout << "a = " << _p.a <<"\t&b = "<<_p.b<< "\tb = " << *_p.b << endl;
	return cout;
};

void test1() {
	Person p1(1, 2);
	Person p2(p1);
	Person p3;
	Person p4;
	p4= p3 = p2;
	cout << p1 << p2 << p3 <<p4<< endl;
}
int main() {
	test1();
}