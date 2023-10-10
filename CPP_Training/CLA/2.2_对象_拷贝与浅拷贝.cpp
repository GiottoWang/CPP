#include <iostream>
using namespace std;
//ǳ�������򵥵�ֵ����
//������ڶ�����������ռ䣬���п���
//���ʵ�ַ�ʽ��1���ع��������캯����2���ع�operator

class Person{
public:
	Person() = default;
	Person(int a, int b);
	//1���ع��������캯�������ڳ�ʼ��
	Person(const Person &p);
	//2���ع�operator,���ڸ�ֵ
	Person& operator=(const Person &_p);
	friend ostream& operator<<(ostream &cout, const Person &_p);
	~Person() {
		if (b != nullptr) {
			delete b;
			b = nullptr;
		}
		cout << "����ָ�����ͷ�" << endl;
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
	b = new int(*p.b);//�ڶ�����������ռ䣬�������
}
Person& Person::operator=(const Person &_p) {
	a = _p.a;
	if (b != nullptr) {
		delete b;
		b = nullptr;
	}
	b = new int(*_p.b);////�ڶ�����������ռ䣬�������
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