#include<iostream>
//多态的优点
//1.结构清晰
//2.可读性强
//3.利于扩展
class ABC_Calculator {
	//拥有纯虚函数（包括纯析构函数）的类称为Abstract Basic Class
	//ABC不可创建对象
private://基本属性对派生类隐藏，但提供只读访问接口
	int a;
	int b;
public:
	ABC_Calculator(const int &_a=0, const int &_b=0) :a(_a), b(_b) {};
	int get_a() { return a; };
	int get_b() { return b; };
	virtual int getResult() = 0;//纯虚函数，即虚函数 = 0
};
class Plus :public ABC_Calculator {
public:
	Plus(const int &_a = 0, const int &_b = 0) :ABC_Calculator(_a, _b) {};
	int getResult() { return get_a()+ get_b(); };
};
class Times :public ABC_Calculator {
public:
	Times(const int &_a = 0, const int &_b = 0) :ABC_Calculator(_a, _b) {};
	int getResult() {return get_a() *get_b();};
};
class Minus :public ABC_Calculator {
public:
	Minus(const int &_a = 0, const int &_b = 0) :ABC_Calculator(_a, _b) {};
	int getResult() { return get_a() - get_b(); };
};
class Divided :public ABC_Calculator {
public:
	Divided(const int &_a = 0, const int &_b = 0) :ABC_Calculator(_a, _b) {};
	int getResult(){ return get_a() / get_b();};
};

int main() {
	using std::cout;
	using std::endl;
	ABC_Calculator *x ;//基类指针可以指向派生类对象
	x = new Plus(1,1);
	cout <<x->get_a()<<" + "<<x->get_b()<<" = "<< x->getResult() << endl;
	delete x;
	x = new Times(2, 2);
	cout << x->get_a() << " * " << x->get_b() << " = " << x->getResult() << endl;
	delete x;
	x = new Divided(9, 3);
	cout << x->get_a() << " / " << x->get_b() << " = " << x->getResult() << endl;
	delete x;
	x = new Minus(2, 7);
	cout << x->get_a() << " - " << x->get_b() << " = " << x->getResult() << endl;
	delete x;
}
