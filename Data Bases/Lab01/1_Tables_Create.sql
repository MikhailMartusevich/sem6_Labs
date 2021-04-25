USE Manufacture

CREATE TABLE Изделия (
	[Наименование изделия] NVARCHAR(20) NOT NULL,
	[Стоимость] INTEGER DEFAULT 0
)

CREATE TABLE Комплектация (
	[Наименование изделия] NVARCHAR(20) NOT NULL,
	[Наименование комплектующего] NVARCHAR(20)NOT NULL,
	[Количество] INTEGER DEFAULT 0
)

CREATE TABLE Комплектующее (
	[Наименование комплектующего] NVARCHAR(20)NOT NULL,
	[Стоимость] INTEGER DEFAULT 0
)

CREATE TABLE Заказы (
	[Наименование изделия] NVARCHAR(20) NOT NULL,
	[Количество] INTEGER DEFAULT 0
)