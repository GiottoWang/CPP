#include<iostream>
#include<cmath>
#include<string>
class demo {
private:
	std::string word;
public:
	demo(const std::string& str) {
		word = str;
		std::cout << "demo " << word << " created\n" << std::endl;
	}
	~demo() {
		std::cout << "demo " << word << " destroyed\n" << std::endl;
	}
	void show()const {
		std::cout << "demo " << word << " lives\n" << std::endl;
	}

};
class bad_mean_Harmonic {
private:
	long double a;
	long double b;
public:
	bad_mean_Harmonic(double _a = 0, double _b = 0) :a(_a), b(_b) {};
	void message() {
		std::cout << "mean_Harmonic函数不允许使用相反数作为参数,但您输入的参数为：" << a << '  ' << b << std::endl;
	}
};
class bad_mean_Geometric {
private:
	long double a;
	long double b;
public:
	bad_mean_Geometric(double _a = 0, double _b = 0) :a(_a), b(_b) {};
	void message() {
		std::cout << "mean_Harmonic函数应使用非负数作为参数,但您输入的参数为：" << a << '  ' << b << std::endl;
	}
};
typedef  bad_mean_Harmonic BH;
typedef bad_mean_Geometric BG;

double mean_Harmonic(double a, double b) {
	if (a == -b)
		throw BH(a, b);
	return 2.0*a*b / (a + b);
}
double mean_Geometric(double a, double b) {
	if (a < 0 || b < 0)
		throw BG(a, b);
	return std::sqrt(a*b);
}
double means(double a, double b) {
	double M, H, G;
	demo d("  means中的  ");
	M = (a + b) / 2.0;
	try {
		H = mean_Harmonic(a, b);
		G = mean_Geometric(a, b);
	}
	catch (BH &_bh) {
		_bh.message();
		std::cout << "means中的catch\n" << std::endl;
		throw;//将导致means函数终止，退栈，把异常返回给主函数，进入主函数中的catch

	}
	d.show();
	return (M + H + G) / 3.0;
}
int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	double x, y, z;
	{
		demo d("  main中的  ");
		cout << "请输入两个数：";
		while (cin >> x >> y) {
			try {
				z = means(x, y);
				cout << x << "和" << y << "的算数平均数、调和平均数以及几何平均数的平均数为：" << z << endl;
				cout << "请输入下一对数:";
			}//end try
			catch (BH &_bh) {
				_bh.message();
				cout << "请重新输入:";
				continue;
			}
			catch (BG &_bg) {
				_bg.message();
				cout << "输错了，完蛋咯";
				break;
			}//end catch

		}//end while
		d.show();
	}//end block
	cout << "BYE BYE~" << endl;
}