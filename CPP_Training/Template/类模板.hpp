#pragma once
#include<string>
#include <iostream>
using std::string;
namespace cla {
	//��ģ��û���Զ������Ƶ�
	//��ģ���ģ������б��п�����Ĭ�ϲ���,Ĭ�ϲ�����������б�ĩβ
	template<class T1 = string, class T2 = int>
	class Base {
	private:
		T1 a;
		T2 b;
	public:
		Base() = default;
		explicit Base(T1 _a, T2 _b) :a(_a), b(_b) {}
		T1 get_a() { return a; };
		T2 get_b() { return b; };
		Base& operator=(const Base& _b);//��������������ʵ��
		friend std::ostream& operator<<(std::ostream& os,  const Base& _b) {//��ģ�����Ԫ������������ʵ�֣�����ʵ�ֺ��鷳
			os << "a = "<<_b.a<<"  b = "<<_b.b<<std::endl;
			return os;
		};
	};
	//������̳���ģ��ʱ
	//1.ָ������ģ������
	class Derive1 :public Base<string, int> {
	public:
		void func() {
			std::cout << "Base�������ࣺDerive1" << std::endl;
		}

	};
	//2.������Ҳ����ģ��
	template<class T3, class T1 = string, class T2 = int>
	class Derive2:public Base<T1,T2>{
		T3 c;
	public:
		void func() {
			std::cout << "Base�������ࣺDerive2" << std::endl;
		}
	};
	//��Ա����������ʵ��,ע�����ģ������б�
	//��Ա�����ڱ���׶β������ɣ������ú�����ɣ�����ͨ�಻ͬ
	template<class T1, class T2>
	Base<T1, T2>& Base<T1, T2>::operator=(const Base& _b) {
		a = _b.a;
		b = _b.b;
		return *this;
	}

	//��ģ���������������
	//1.ָ����������
	//2.����ģ�廯
	//3.��ģ�廯
	//1.ָ����������
	void swap1(Base<string, int> &_b1, Base<string, int>&_b2) {
		Base<string, int> temp;
		temp = _b1;
		_b1 = _b2;
		_b2 = temp;
		std::cout << "swap1�ĵ���" << std::endl;
	}
	//2.����ģ�廯
	template<class T1, class T2>
	void swap2(Base<T1, T2>&_b1, Base<T1, T2>&_b2) {
		Base<T1, T2> temp;
		temp = _b1;
		_b1 = _b2;
		_b2 = temp;
		std::cout << "swap2�ĵ���" << std::endl;
	}
	//3.��ģ�廯
	template<class T>
	void swap3(T&_b1, T&_b2) {
		//���������������=
		T temp;
		temp = _b1;
		_b1 = _b2;
		_b2 = temp;
		std::cout << "swap3�ĵ���" << std::endl;
	}
}
