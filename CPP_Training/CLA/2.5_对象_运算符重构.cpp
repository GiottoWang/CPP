#include <iostream>
#include"2.5_对象_运算符重构.h"
Time::Time(int h, int m) :hour(h), min(m) {};
Time::Time() :Time(0, 0) {};
void Time::Reset(int h, int m) {
	hour = h;
	min = m;
}
void Time::add_H(int h) {
	hour += h;
};
void Time::add_M(int m) {
	hour += (min + m) / 60;
	min += (min + m) % 60;
};
Time Time::operator+(const Time &_t) const{
	Time t;
	t.hour = hour + _t.hour + (min + _t.min) / 60;
	t.min = (min + _t.min) % 60;
	return t;
};
Time Time::operator-(const Time &_t) const{
	Time t;
	int t1 = hour * 60 + min;
	int t2 = _t.hour * 60 + _t.min;
	t.hour = (t1 - t2) / 60;
	t.min = (t1 - t2) % 60;
	return t;
};
Time Time::operator*(double n) const {
	Time _t;
	long long t = (hour * 60 + min)*n;
	_t.hour = t / 60;
	_t.min = t % 60;
	return _t;
};
bool Time::operator==(const Time &_t) {
	return (hour == _t.hour&&min == _t.min) ? true : false;
};
bool Time::operator!=(const Time &_t) {
	return (hour == _t.hour&&min == _t.min) ? false : true;
};
bool Time::operator<(const Time &_t) {
	if (hour > _t.hour) return true;
	else if (hour == _t.hour) {
		if (min > _t.min) return true;
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

};
bool Time::operator>(const Time &_t) {
	if (hour < _t.hour) return true;
	else if (hour == _t.hour) {
		if (min < _t.min) return true;
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

};
inline Time operator*(double n,  const Time &_t) {
	return _t.operator*(n);
};
std::ostream & operator<<(std::ostream & os, const Time &_t) {
	os << _t.hour << " hours " << _t.min << " min " << std::endl;
	return os;
};

