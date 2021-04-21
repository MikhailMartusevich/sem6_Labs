#ifndef LECTURER_H
#define LECTURER_H

#include "Reader.h"

class Lecturer : public Reader {
public:
	Lecturer(const std::string& name, const std::string& position);
	virtual ~Lecturer();

	std::string GetPosition() { return _position; }

private:

	// Занимаемая должность
	std::string _position;
};


#endif // !LECTURER_H
