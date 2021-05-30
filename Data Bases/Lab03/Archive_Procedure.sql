CREATE PROC Archive_Parts
AS
BEGIN

	INSERT INTO PartArchive (part_name, part_price)
	SELECT part_name, part_price 
	FROM Part
	WHERE isArchived = 'N'

	UPDATE PartArchive
	SET archive_date = GETDATE()
	WHERE archive_date IS NULL;
	

	UPDATE Part
	SET isArchived = 'Y'
	WHERE isArchived = 'N'

END