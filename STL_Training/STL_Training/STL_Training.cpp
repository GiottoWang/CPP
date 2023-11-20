#include <iostream>
#include<algorithm>
#include<map>
#include<string>
int main() {
	std::map<std::string,int> m;
	int a = 10;
	int *p = &a;
	m.insert(std::pair<std::string, int>("a", a));
	
	*p = 20;
	m.insert(std::pair<std::string, int>("b", a));
	std::cout << m["a"] << std::endl;
	std::cout << m["b"] << std::endl;

}