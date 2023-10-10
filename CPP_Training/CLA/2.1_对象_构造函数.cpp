#include <iostream>
#include <string>
using namespace std;
//析构函数：销毁对象前，执行清理工作，且没有数据类型。
//构造函数:创建对象时，为对象的成员属性赋值，且没有数据类型。
//构造函数分为 无参、有参和拷贝
//拷贝构造函数（浅拷贝）的使用时机：1、使用一个现存的对象初始化新对象；2、以值传递做参数；3、一值传递做返回值
//构造函数的调用方式：括号法、显示法、隐式转换法
//自定义有参后，编译器不会提供默认无参构造
//自定义拷贝后，编译器不会提供默认有参以及无参构造
class Person{
public:
	//分类
	Person() {};//无参构造
	Person(int a):a(a) {};//有参构造，初始化列表
	Person( const Person &P) { a=P.get_A(); //常对象只能调用常函数
	};//拷贝构造
	~Person() {};//析构函数
	int get_A() const {//常对象只能调用常函数
		return a;
	}
private:
	int a;
};
//调用方式
void test1() {
	//普通
	Person p1(1);//括号法
	Person p2 = Person(2);//显示法
	Person p3 = { 3 };//隐式转换法
	cout << p1.get_A()<<' ' << p2.get_A() << ' ' << p3.get_A() << endl;
}
//浅拷贝
void test2() {//1
	Person p1(1);
	Person p2(p1);
	cout<< p1.get_A() << ' ' << p2.get_A() << endl;
}

void test3(Person p) {//2
	cout << "test" << endl;
}
void test4() {//2
	Person p1(1);
	test3(p1);
}
Person test5() {//3
	Person  p1(1);
	return p1;
}
int main() {
	test1();
	test2();
	test4();
	cout << test5().get_A();
}