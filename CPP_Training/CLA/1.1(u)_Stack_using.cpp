#include<iostream>
#include "1.1_ADT_Stack.h"
int main() {
	Stack st1;
	int i = 0;
	while (!st1.isFull()) 
		st1.push(i++);
	while (!st1.isEmpty())
		std::cout<<st1.pop(i)<<' '<<i<<std::endl;
}