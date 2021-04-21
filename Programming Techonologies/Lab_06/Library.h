#ifndef LIBRARY_H
#define LIBRARY_H

#include "IPurchaseStrategy.h"
#include "IDeliveryStrategy.h"
#include "IItem.h"
#include "LibraryItem.h"
#include <vector>
#include <algorithm>

class Library {
public:
	std::vector<LibraryItem*> GetLibItems();
	std::vector<Reader*>& GetReaders();

	// При создании экземпляра класса библиотека надо указать
	// стратегии приобретения печатных изданий и вычисления 
	// периода владения единицей хранения читателями.
	Library(
		const std::string& name,
		IPurchaseStrategy* purchaseStrategy,
		IDeliveryStrategy* deliveryStrategy);

	// При уничтожении объекта, надо уничтожить и объекты 
	// стратегий, и единицы хранения
	virtual ~Library();

	// Название библиотеки
	std::string GetName() { return _name; }

	// Попытаться приобрести печатное издание.
	// Если оно приобретено, то возвращается true,
	// в противном случае - false
	bool PurchaseItem(IItem* item);

	// Зарегистрировать читателя
	void AddReader(Reader* reader);

	// Выдать книгу читателю
	void LetLibItemOut(LibraryItem* item, Reader* reader);

	// Вернуть книгу в библиотеку
	void PutLibItemBack(LibraryItem* libItem);

private:

	std::string _name;
	// Стратегии
	IPurchaseStrategy* _purchaseStrategy;
	IDeliveryStrategy* _deliveryStrategy;

	// Последний присвоенный инвентарный номер
	int _lastInventoryNumber;

	// Все единцы хранения
	std::vector<LibraryItem*> _libItems;

	// Все читатели
	std::vector<Reader*> _readers;
};


#endif // !LIBRARY_H
