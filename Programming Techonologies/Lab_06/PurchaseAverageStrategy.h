#ifndef PURCHASEAVERAGESTRATEGY_H
#define PURCHASEAVERAGESTRATEGY_H

#include "IPurchaseStrategy.h"

class PurchaseAverageStrategy : public IPurchaseStrategy {
public:
	bool IsAcceptable(const IItem& item);
	PurchaseAverageStrategy(int avgPrice);
	virtual ~PurchaseAverageStrategy();

private:
	double _avgPrice;
};


PurchaseAverageStrategy::PurchaseAverageStrategy(int avgPrice) : _avgPrice(avgPrice) {}

PurchaseAverageStrategy::~PurchaseAverageStrategy() {}

bool PurchaseAverageStrategy::IsAcceptable(const IItem& item) {
	bool result = true;

	if (_avgPrice + 5 > item.GetPrice()) {
		result = false;
	}

	return result;
}
#endif // !PURCHASEAVERAGESTRATEGY_H
