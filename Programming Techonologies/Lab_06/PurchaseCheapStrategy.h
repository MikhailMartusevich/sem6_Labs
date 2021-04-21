#ifndef PURCHASECHEAPSTRATEGY_H
#define PURCHASECHEAPSTRATEGY_H

#include "IPurchaseStrategy.h"

class PurchaseCheapStrategy : public IPurchaseStrategy {
public:

	// Реализация абстрактного метода из родительского интерфейса.
	// Реализует проверку печатного издания на допустимую цену
	bool IsAcceptable(const IItem& item);

	PurchaseCheapStrategy(double maxPrice);
	virtual ~PurchaseCheapStrategy();

private:
	double _maxPrice;
};

PurchaseCheapStrategy::PurchaseCheapStrategy(double maxPrice) : _maxPrice(maxPrice) {}

PurchaseCheapStrategy::~PurchaseCheapStrategy() {}

bool PurchaseCheapStrategy::IsAcceptable(const IItem& item) {
	bool result = true;

	// Если цена более заданной максимальной,
	// то закупка не приемлема
	if (item.GetPrice() > _maxPrice) {
		result = false;
	}
	return result;
}
#endif // !PURCHASECHEAPSTRATEGY_H




