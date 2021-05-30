CREATE TABLE PartArchive (
	part_name NVARCHAR(20) NULL UNIQUE,
	part_price MONEY NULL,
	archive_date DATETIME NULL
);

--DROP TABLE PartArchive