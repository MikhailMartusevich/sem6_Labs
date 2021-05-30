CREATE TRIGGER Cascade_Delete_Product
ON Product
INSTEAD OF DELETE
AS
BEGIN

DECLARE 
	@Name NVARCHAR(20),
	@Date DATETIME,
	@Type NVARCHAR(6)

SELECT @Name = 'Product'
SELECT @Date = GETDATE()
SELECT @Type = 'CasDel'

DELETE FROM Asm 
WHERE Asm.prod_name IN (SELECT prod_name FROM deleted)

DELETE FROM Packaging
WHERE Packaging.prod_name IN (SELECT prod_name FROM deleted)

DELETE FROM Product
WHERE Product.prod_name IN (SELECT prod_name FROM deleted)

INSERT INTO Log(table_name, date, type) VALUES (
	@Name, @Date, @Type
)

END

--DROP TRIGGER Cascade_Delete_Product