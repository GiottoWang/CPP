#include "1.1_ADT_Stack.h"
Stack::Stack() {
	top = 0;
}

bool Stack::isEmpty() {
	return top==0;
}
bool Stack::isFull() {
	return top == MAX;
}
bool Stack::push(const int &x) {
	if (top < MAX){ Arr[top++] = x; 
	return true;
	}
	else return false;
}
bool Stack::pop(int &x) {
	if (top > 0) {
		x = Arr[top--];
		return true;
	}
	else return false;
}