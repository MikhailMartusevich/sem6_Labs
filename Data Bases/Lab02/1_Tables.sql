USE Manufacture;


-- ������� �������
CREATE TABLE Product (
	prod_name NVARCHAR(20) NOT NULL PRIMARY KEY,	-- ������������ ������ (��)
	prod_price MONEY NULL,							-- ��������� ������
	CHECK(prod_price > 0)							-- ����������� ��������� (�� ����� ���� ������������� � ������ ����)
);


-- ������� �������������
CREATE TABLE Part (
	part_name NVARCHAR(20) NOT NULL PRIMARY KEY,	-- ������������ �������������� (��)
	part_price MONEY NULL,							-- ��������� �������������
	CHECK(part_price > 0)							-- ����������� ��������� (�� ����� ���� ������������� � ������ ����)
);


-- ��������� ������� "������"
-- ��� ���������: ������ �� ������ ����� ��������� Product � Part
CREATE TABLE Asm (
	prod_name NVARCHAR(20) NOT NULL FOREIGN KEY REFERENCES Product(prod_name),	-- ������������ ������ (�� ��� ������� �������)
	part_name NVARCHAR(20) NOT NULL FOREIGN KEY REFERENCES Part(part_name),		-- ������������ �������������� (�� ��� ������� �������������)
	part_count INTEGER NULL,													-- ���������� �������������
	CHECK(part_count > 0)														-- ����������� ���������� (�� ����� ���� ������������� � ������ ����)
);


-- ������� ��������
CREATE TABLE Client (
	client_id INTEGER NOT NULL PRIMARY KEY IDENTITY(1,1),							-- ������������� ������� (��)
	client_name NVARCHAR(20) NULL UNIQUE,											-- ��� ������� (���������� ��������)
	country NVARCHAR(20) NULL,														-- ������ �������
	CONSTRAINT client_info CHECK (client_name IS NOT NULL AND country IS NOT NULL)	-- ���������� ����������� ��� �������� ��� � ������
);


-- ������� �������
CREATE TABLE Orders (
	order_number INTEGER NOT NULL PRIMARY KEY IDENTITY (1001, 1),			-- ������������� ������ (��)
	client_id INTEGER NOT NULL FOREIGN KEY REFERENCES Client(client_id),	-- ������������� ������� (�� ��� ������� ��������)
	order_date DATE NULL													-- ���� ������
	CHECK(order_date < GETDATE())											-- �������� ���� (�� ����� ������� ����)
);

-- ��������� ������� "��������"
-- ��� ���������: ������ �� ������ ����� ��������� Product � Orders
CREATE TABLE Packaging (
	order_number INTEGER NOT NULL FOREIGN KEY REFERENCES Orders(order_number),
	prod_name NVARCHAR(20) NOT NULL FOREIGN KEY REFERENCES Product(prod_name)
);
