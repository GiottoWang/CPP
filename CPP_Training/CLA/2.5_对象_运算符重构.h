#pragma once
#include<iostream>
class Time {
	/*�滮ʱ��*/
private:
	int hour;//Сʱ
	int min;//����
public:
	Time();
	Time(int h, int m);
	void Reset(int h, int m);
	void add_H(int h);
	void add_M(int m);
	Time operator+(const Time &_t)const;
	Time operator-(const Time &_t)const;
	Time operator*(double n)const;
	//Time& operator=(const Time &_t);��Ҫ������� ��2.2
	bool operator==(const Time &_t);
	bool operator!=(const Time &_t);
	bool operator<(const Time &_t);
	bool operator>(const Time &_t);
	friend  inline Time operator*(double n, const Time &_t);
	friend std::ostream &operator<<(std::ostream & os, const Time &_t);
};