USE Manufacture

CREATE TABLE Изделия (
	[Наименование изделия] NVARCHAR(20) NOT NULL PRIMARY KEY,
	[Стоимость] INTEGER DEFAULT 0
)

CREATE TABLE Комплектация (
	[Наименование изделия] NVARCHAR(20) NOT NULL FOREIGN KEY REFERENCES Изделия([Наименование изделия]),
	[Наименование комплектующего] NVARCHAR(20) NOT NULL PRIMARY KEY,
	[Количество] INTEGER DEFAULT 0
)

CREATE TABLE Комплектующее (
	[Наименование комплектующего] NVARCHAR(20) NOT NULL FOREIGN KEY REFERENCES Комплектация([Наименование комплектующего]),
	[Стоимость] INTEGER DEFAULT 0
)

CREATE TABLE Заказы (
	[Наименование изделия] NVARCHAR(20) NOT NULL FOREIGN KEY REFERENCES Изделия([Наименование изделия]),
	[Количество] INTEGER DEFAULT 0
)