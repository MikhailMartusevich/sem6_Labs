#include "Newspaper.h"

Newspaper::Newspaper(const std::string& title, double price, const std::string& edition) 
	: _title(title), _price(price), _edition(edition) {}

Newspaper::~Newspaper() {}
