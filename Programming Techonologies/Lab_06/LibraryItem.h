#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include "IItem.h"
#include "Reader.h"

//
// Декоратор для единицы хранения. 
// Добавляет структуру и поведение необходимые для использования
// классом библиотека: инвентарный номер, ссылку на читателя, 
//
class LibraryItem : IItem {
public:
	IItem* GetItem();

	int GetInventoryNumber() const { return _inventoryNumber; }

	int GetHoldPeriod() const { return _holdPeriod; }

	void SetHolderPeriod(int holdPeriod) { _holdPeriod = holdPeriod; }

	// Вернет NULL, если книга - в библиотеке
	Reader* GetReader() { return _reader; }

	// Установить владельца единицы хранения. Если нужно указать, 
	// единица хранения находится в библиотеке, то надо установить
	// значение NULL
	void SetReader(Reader* reader) { _reader = reader; }

	// При создании декоратора печатного издания, сразу же 
	// надо присвоить ему инвентарный номер.
	LibraryItem(IItem* item, int inventoryNumber);

	//
	// При уничтожении декоратора надо уничтожить и "обернутый" объект
	// иначе он будет создавать "мусор" в памяти
	//
	virtual ~LibraryItem();

	std::string GetTitle() const { return _item->GetTitle(); }

	double GetPrice() const { return _item->GetPrice(); }

private:
	// Это указатель на "обернутый объект"
	IItem* _item;

	//
	// Дополнительные (декорирующие) абстракции сущности, свойственные
	// единице хранения в библиотеке
	//

	// Инвентарный номер
	int _inventoryNumber;

	// Время владения книгой читателем
	int _holdPeriod;

	// Адрес объекта класса читатель, который владеет книгой в конкретный момент.
	// Если книга находится в библиотеке, то он должен быть NULL
	Reader* _reader;

};

#endif // !LIBRARYITEM_H
