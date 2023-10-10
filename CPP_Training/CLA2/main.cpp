#include"Queue.h"
#include<iostream>
using std::cout;
using std::endl;
int main() {
	Queue Q1;
	cout << Q1.enQueue(1) << endl;
	cout << Q1.enQueue(2) << endl;
	cout << Q1.deQueue() << endl;
	return 0;
}