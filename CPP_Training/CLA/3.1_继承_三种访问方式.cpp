#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
//基类中private属性和方法，以任何方式继承，在派生类中不可访问
//基类中protected属性和方法，以公有或保护方式继承，在派生类中可以访问，类外不可访问
//基类中public属性和方法，以公有方式继承，则在派生类中和外部均可访问，否则只能在派生类中访问
class T {
private:
	string a;
	int b;
public:
	T(string _a = "none", int _b = 0) :a(_a), b(_b) {}
	string get_a() { return a; }
	int get_b() { return b; }
};

class T1 :public T {
private:
	double c;
public:
	T1(string _a= "none", int _b= 0, double _c = 0) :T(_a, _b), c(_c) {}
	double get_c() { return c; }
};
class T2 :protected T1 {
private:
	bool d;
public:
	T2(string _a = "none", int _b = 0, double _c = 0, bool _d=0) :T1(_a, _b, _c), d(_d) {}
	bool get_d() { return d; }
	void func1() {
		cout << get_a() << endl;
		cout << get_b() << endl;
		cout << get_c() << endl;
	}
};

class T3 :private T2 {
private:
	long e;
public:
	T3(string _a = "none", int _b = 0, double _c = 0, bool _d = 0, long _e = 0) :T2(_a, _b, _c, _d) {}
	long get_e() { return e; }
	void func2() {
		cout << get_a() << endl;
		cout << get_b() << endl;
		cout << get_c() << endl;
		cout << get_d() << endl;
	}
};
class T4 :public T3 {
private:
	float f;
public:
	//int a=get_d();//该方法在T3中已设为private，故T4无法访问

};
int main() {
	T3 a;//私有继承，基类private、protected、public ->private
	//以下方法均变为private
	//a.get_a();
	//a.get_b();
	//a.get_c();
	//a.get_d();
	//a.func1();
	a.func2();
	T2 b;//保护继承，基类private->派生private,基类public->派生protected
	//以下方法均变为protected
	//b.get_a();
	//b.get_b();
	//b.get_c();
	b.func1();
	T1 c;//公有继承，基类private->派生private，基类public->派生public
	cout << c.get_a() << endl;
	cout<<c.get_b()<<endl;
}