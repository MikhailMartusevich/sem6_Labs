#ifndef RESULT_H
#define RESULT_H

#include <iostream>

class Result {
public:
	Result(const char* time, int year, const char* type) : _resultTime(time), _yearOfResult(year), _typeOfResult(type) {};
	virtual ~Result() {};
	virtual void getData();
protected:
	const char* _resultTime;
	const char* _typeOfResult;
	int _yearOfResult{ 0 };
};

void Result::getData() {
	std::cout << "Type of record: " << _typeOfResult;
	std::cout << "\nTime: " << _resultTime;
	std::cout << "\nYear: " << _yearOfResult << std::endl;
};


class Olympic : public Result {
public:
	Olympic(const char* time, int year) : Result(time, year, "Olympic record") {};
	virtual ~Olympic() {};
};

class Worldwide : public Result {
public:
	Worldwide(const char* time, int year) : Result(time, year, "Worldwide record") {};
	virtual ~Worldwide() {};
};

#endif // !RESULT_H
