-- �������� ���� ������
--DROP TABLE cities;
--DROP TABLE city_areas;
--DROP TABLE city_metros;
--DROP TABLE countries;
--DROP TABLE er_object_types;
--DROP TABLE er_pq_areas;
--DROP TABLE er_pq_metros;
--DROP TABLE er_pq_cities;
--DROP TABLE er_user_emails;
--DROP TABLE er_user_query_types;
--DROP TABLE er_users;

CREATE TABLE countries
(
	sign VARCHAR(5) NOT NULL PRIMARY KEY,
	name VARCHAR(100) NOT NULL
);

CREATE UNIQUE INDEX idx_countries_name ON countries(name);

---------------------------------------------------------------------------------------------------------

CREATE TABLE cities
(
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
	country VARCHAR(5) NOT NULL,
	name VARCHAR(100) NOT NULL,
	FOREIGN KEY(country) REFERENCES countries(sign)
);

CREATE INDEX idx_cities_country ON cities(country);
CREATE INDEX idx_cities_name ON cities(name);

---------------------------------------------------------------------------------------------------------

CREATE TABLE city_metros
(
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
	metro_name VARCHAR(100) NOT NULL,
	city_id INT NOT NULL,
	FOREIGN KEY(city_id) REFERENCES cities(id)
);

CREATE INDEX idx_city_metros_metro_name ON city_metros(metro_name);
CREATE INDEX idx_city_metros_city_id ON city_metros(city_id);

---------------------------------------------------------------------------------------------------------

CREATE TABLE city_areas
(
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
	area_name VARCHAR(100) NOT NULL,
	city_id INT NOT NULL,
	FOREIGN KEY(city_id) REFERENCES cities(id)
);

CREATE INDEX idx_city_areas_area_name ON city_areas(area_name);
CREATE INDEX idx_city_areas_city_id ON city_areas(city_id);

---------------------------------------------------------------------------------------------------------

CREATE TABLE er_user_query_types
(
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
	name VARCHAR(20) NOT NULL
);

CREATE INDEX idx_er_user_query_types_name ON er_user_query_types(name);

---------------------------------------------------------------------------------------------------------

CREATE TABLE er_object_types
(
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
	sign VARCHAR(50) NOT NULL,
	name VARCHAR(150) NOT NULL
);

CREATE UNIQUE INDEX idx_er_object_types_sign ON er_object_types(sign);

---------------------------------------------------------------------------------------------------------

CREATE TABLE er_users
(
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
	surname VARCHAR(100) NOT NULL,
	name VARCHAR(100) NOT NULL,
	patronymic VARCHAR(100),
	username VARCHAR(50) NOT NULL,
	pswd VARCHAR(255) NOT NULL,
	city_id INT NOT NULL,
	FOREIGN KEY (city_id) REFERENCES cities(id)
);

CREATE UNIQUE INDEX idx_er_users_username ON er_users(username);

---------------------------------------------------------------------------------------------------------

-- ������� � ������� ����� ����� ���� �����
-- ����� ������� ������ ���� ������ �� ���������� ������� (�� ����� ����� �����, ��������)

CREATE TABLE er_priority_queries
(
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
	user_id INT NOT NULL,
	type_id INT NOT NULL,
	object_type INT,
	telephone BIT,
	fridge BIT,
	washer BIT,
	furniture BIT,
	rooms_from INT,
	rooms_to INT,
	period INT,
	price_from INT,
	price_to INT,
	create_date DATETIME NOT NULL DEFAULT GETDATE(),
	last_search_date DATETIME,
	additional_info VARCHAR(MAX),
	FOREIGN KEY (user_id) REFERENCES er_users(id),
	FOREIGN KEY (type_id) REFERENCES er_user_query_types(id),
	FOREIGN KEY (object_type) REFERENCES er_object_types(id)
);

CREATE INDEX idx_er_priority_queries_user_id ON er_priority_queries(user_id);
CREATE INDEX idx_er_priority_queries_type_id ON er_priority_queries(type_id);
CREATE INDEX idx_er_priority_queries_object_type ON er_priority_queries(object_type);

---------------------------------------------------------------------------------------------------------

CREATE TABLE er_pq_cities
(
	pq_id INT NOT NULL,
	city_id INT NOT NULL,
	FOREIGN KEY (pq_id) REFERENCES er_priority_queries(id),
	FOREIGN KEY (city_id) REFERENCES cities(id)
);

CREATE INDEX idx_er_pq_cities_pq_id ON er_pq_cities(pq_id);
CREATE INDEX idx_er_pq_cities_city_id ON er_pq_cities(city_id);
CREATE UNIQUE INDEX idx_er_pq_cities_pqcity ON er_pq_cities(pq_id, city_id);

---------------------------------------------------------------------------------------------------------

