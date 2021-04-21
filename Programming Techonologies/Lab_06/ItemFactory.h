#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "Book.h"
#include "Journal.h"
#include "Newspaper.h"

class ItemFactory {
public:
	// Фабричный метод для создания экземпляра книги.
	// За уничтожение объекта отвечает клиент.
	Journal* CreateJournal();

	// Фабричный метод для создания экземпляра журнала.
	// За уничтожение объекта отвечает клиент.
	Book* CreateBook();

	Newspaper* CreateNewspaper();

	// Вернуть ссылку на экземпляр "одиночки", который и есть экземпляр фабрики.
	static ItemFactory& Instance();

	virtual ~ItemFactory();

private:

	// Единственный экземпляр "одиночки" - статическое поле
	static ItemFactory s_instance;

	// Счетчик созданных "продуктов" - печатных изданий.
	// Это поле объекта (не статическое поле). Оно предназначено для генерации
	// искусственных экземпляров печатных изданий.
	int _counter;

	// Закрытый конструктор для того, чтобы клиенты класса не могли создавать
	// экзепляры фабрики. Так реализуется шаблон проектирования "одиночка".
	ItemFactory();

};



#endif // !ITEMFACTORY_H
