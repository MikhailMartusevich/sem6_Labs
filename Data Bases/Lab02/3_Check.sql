INSERT INTO Product VALUES -- ��������� check
	('�������', -159.99);

INSERT INTO Product VALUES -- ��������� ������������ ��
	('����������', 159.99);

INSERT INTO Part VALUES -- ��������� check
	('�����', 0)

INSERT INTO Asm VALUES -- ��������� check
	('����������','�����', 0)

INSERT INTO Client VALUES -- ��������� ����������� �����������
	('Huawei', null)

INSERT INTO Client VALUES -- ��������� unique
	('Apple', '���')

INSERT INTO Orders VALUES -- ��������� check
	(6, '2077-01-01');


DELETE FROM Product -- �������� �� ������������ �������
WHERE prod_name = '�����'

DELETE FROM Asm	 -- �������� �� ����������� �������
WHERE prod_name = '�����'

INSERT INTO Asm VALUES
('�����', '�����������', 1)