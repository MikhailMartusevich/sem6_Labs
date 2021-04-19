SELECT * FROM Изделия ORDER BY Изделия.Стоимость


SELECT Изделия.[Наименование изделия] FROM Изделия
UNION
SELECT Комплектация.[Наименование изделия] FROM Комплектация

SELECT * FROM Заказы

SELECT ALL Заказы.Количество, COUNT(*) AS COUNTER 
FROM Заказы
GROUP BY Заказы.Количество