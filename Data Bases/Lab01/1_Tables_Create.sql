USE Manufacture

CREATE TABLE ������� (
	[������������ �������] NVARCHAR(20) NOT NULL PRIMARY KEY,
	[���������] INTEGER DEFAULT 0
)

CREATE TABLE ������������ (
	[������������ �������] NVARCHAR(20) NOT NULL FOREIGN KEY REFERENCES �������([������������ �������]),
	[������������ ��������������] NVARCHAR(20) NOT NULL PRIMARY KEY,
	[����������] INTEGER DEFAULT 0
)

CREATE TABLE ������������� (
	[������������ ��������������] NVARCHAR(20) NOT NULL FOREIGN KEY REFERENCES ������������([������������ ��������������]),
	[���������] INTEGER DEFAULT 0
)

CREATE TABLE ������ (
	[������������ �������] NVARCHAR(20) NOT NULL FOREIGN KEY REFERENCES �������([������������ �������]),
	[����������] INTEGER DEFAULT 0
)