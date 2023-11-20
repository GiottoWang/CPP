#include"3.4_��̬_��̬�ڴ����.h"
using std::cout;
using std::endl;
//ע������
//1.������Ŀ������캯��
//2.�������������ع�������1����Ա������2����Ԫ����

//base class T
T::T(int _a1, int _a2) :a1(new int(_a1)), a2(_a2) 
{ cout << "T���вι��캯������" << endl; }
T::T(const T& _t) {
	a1 = new int(*_t.a1);
	a2 = _t.a2;
	cout << "T�Ŀ������캯������" << endl;
};
T::~T() {
	if (a1 != nullptr) {
		delete a1;
	}
	cout << "T��������������" << endl;
}
T& T::operator=(const T& _t) {
	if (a1 != nullptr)delete a1;
	a1 = new int(*_t.a1);
	a2 = _t.a2;
	return *this;
};
std::ostream& operator<<(std::ostream& os, const T& _t) {
	if (_t.a1 == nullptr) os << "a1 = null" << endl;
	else
		os << "a1 = " << *_t.a1 << endl;
	os << "a2 = " << _t.a2 << endl;
	return os;
};

//class T1
T1::T1(int _a1, int _a2, int _b) :T(_a1, _a2), b(new int(_b)) {
	cout << "T1���вι��캯��1����" << endl;
};
T1::T1(const T& _t, int _b):T(_t),b(new int (_b)){
	cout << "T1���вι��캯��2����" << endl;
}
//ע���1
T1::T1(const T1& _t) :T(_t){//ֱ�Ӱѻ���Ŀ������촫�������������û�ָ�����ָ�����������
	b = new int(*_t.b);
	cout << "T1�Ŀ������캯������" << endl;
}
T1::~T1() {
	if (b != nullptr) delete b;
	cout << "T1��������������" << endl;
}
//ע���2.1
T1& T1::operator=(const T1& _t) {
	T ::operator=(_t);//�������û�ָ�����ָ�����������
	b = new int(*_t.b);
	return *this;
};

//ע���2.2
std::ostream& operator<<(std::ostream& os, const T1& _t) {
	os << (const T&)_t;//�����ⲻ���ԣ�������Ҫǿ������ת��
	if(_t.b==nullptr)  os<< "b = null" << endl;
	else
	{
		os << "b = " << *_t.b << endl;
	}
	return os;

};
