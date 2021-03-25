#include "errorHandler.h"

errorHandler::errorHandler(errors type) {
	errorType = type;
	switch (errorType) {
	case errors::input_error:
		errorMessage = "Unable to open input file";
		break;
	case errors::output_error:
		errorMessage = "Unable to write to output file";
		break;
	case errors::null_err:
	default:
		errorMessage = "Unknown error";
		break;
	}
}

std::string errorHandler::print() {
	return errorMessage;
}
