Select * from Part;
Select * from PartArchive;

EXEC Archive_Parts

INSERT INTO Part(part_name, part_price) VALUES
('�����', 9.999)

UPDATE Part
set isArchived = 'N'

DELETE FROM Part
WHERE part_name = '�����'

DELETE FROM PartArchive
