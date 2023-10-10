#include <iostream>
#include <cmath>
#include <string>
using namespace std;
//对象：属性+行为。封装成一个整体，隐藏实现细节，仅对外提供访问的接口
//属性:成员变量，行为：成员函数

//访问权限
//public:      类内可以访问  类外可以访问
//protected:   类内可以访问  内外不可访问  可以继承
//private:     内类可以访问  内外不可访问  不可继承

//public 默认权限 private
//struct 默认权限 public


constexpr double pi = 3.14;
//constexpr 只能定义编译期常量，⽽ const 可以定义编译期常量，也可以定义运⾏期常量。
//二者修饰的变量在定义时必须初始化。
//编译期常量：在编译器就能得到值。
//运行期常量：在运行时才能得到值。
class Point {
public:
	Point() = default;
	Point(double x, double y, string name) :x(x), y(y), name(name) {};
	Point(double x, double y) :Point(x, y, "p") {};
	void set_P(double x, double y) {
		this->x = x;
		this->y = y;
	}
	double get_X() {
		return x;
	}
	double get_Y() {
		return y;
	}
public:
	string name;
private:
	double x;
	double y;

};
class Circle {
public:
	Circle(Point center, double radius) :center(center), radius(radius) {};
	Circle() = default;
	double Perimeter() {
		return 2 * radius*pi;
	}
	double Area() {
		return pi * radius*radius;
	}
	void Relationship(Point p) {
		double d = sqrt(pow(p.get_X() - center.get_X(), 2) + pow(p.get_Y() - center.get_Y(), 2));
		if (d < radius) cout << "点" << p.name << "在圆" << center.name << "内" << endl;
		else if (d == radius) cout << "点" << p.name << "在圆" << center.name << "上" << endl;
		else cout << "点" << p.name << "在圆" << center.name << "外" << endl;

	}
	string name() {
		return center.name;
	}
private:
	Point center;
	double radius;
};
int main() {
	Point p1(0, 0, "A");
	Point p2(1, 0, "B");
	Point p3(1, 1, "C");
	Point p4;
	p4.set_P(sqrt(2) / 2, 1 / 2);
	p4.name = "D";
	Circle c1(p1, 1);
	cout << "圆" << c1.name() << "的周长为" << c1.Perimeter() << endl;
	cout << "圆" << c1.name() << "的面积为" << c1.Area() << endl;
	c1.Relationship(p2);
	c1.Relationship(p3);
	c1.Relationship(p4);
	return 0;
}