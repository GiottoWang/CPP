#include <iostream>
#include <string>
using namespace std;
//�������������ٶ���ǰ��ִ������������û���������͡�
//���캯��:��������ʱ��Ϊ����ĳ�Ա���Ը�ֵ����û���������͡�
//���캯����Ϊ �޲Ρ��вκͿ���
//�������캯����ǳ��������ʹ��ʱ����1��ʹ��һ���ִ�Ķ����ʼ���¶���2����ֵ������������3��һֵ����������ֵ
//���캯���ĵ��÷�ʽ�����ŷ�����ʾ������ʽת����
//�Զ����вκ󣬱����������ṩĬ���޲ι���
//�Զ��忽���󣬱����������ṩĬ���в��Լ��޲ι���
class Person{
public:
	//����
	Person() {};//�޲ι���
	Person(int a):a(a) {};//�вι��죬��ʼ���б�
	Person( const Person &P) { a=P.get_A(); //������ֻ�ܵ��ó�����
	};//��������
	~Person() {};//��������
	int get_A() const {//������ֻ�ܵ��ó�����
		return a;
	}
private:
	int a;
};
//���÷�ʽ
void test1() {
	//��ͨ
	Person p1(1);//���ŷ�
	Person p2 = Person(2);//��ʾ��
	Person p3 = { 3 };//��ʽת����
	cout << p1.get_A()<<' ' << p2.get_A() << ' ' << p3.get_A() << endl;
}
//ǳ����
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