CREATE TABLE er_pq_areas
(
	pq_id INT NOT NULL,
	area_id INT NOT NULL,
	FOREIGN KEY (pq_id) REFERENCES er_priority_queries(id),
	FOREIGN KEY (area_id) REFERENCES city_areas(id)
);

CREATE INDEX idx_er_pq_areas_pq_id ON er_pq_cities(pq_id);
CREATE INDEX idx_er_pq_areas_area_id ON er_pq_areas(area_id);
CREATE UNIQUE INDEX idx_er_pq_areas_pqarea ON er_pq_areas(pq_id, area_id);

---------------------------------------------------------------------------------------------------------

CREATE TABLE er_pq_metros
(
	pq_id INT NOT NULL,
	metro_id INT NOT NULL,
	FOREIGN KEY (pq_id) REFERENCES er_priority_queries(id),
	FOREIGN KEY (metro_id) REFERENCES city_metros(id)
);

CREATE INDEX idx_er_pq_metros_pq_id ON er_pq_cities(pq_id);
CREATE INDEX idx_er_pq_metros_metro_id ON er_pq_metros(metro_id);
CREATE UNIQUE INDEX idx_er_pq_metros_pqmetro ON er_pq_metros(pq_id, metro_id);

---------------------------------------------------------------------------------------------------------

CREATE TABLE er_user_emails
(
	user_id INT NOT NULL,
	email VARCHAR(100) NOT NULL,
	FOREIGN KEY (user_id) REFERENCES er_users(id)
);

CREATE UNIQUE INDEX idx_er_user_emails_email ON er_user_emails(email);
CREATE INDEX idx_er_user_emails_user_id ON er_user_emails(user_id);

---------------------------------------------------------------------------------------------------------

insert into countries(sign, name) values('RUS', '���������� ���������');
insert into countries(sign, name) values('ENG', '��������������');
insert into countries(sign, name) values('USA', '����������� ����� �������');

insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '�����-���������');
insert into cities(country, name) values('RUS', '�����������');
insert into cities(country, name) values('RUS', '������������');
insert into cities(country, name) values('RUS', '������ ��������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '����');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '���');
insert into cities(country, name) values('RUS', '������-��-����');
insert into cities(country, name) values('RUS', '����������');
insert into cities(country, name) values('RUS', '�����');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '�����������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '�����');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '�����������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '���������� �����');
insert into cities(country, name) values('RUS', '�����');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '����');
insert into cities(country, name) values('RUS', '�����');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '�����������');
insert into cities(country, name) values('RUS', '�����');
insert into cities(country, name) values('RUS', '����-���');
insert into cities(country, name) values('RUS', '����������');
insert into cities(country, name) values('RUS', '������������');
insert into cities(country, name) values('RUS', '�����');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '����');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '������ �����');
insert into cities(country, name) values('RUS', '�����������');
insert into cities(country, name) values('RUS', '�����������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '����');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '�����������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '���');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '�����������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '�����������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '������������');
insert into cities(country, name) values('RUS', '�������������');
insert into cities(country, name) values('RUS', '������-���');
insert into cities(country, name) values('RUS', '������������');
insert into cities(country, name) values('RUS', '�����������-��-�����');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '�����');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '����������');
insert into cities(country, name) values('RUS', '����');
insert into cities(country, name) values('RUS', '�����');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '������������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '������ �����');
insert into cities(country, name) values('RUS', '������� ��������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '�����');
insert into cities(country, name) values('RUS', '�����');
insert into cities(country, name) values('RUS', '�����������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '����-���������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '������������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '�������������-����������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '������������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '�������-���������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '����������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '������������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '���������������');
insert into cities(country, name) values('RUS', '�����');
insert into cities(country, name) values('RUS', '�����������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '�����');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '�����������');
insert into cities(country, name) values('RUS', '����������');
insert into cities(country, name) values('RUS', '������������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '�����������');
insert into cities(country, name) values('RUS', '������������');
insert into cities(country, name) values('RUS', '��������������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '����������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '�������-�����');
insert into cities(country, name) values('RUS', '������������');
insert into cities(country, name) values('RUS', '������������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '����� �������');
insert into cities(country, name) values('RUS', 'ٸ�����');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '�����');
insert into cities(country, name) values('RUS', '�����������');
insert into cities(country, name) values('RUS', '�����');
insert into cities(country, name) values('RUS', '������������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '����������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '������� �����');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '��������������');
insert into cities(country, name) values('RUS', '��������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '����');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '�������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '���������');
insert into cities(country, name) values('RUS', '������');
insert into cities(country, name) values('RUS', '����');
insert into cities(country, name) values('RUS', '�������');

INSERT INTO er_users(surname, name, patronymic, username, pswd, city_id) VALUES ('���������', '������', '���������', 'cherevon', 'DD15672EABBB1189207DEFABC', 10);