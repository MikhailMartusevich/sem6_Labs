#ifndef GRADUATEST_H
#define GRADUATEST_H

#include "Reader.h"

class Graduate : public Reader {
public:
	Graduate(const std::string name, const std::string form);
	virtual ~Graduate();

	std::string GetForm() const { return _form; }

private:
	std::string _form;
};

#endif // !GRADUATEST_H
