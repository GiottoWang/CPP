#include <iostream>
using namespace std;
//static ��̬��Ա
//static ��Ա�������ڱ���׶η����ڴ棻�������ж������������������ⶨ��	
//static ��Ա�������������ж�����ֻ�ܷ���static����
//const  �������η�
//const ���������������޸ĳ�Ա���ԣ�mutable���⣩
//const ������ֻ�ܵ��ó�����
//this ָ��ı����Ƕ���const������ָ�룬thisָ��ĵ�ַ���ܸı䣬����ָ������ֵ����ͨ��ָ����ʸı�

class T {
public:
	static int a;
	mutable int c;
	int get_B() {
		return b;
	}
	static int  get_BB(int _b) {//ֻ�ܷ���static����
		 //c = 1;���ܷ���
		b = _b;
		return b;
	}
	void fun() const {//�������в������޸ĳ�Ա����
		a = 50;//��̬��������
		c = 100;//mutable����
		//d = 500; ���� this->d ΪT* const this�������һ��const���� 
		//��Ϊ const T* const this ָ�룺�ײ�+����ָ�� thisָ��ĵ�ַ�Ͷ�Ӧ��ֵ�����ܸı�
		cout << a << c << endl;
	}
private:
	static int b;//������˽�����µľ�̬��Ա����ͬ������װ
	int d;
};
//�����ʼ��
int T::a = 1;
int T::b = -1;
void test1() {//���ݹ���
	T t1,t2;
	cout << t1.a << endl;
	t2.a=2;
	cout << t1.a << endl;
}
void test2() {//��̬��Ա������������һ����
	//ͨ���������
	T t1;
	cout << t1.a << endl;
	cout << t1.get_B() << endl;
	//ͨ����������
	cout << T::a << endl;
	cout << T::get_BB(-3) << endl;//��̬�����ĵ���
}
void test3() {//������ֻ�ܵ��ó�����
	const T t1;
	t1.a = 1000;
	t1.fun();
	//t1.get_B(); ���ܵ��÷ǳ�����
}
int main() {
	test1();
	test2();
	test3();
}