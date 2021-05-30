CREATE TRIGGER Client_Log_Trigger
ON Client
AFTER INSERT, UPDATE, DELETE
AS
BEGIN

DECLARE
	@Name NVARCHAR(20),
	@Date DATETIME,
	@Type CHAR(6)

SELECT @Date = GETDATE();
SELECT @Name = 'Client'
IF EXISTS(SELECT * FROM inserted)
	BEGIN
		IF EXISTS(SELECT * FROM deleted)
		BEGIN
			SELECT @Type = 'Update'
		END
		ELSE
		BEGIN
			SELECT @Type = 'Insert'
		END
	END
ELSE
BEGIN
	SELECT @Type = 'Delete'
END

INSERT INTO Log(table_name, date, type) VALUES (
	@Name, @Date, @Type
)

END

--DROP TRIGGER Client_Log_Trigger