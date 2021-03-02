#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <string> 

enum class errors {
	null_err = -1,
	input_error = 0,
	output_error = 1,
	read_failure,
	invalid_symbol
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
