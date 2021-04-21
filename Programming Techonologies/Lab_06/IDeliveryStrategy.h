#ifndef IDELIVERYSTRATEGY_H
#define IDELIVERYSTRATEGY_H

#include "Reader.h"

//
// Интерфейс стратегии определения времени владения книгой
//
class IDeliveryStrategy {
public:

	// Вычислить период (в днях) владения книгой для заданного читателя
	virtual int HoldPeriod(const Reader& reader) const = 0;

};


#endif // !IDELIVERYSTRATEGY_H
