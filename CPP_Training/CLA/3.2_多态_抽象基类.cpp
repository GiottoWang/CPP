#include<iostream>
//��̬���ŵ�
//1.�ṹ����
//2.�ɶ���ǿ
//3.������չ
class ABC_Calculator {
	//ӵ�д��麯�������������������������ΪAbstract Basic Class
	//ABC���ɴ�������
private://�������Զ����������أ����ṩֻ�����ʽӿ�
	int a;
	int b;
public:
	ABC_Calculator(const int &_a=0, const int &_b=0) :a(_a), b(_b) {};
	int get_a() { return a; };
	int get_b() { return b; };
	virtual int getResult() = 0;//���麯�������麯�� = 0
};
class Plus :public ABC_Calculator {
public:
	Plus(const int &_a = 0, const int &_b = 0) :ABC_Calculator(_a, _b) {};
	int getResult() { return get_a()+ get_b(); };
};
class Times :public ABC_Calculator {
public:
	Times(const int &_a = 0, const int &_b = 0) :ABC_Calculator(_a, _b) {};
	int getResult() {return get_a() *get_b();};
};
class Minus :public ABC_Calculator {
public:
	Minus(const int &_a = 0, const int &_b = 0) :ABC_Calculator(_a, _b) {};
	int getResult() { return get_a() - get_b(); };
};
class Divided :public ABC_Calculator {
public:
	Divided(const int &_a = 0, const int &_b = 0) :ABC_Calculator(_a, _b) {};
	int getResult(){ return get_a() / get_b();};
};

int main() {
	using std::cout;
	using std::endl;
	ABC_Calculator *x ;//����ָ�����ָ�����������
	x = new Plus(1,1);
	cout <<x->get_a()<<" + "<<x->get_b()<<" = "<< x->getResult() << endl;
	delete x;
	x = new Times(2, 2);
	cout << x->get_a() << " * " << x->get_b() << " = " << x->getResult() << endl;
	delete x;
	x = new Divided(9, 3);
	cout << x->get_a() << " / " << x->get_b() << " = " << x->getResult() << endl;
	delete x;
	x = new Minus(2, 7);
	cout << x->get_a() << " - " << x->get_b() << " = " << x->getResult() << endl;
	delete x;
}
