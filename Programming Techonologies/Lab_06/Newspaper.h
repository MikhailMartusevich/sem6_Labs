#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include "IItem.h"

class Newspaper : public IItem {
public:
	Newspaper(const std::string& title, double price, const std::string& edition);
	virtual ~Newspaper();

	// Реализация интерфейса печатного издания
	std::string GetTitle() const { return _title; }

	// Реализация интерфейса печатного издания
	double GetPrice() const { return _price; }

	// Получить номер тиража газеты. 
	// Добавленный метод, специфический для газеты
	std::string GetEdition() const { return _edition; }

private:
	std::string _title;
	double _price;
	std::string _edition;
};

#endif // !NEWSPAPER_H

