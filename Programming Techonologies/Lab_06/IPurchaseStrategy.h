#ifndef IPURCHASESTRATEGY_H
#define IPURCHASESTRATEGY_H

#include "IItem.h"

class IPurchaseStrategy {
public:

	// Возвращает true, если печатное издание подходит для закупки.
	// Здесь передается ссылка на объект (передача объекта
	// абстрактного класса по значению не может быть выполнена, т.к.
	// требует конструирования объекта)
	virtual bool IsAcceptable(const IItem& item) = 0;

};


#endif // !IPURCHASESTRATEGY_H

