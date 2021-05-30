SELECT * FROM Product
SELECT * FROM Asm
SELECT * FROM Packaging

DELETE FROM Product
WHERE prod_name = 'Чайник'

INSERT INTO Product VALUES
	('Чайник', 7.90);

INSERT INTO Asm VALUES
	('Чайник', 'Провод', 1);

INSERT INTO Packaging VALUES
	(1006, 'Чайник');

select * from Log