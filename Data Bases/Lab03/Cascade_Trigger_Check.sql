SELECT * FROM Product
SELECT * FROM Asm
SELECT * FROM Packaging

DELETE FROM Product
WHERE prod_name = '������'

INSERT INTO Product VALUES
	('������', 7.90);

INSERT INTO Asm VALUES
	('������', '������', 1);

INSERT INTO Packaging VALUES
	(1006, '������');

select * from Log