#include"Queue.h"
#include<iostream>
using std::cout;
using std::endl;
int main() {
	Queue Q1;
	cout << Q1.enQueue(1) << endl;
	cout << Q1.enQueue(2) << endl;
	cout << Q1.deQueue() << endl;

	int a[] = { 12,12,12 };
	int *b = new int[std::size(a)];
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	cout << std::size(a) << endl;
	cout << sizeof(a)/sizeof(int) << endl;
	cout << sizeof(b[0]) << endl;
}