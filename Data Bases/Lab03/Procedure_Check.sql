Select * from Part;
Select * from PartArchive;

EXEC Archive_Parts

INSERT INTO Part(part_name, part_price) VALUES
('Труба', 9.999)

UPDATE Part
set isArchived = 'N'

DELETE FROM Part
WHERE part_name = 'Труба'

DELETE FROM PartArchive
