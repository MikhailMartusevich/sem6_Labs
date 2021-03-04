#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <string> 

enum class errors {
	null_err = -1,
	free_store_err,
	empty_vector_err,
	find_err,
	invalid_year,

};

class errorHandler {
public:
	errorHandler() : errorType(errors::null_err), errorMessage("") {};
	errorHandler(errors type);
	~errorHandler() = default;

	std::string print();
private:
	errors errorType = errors::null_err;
	std::string errorMessage = "";
};

#endif // !ERRORHANDLER_H
