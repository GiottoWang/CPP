#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
//������private���Ժͷ��������κη�ʽ�̳У����������в��ɷ���
//������protected���Ժͷ������Թ��л򱣻���ʽ�̳У����������п��Է��ʣ����ⲻ�ɷ���
//������public���Ժͷ������Թ��з�ʽ�̳У������������к��ⲿ���ɷ��ʣ�����ֻ�����������з���
class T {
private:
	string a;
	int b;
public:
	T(string _a = "none", int _b = 0) :a(_a), b(_b) {}
	string get_a() { return a; }
	int get_b() { return b; }
};

class T1 :public T {
private:
	double c;
public:
	T1(string _a= "none", int _b= 0, double _c = 0) :T(_a, _b), c(_c) {}
	double get_c() { return c; }
};
class T2 :protected T1 {
private:
	bool d;
public:
	T2(string _a = "none", int _b = 0, double _c = 0, bool _d=0) :T1(_a, _b, _c), d(_d) {}
	bool get_d() { return d; }
	void func1() {
		cout << get_a() << endl;
		cout << get_b() << endl;
		cout << get_c() << endl;
	}
};

class T3 :private T2 {
private:
	long e;
public:
	T3(string _a = "none", int _b = 0, double _c = 0, bool _d = 0, long _e = 0) :T2(_a, _b, _c, _d) {}
	long get_e() { return e; }
	void func2() {
		cout << get_a() << endl;
		cout << get_b() << endl;
		cout << get_c() << endl;
		cout << get_d() << endl;
	}
};
class T4 :public T3 {
private:
	float f;
public:
	//int a=get_d();//�÷�����T3������Ϊprivate����T4�޷�����

};
int main() {
	T3 a;//˽�м̳У�����private��protected��public ->private
	//���·�������Ϊprivate
	//a.get_a();
	//a.get_b();
	//a.get_c();
	//a.get_d();
	//a.func1();
	a.func2();
	T2 b;//�����̳У�����private->����private,����public->����protected
	//���·�������Ϊprotected
	//b.get_a();
	//b.get_b();
	//b.get_c();
	b.func1();
	T1 c;//���м̳У�����private->����private������public->����public
	cout << c.get_a() << endl;
	cout<<c.get_b()<<endl;
}