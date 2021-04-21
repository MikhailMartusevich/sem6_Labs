#ifndef READER_H
#define READER_H

#include <string>

class Reader {
public:
	std::string GetName();

	virtual ~Reader();

protected:

	// Защищенный конструктор не позволит создавать объекты данного класса, 
	// но будет использоваться в классах-потомках
	Reader(const std::string& name);

private:
	std::string _name;

};


#endif // !READER_H
