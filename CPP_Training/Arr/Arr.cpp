#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int *pas[10]; //整型指针数组
	int(*pa)[10] = &a;//指向数组的指针，用于多维数组
	int *p = a;//指向数组首元素的指针，*p=&a[0]
	auto p2(a);//指向数组首元素的指针
	int(&ar)[10] = a;//数组的引用
	int*(&pr)[10] = pas;//指针数组的引用
	
	int *beg = begin(a);
	int *last = end(a);
	int x = p[6];//*(p+6)
	int *q = p + 5;
	int y = q[-1];//*(q-1)
	cout << *p << ' ' << x << ' ' << *q << ' ' << y << endl;

	cout << "vector与数组的转化：" << endl;
	vector<int> vec(beg, last);//使用数组初始化vector
	vector<int> vec2(beg + 2, last - 2);//切片
	for (int i : vec) cout << i << ' ';
	cout << endl;
	for (int i : vec2)cout << i << ' ';
	cout << endl;
	//将vector对象copy到数组
	int b[10];
	int *m = b;
	for ( vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		*m = *it;
		m++;
	}
	for (int i : b) cout << i << ' ';
	cout << endl;



	cout << "多维数组："<<endl;
	double temp = 0;
	double ma[2][3][4] = { {{1},{2},{3}},{{-1},{-2},{-3}}};//部分初始化
	for(auto &i :ma)
		for(auto &j:i)
			for(auto &k:j){
				k = temp;
				temp++;
			}
	for (const auto &i : ma){//只读时，为避免编译器将数组转换为指向数组内首元素的指针，除最内层循环外，应使用引用类型
		for (const auto &j : i){
			for (auto k : j)
				cout << k << ' ';
			cout << endl;
		}
	}
	cout << endl;
	double(*t)[3][4] = ma;
	cout << *(*(*(t+1)+1)+2) << endl;

	for(auto m1=ma;m1!=ma+2;m1++)//使用数组指针间接访问
		for(auto m2=*m1;m2!=*m1+3;m2++){
			for (auto m3 = *m2; m3 != *m2 + 4; m3++) {
				*m3 *= (*m3);
				cout << *m3 << ' ';
			}
			cout << endl;
		}
	cout << endl;
	//or
	for (auto m1 = begin(ma); m1 != end(ma); m1++)//使用数组指针间接访问
		for (auto m2 = begin(*m1); m2 != end(*m1); m2++) {
			for (auto m3 = begin(*m2); m3 != end(*m2); m3++) {
				*m3 /= 2;
				cout << *m3 << ' ';
			}
			cout << endl;
		}


}

