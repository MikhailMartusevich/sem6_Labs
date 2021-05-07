INSERT INTO Product VALUES -- Нарушение check
	('Ноутбук', -159.99);

INSERT INTO Product VALUES -- Нарушение уникальности ПК
	('Кофемашина', 159.99);

INSERT INTO Part VALUES -- Нарушение check
	('Гайка', 0)

INSERT INTO Asm VALUES -- Нарушение check
	('Кофемашина','Шланг', 0)

INSERT INTO Client VALUES -- Нарушение совместного ограничения
	('Huawei', null)

INSERT INTO Client VALUES -- Нарушение unique
	('Apple', 'США')

INSERT INTO Orders VALUES -- Нарушение check
	(6, '2077-01-01');


DELETE FROM Product -- Удаление из родительской таблицы
WHERE prod_name = 'Гриль'

DELETE FROM Asm	 -- Удаление из подчиненной таблицы
WHERE prod_name = 'Гриль'

INSERT INTO Asm VALUES
('Гриль', 'Нагреватель', 1)