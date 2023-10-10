#include <iostream>
using namespace std;
typedef int *pi;//pi类型为指向int的指针
int main()
{
	int i = 100,j=-99;
	const pi p = &i;//理解为指向int的 const p，== int * const p or constexpr int p
	pi const p1 = &i;//与p定义等价,理解为指向int的 const p,!const int *p
	/*
	const pi p的基本数据类型是指针
	const int *p的基本数据类型是int，*为声明符
	*/
	cout <<*p << endl;
	*p = j;
	
	cout << *p << endl;
	string a = "abc";
	cout << a;


}
