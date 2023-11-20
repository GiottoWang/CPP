#pragma once
#include <iostream>
namespace func{
	//����ģ������ֵ��÷���
	//1.�Զ������Ƶ�
	//2.��ʽָ�����ͣ�ʹ�ô˵��÷���ʱ�����Է�����ʽ����ת��
	template <typename T>
	void Swap(T&a, T&b) {//����������ʱ�����ܷ�������ת����ǿ������ʽ������
		T temp = a;
		a = b;
		b = temp;
		std::cout << "����ģ�����" << std::endl;
	}
	//����ͨ��������ʱ�����ȵ�����ͨ����
	void Swap(int &a, int &b) {
		int temp = a;
		a = b;
		b = temp;
		std::cout << "��ͨ��������" << std::endl;
	}

	//����ģ���������
	template <typename T>
	T plus(T a, T b) {
		std::cout << "����ģ�����" << std::endl;
		return a + b;
	}
	template <typename T>
	T plus(T a, T b, T c) {
		std::cout << "ģ�����ص���" << std::endl;
		return a + b + c;
	}
	//����ģ��ľ����ԣ����ܴ��������������ͣ��Ľ������
	//1.���������
	//2.ʵ����ģ��
	class T {
		char a;
		int b;
	public:
		T(const char &_a = ' ', const int&_b = 0) :a(_a), b(_b) {};
		//void set_a(const char &_a) { a = _a; }
		//void ste_b(const int &_b) { b = _b; }
		char get_a() const { return a; }
		int get_b() const { return b; }
		T& operator=(T& _t) {//1.���������
			a = _t.get_a();
			b = _t.get_b();
			return *this;
		}
	};

	template <>
	T plus(T a, T b) {//2.ʵ����ģ��
		T t(a.get_a() + b.get_a(), a.get_b() + b.get_b());
		return t;
	}

}
