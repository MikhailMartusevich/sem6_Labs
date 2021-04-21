#ifndef STUDENT_H
#define STUDENT_H

#include "Reader.h"

class Student : public Reader {
public:
	Student(const std::string& name, int clazz);
	virtual ~Student();

	int GetClass() const { return _class; }

private:
	int _class;

};


#endif // !STUDENT_H
