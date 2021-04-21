#include "Library.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Library::Library(
	const std::string& name, IPurchaseStrategy* purchaseStrategy, IDeliveryStrategy* deliveryStrategy)
	: _name(name), _purchaseStrategy(purchaseStrategy), _deliveryStrategy(deliveryStrategy), _lastInventoryNumber(0)
{}

Library::~Library() {
	if (_purchaseStrategy != NULL) {
		delete _purchaseStrategy;
	}

	if (_deliveryStrategy != NULL) {
		delete _deliveryStrategy;
	}

	for (int i = 0; i < _libItems.size(); i++) {
		delete _libItems[i];
	}
}

bool Library::PurchaseItem(IItem* item) {
	bool result = true;
	// Проверить, возможно ли приобрести печатное издание
	// в соответствии с политикой приобретения
	if (_purchaseStrategy->IsAcceptable(*item)) {
		// Печатное издание приобретается, оно становится 
		// единицей хранения. Поэтому создается экземпляр
		// декоратора. Назначается инвентарный номер
		_lastInventoryNumber++;
		LibraryItem* libItem = new LibraryItem(item, _lastInventoryNumber);

		_libItems.push_back(libItem);
	}
	else {
		// Нельзя приобретать
		result = false;
	}
	return result;
}

void Library::AddReader(Reader* reader) {
	_readers.push_back(reader);
}

void Library::LetLibItemOut(LibraryItem* item, Reader* reader) {
	// Выдавать книгу можно только читателю, зарегистрированному
	// в данной библиотеке
	if (find(_readers.begin(), _readers.end(), reader) != _readers.end()) {
		// Кнмгу можно выдать, если она не была взята другим  или этим читателем
		if (item->GetReader() == NULL) {
			// Получить величину периода владения книгой в соответствии с 
			// со стратегией и выдать книгу
			int holdPeriod = _deliveryStrategy->HoldPeriod(*reader);

			item->SetHolderPeriod(holdPeriod);
			item->SetReader(reader);
		}
	}
}

void Library::PutLibItemBack(LibraryItem* libItem) {
	libItem->SetReader(NULL);
}

std::vector<Reader*>& Library::GetReaders() {
	return _readers;
}

std::vector<LibraryItem*> Library::GetLibItems() {
	return _libItems;
}
