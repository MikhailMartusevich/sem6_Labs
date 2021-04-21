#ifndef JOURNAL_H
#define JOURNAL_H

#include "IItem.h"
#include <string>

class Journal : public IItem {
public:
	Journal(const std::string& title, double price, const std::string& volume);
	virtual ~Journal();

	// Реализация интерфейса печатного издания
	std::string GetTitle() const { return _title; }

	// Реализация интерфейса печатного издания
	double GetPrice() const { return _price; }

	// Получть название тома (номера) журнала. 
	// Добавленный метод, специфический для журнала
	std::string GetVolume() const { return _volume; }

private:
	std::string _title;
	double _price;
	std::string _volume;

};


#endif // !JOURNAL_H
