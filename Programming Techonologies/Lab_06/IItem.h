#ifndef IITEM_H
#define IITEM_H

#include <string>

class IItem {
public:

	// Название
	virtual std::string GetTitle() const = 0;

	// Стоимость
	virtual double GetPrice() const = 0;

};


#endif // !IITEM_H
