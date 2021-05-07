USE Manufacture;


-- Таблица товаров
CREATE TABLE Product (
	prod_name NVARCHAR(20) NOT NULL PRIMARY KEY,	-- Наименование товара (ПК)
	prod_price MONEY NULL,							-- Стоимость товара
	CHECK(prod_price > 0)							-- Ограничение стоимости (не может быть отрицательным и равным нулю)
);


-- Таблица комплектующих
CREATE TABLE Part (
	part_name NVARCHAR(20) NOT NULL PRIMARY KEY,	-- Наименование комплектующего (ПК)
	part_price MONEY NULL,							-- Стоимость комплектующих
	CHECK(part_price > 0)							-- Ограничение стоимости (не может быть отрицательным и равным нулю)
);


-- Связующая таблица "Сборка"
-- Вид отношения: Многие ко многим между таблицами Product и Part
CREATE TABLE Asm (
	prod_name NVARCHAR(20) NOT NULL FOREIGN KEY REFERENCES Product(prod_name),	-- Наименование товара (ВК для таблицы товаров)
	part_name NVARCHAR(20) NOT NULL FOREIGN KEY REFERENCES Part(part_name),		-- Наименование комплектующего (ВК для таблицы комплектующих)
	part_count INTEGER NULL,													-- Количество комплектующих
	CHECK(part_count > 0)														-- Ограничение количества (не может быть отрицательным и равным нулю)
);


-- Таблица клиентов
CREATE TABLE Client (
	client_id INTEGER NOT NULL PRIMARY KEY IDENTITY(1,1),							-- Идентификатор клиента (ПК)
	client_name NVARCHAR(20) NULL UNIQUE,											-- Имя клиента (Уникальное значение)
	country NVARCHAR(20) NULL,														-- Страна клиента
	CONSTRAINT client_info CHECK (client_name IS NOT NULL AND country IS NOT NULL)	-- Совместное ограничение для столбцов Имя и Страна
);


-- Таблица заказов
CREATE TABLE Orders (
	order_number INTEGER NOT NULL PRIMARY KEY IDENTITY (1001, 1),			-- Идентификатор заказа (ПК)
	client_id INTEGER NOT NULL FOREIGN KEY REFERENCES Client(client_id),	-- Идентификатор клиента (ВК для таблицы клиентов)
	order_date DATE NULL													-- Дата заказа
	CHECK(order_date < GETDATE())											-- Проверка даты (не позже текущей даты)
);

-- Связующая таблица "Упаковка"
-- Вид отношения: Многие ко многим между таблицами Product и Orders
CREATE TABLE Packaging (
	order_number INTEGER NOT NULL FOREIGN KEY REFERENCES Orders(order_number),
	prod_name NVARCHAR(20) NOT NULL FOREIGN KEY REFERENCES Product(prod_name)
);
