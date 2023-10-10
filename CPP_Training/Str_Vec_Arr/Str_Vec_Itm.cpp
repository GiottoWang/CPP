
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	/*String*/

	string a(7, 'a');
	string b=" ";
	//getline(cin, b);
	if(!a.empty())
		cout<< a+b<<endl;//字符串加法两边至少有一个string对象
	string c("Hello World!");
	for (auto &i : c)//通过下标直接访问
		i = toupper(i);
	cout << c << endl;
	for (auto it = c.begin(); it != c.end(); ++it)//通过迭代器间接访问
		*it = tolower(*it);
	cout << c << endl;
	/*Vector*/
	//初始化
	vector<string> vec(5, "hi" );
	vector<int> v2{ 1,2 };
	cout << vec[0] << v2[1] << endl;
	//添加新元素
	vector<int> v3;
	for (int i = 0; i < 10; i++){
		v3.push_back(i+1);
	}
	for (auto &i : v3) {//直接访问
		i *= i;
	}
	for (auto i : v3) {
		cout << i << ' ';
	}
	cout << endl;
	for (auto it = v3.begin(); it != v3.end(); it++)//间接访问
		*it *= 2;
	for (auto it = v3.cbegin(); it != v3.cend(); it++)
		cout << *it<< ' ';
	cout << endl;

	string w;
	vector<string> t;
	while (cin >> w)
		t.push_back(w);
	for (auto i : t)
		cout << i << " ";
	cout << endl;
	
		
	



}
