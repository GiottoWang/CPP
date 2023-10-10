#include <iostream>
using namespace std;
//��Ԫ friend�������������Է������е�˽�г�Ա
//����ʵ�ַ�ʽ��ȫ�ֺ�������Ԫ��������Ԫ����Ա��������Ԫ
class T1;
class T3 {
public:
	T3(int a, int b);
	T3() = default;
	void visit();
private:
	T1 *T;
};

class T1{
	friend void func(T1 &_t);
	friend class T2;
	friend void T3::visit();
public:
	T1(int a,int b) :a(a), b(b) {};
	T1() :T1(1, 1) {};
private:
	int a;
	int b;
	int sum() { return a + b; }
};
//1.��Ա����������Ԫ����(T3)Ӧ������ǰ,T1Ӧ������ǰ
//2.T3���õ�T1�ĺ���Ӧ��������������T1֮��
T3::T3(int a, int b) {
	T = new T1(a, b);
}
void T3::visit(){
	cout << T->sum() << endl;
}


class T2 {
public:
	T2(int a,int b) {
		T = new T1(a,b);
	}
	T2() = default;
	void visit() {
		cout << T->sum() << endl;
	}
private:
	T1 *T;
};


void func(T1 &_t) {
	cout << _t.sum() << endl;
}


void test1() {//ȫ�ֺ�������Ԫ
	T1 t;
	func(t);
}
void test2() {//������Ԫ
	T2 t(1,-1);
	t.visit();
}
void test3() {//��Ա��������Ԫ
	T3 t(2, 2);
	t.visit();
}
int main() {
	test1();
	test2();
	test3();
}
