#include "LibraryItem.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LibraryItem::LibraryItem(IItem* item, int inventoryNumber)
	: _item(item), _inventoryNumber(inventoryNumber), _reader(NULL), _holdPeriod(0) 
{}

LibraryItem::~LibraryItem() {}

IItem* LibraryItem::GetItem() {
	return _item;
}
