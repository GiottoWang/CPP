#include"3.4_��̬_��̬�ڴ����.h"
#include <iostream>
using namespace std;
void test1() {
	T t1(1, -1);
	T t2(t1);
	cout << t1 << endl;
	cout << t2 << endl;
}
void test2() {
	T t1(1, 1);
	T1 t2(t1, 0);//��T�Ŀ������캯��
	T1 t3(99, 77, 88);//��T���вι��캯��
	cout << t1 << endl;
	cout << t2 << endl;
	cout << t3 << endl;
}
void test3() {
	T1 t1(1, 2, 3);
	T1 t2(t1);//����T�Ŀ���������T�Ŀ���
	T1 t3;//Ĭ�Ϲ���
	t3 = t2;
	cout << t1 << endl;
	cout << t2 << endl;
	cout << t3 << endl;
}

int main() {
	//test1();
	//test2();
	test3();
}