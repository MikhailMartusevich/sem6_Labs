#include "errorHandler.h"

errorHandler::errorHandler(errors type) {
	errorType = type;
	switch (errorType) {
	case errors::free_store_err:
		errorMessage = "Free store exhausted";
		break;
	case errors::empty_vector_err:
		errorMessage = "Vector is empty";
		break;
	case errors::find_err:
		errorMessage = "Find has no result";
		break;
	case errors::invalid_year:
		errorMessage = "Invalid year";
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
