#ifndef PUBLICLIBRARYSTRATEGY_H
#define PUBLICLIBRARYSTRATEGY_H

#include "IDeliveryStrategy.h"

//
// Реализация стратегии определения времени владения книгой.
// В данном случае (публичная библиотека) период для 
// всех категорий читателей одинаковый. Он задается при
// создании экземпляра стратегии
//
class PublicLibraryStrategy : public IDeliveryStrategy
{
public:
	PublicLibraryStrategy(int nomianlHoldPeriod);
	virtual ~PublicLibraryStrategy();

	// Реализация метода интерфейса стратегии
	int HoldPeriod(const Reader& reader) const;

private:
	int _nomianlHoldPeriod;

};


#endif // !PUBLICLIBRARYSTRATEGY_H
