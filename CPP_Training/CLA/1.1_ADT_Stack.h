#pragma once
class Stack {
private:
	enum{MAX=10};
	int Arr[MAX];
	int top;
public:
	Stack();
	bool isEmpty();
	bool isFull();
	bool push(const int &x);
	bool pop(int &x);
	
};

