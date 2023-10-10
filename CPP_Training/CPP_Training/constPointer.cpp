#include <iostream>
//命名规范:自定义数据类型名用大驼峰，标识符用小驼峰
using namespace std;
int main() 
{
	int i = 7,j=10;
	int *pi = &i;
	const int *p = &i;//底层const，指向常量的指针,p指向的地址可以改变，但其指向对象的值不能通过指针访问改变
	int *const p1 = &i;//顶层const，常量指针，P1指向的地址不能改变，但其指向对象的值可以通过指针访问改变
	const int *const p2 = &i;//左边是底层const，右边是顶层consat指向常量的常量指针，什么都不能变
	constexpr int *p3 = &i;//常量指针
	cout << *p3 << endl;
	cout << *p << endl;
	p = &j;
	cout << *p << endl;
	*p1 = 12;
	cout << *p1 << endl;
	const int a = -1, &r = 1.11;//常量引用可以直接引用常量，所用用于引用声明的const都是底层const
	p = pi;//const可以指向或引用变量，反过来不行
	cout << *p << endl;

}
