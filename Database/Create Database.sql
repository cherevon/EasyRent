-- Удаление всех таблиц
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

-- районов и станций метро может быть много
-- можно создать запрос ддля поиска по нескольким городам (не важно какое метро, например)

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

insert into countries(sign, name) values('RUS', 'Российская федерация');
insert into countries(sign, name) values('ENG', 'Великобритания');
insert into countries(sign, name) values('USA', 'Соединенные Штаты Америки');

insert into cities(country, name) values('RUS', 'Москва');
insert into cities(country, name) values('RUS', 'Санкт-Петербург');
insert into cities(country, name) values('RUS', 'Новосибирск');
insert into cities(country, name) values('RUS', 'Екатеринбург');
insert into cities(country, name) values('RUS', 'Нижний Новгород');
insert into cities(country, name) values('RUS', 'Казань');
insert into cities(country, name) values('RUS', 'Челябинск');
insert into cities(country, name) values('RUS', 'Омск');
insert into cities(country, name) values('RUS', 'Самара');
insert into cities(country, name) values('RUS', 'Уфа');
insert into cities(country, name) values('RUS', 'Ростов-на-Дону');
insert into cities(country, name) values('RUS', 'Красноярск');
insert into cities(country, name) values('RUS', 'Пермь');
insert into cities(country, name) values('RUS', 'Воронеж');
insert into cities(country, name) values('RUS', 'Волгоград');
insert into cities(country, name) values('RUS', 'Саратов');
insert into cities(country, name) values('RUS', 'Краснодар');
insert into cities(country, name) values('RUS', 'Тольятти');
insert into cities(country, name) values('RUS', 'Тюмень');
insert into cities(country, name) values('RUS', 'Ижевск');
insert into cities(country, name) values('RUS', 'Барнаул');
insert into cities(country, name) values('RUS', 'Иркутск');
insert into cities(country, name) values('RUS', 'Ульяновск');
insert into cities(country, name) values('RUS', 'Хабаровск');
insert into cities(country, name) values('RUS', 'Владивосток');
insert into cities(country, name) values('RUS', 'Ярославль');
insert into cities(country, name) values('RUS', 'Махачкала');
insert into cities(country, name) values('RUS', 'Томск');
insert into cities(country, name) values('RUS', 'Оренбург');
insert into cities(country, name) values('RUS', 'Новокузнецк');
insert into cities(country, name) values('RUS', 'Кемерово');
insert into cities(country, name) values('RUS', 'Астрахань');
insert into cities(country, name) values('RUS', 'Рязань');
insert into cities(country, name) values('RUS', 'Набережные Челны');
insert into cities(country, name) values('RUS', 'Пенза');
insert into cities(country, name) values('RUS', 'Липецк');
insert into cities(country, name) values('RUS', 'Тула');
insert into cities(country, name) values('RUS', 'Киров');
insert into cities(country, name) values('RUS', 'Чебоксары');
insert into cities(country, name) values('RUS', 'Калининград');
insert into cities(country, name) values('RUS', 'Курск');
insert into cities(country, name) values('RUS', 'Улан-Удэ');
insert into cities(country, name) values('RUS', 'Ставрополь');
insert into cities(country, name) values('RUS', 'Магнитогорск');
insert into cities(country, name) values('RUS', 'Тверь');
insert into cities(country, name) values('RUS', 'Иваново');
insert into cities(country, name) values('RUS', 'Брянск');
insert into cities(country, name) values('RUS', 'Сочи');
insert into cities(country, name) values('RUS', 'Белгород');
insert into cities(country, name) values('RUS', 'Нижний Тагил');
insert into cities(country, name) values('RUS', 'Севастополь');
insert into cities(country, name) values('RUS', 'Архангельск');
insert into cities(country, name) values('RUS', 'Владимир');
insert into cities(country, name) values('RUS', 'Чита');
insert into cities(country, name) values('RUS', 'Калуга');
insert into cities(country, name) values('RUS', 'Сургут');
insert into cities(country, name) values('RUS', 'Симферополь');
insert into cities(country, name) values('RUS', 'Смоленск');
insert into cities(country, name) values('RUS', 'Волжский');
insert into cities(country, name) values('RUS', 'Курган');
insert into cities(country, name) values('RUS', 'Орёл');
insert into cities(country, name) values('RUS', 'Череповец');
insert into cities(country, name) values('RUS', 'Вологда');
insert into cities(country, name) values('RUS', 'Владикавказ');
insert into cities(country, name) values('RUS', 'Саранск');
insert into cities(country, name) values('RUS', 'Мурманск');
insert into cities(country, name) values('RUS', 'Якутск');
insert into cities(country, name) values('RUS', 'Тамбов');
insert into cities(country, name) values('RUS', 'Грозный');
insert into cities(country, name) values('RUS', 'Стерлитамак');
insert into cities(country, name) values('RUS', 'Кострома');
insert into cities(country, name) values('RUS', 'Петрозаводск');
insert into cities(country, name) values('RUS', 'Нижневартовск');
insert into cities(country, name) values('RUS', 'Йошкар-Ола');
insert into cities(country, name) values('RUS', 'Новороссийск');
insert into cities(country, name) values('RUS', 'Комсомольск-на-Амуре');
insert into cities(country, name) values('RUS', 'Таганрог');
insert into cities(country, name) values('RUS', 'Балашиха');
insert into cities(country, name) values('RUS', 'Сыктывкар');
insert into cities(country, name) values('RUS', 'Братск');
insert into cities(country, name) values('RUS', 'Нальчик');
insert into cities(country, name) values('RUS', 'Шахты');
insert into cities(country, name) values('RUS', 'Дзержинск');
insert into cities(country, name) values('RUS', 'Нижнекамск');
insert into cities(country, name) values('RUS', 'Орск');
insert into cities(country, name) values('RUS', 'Химки');
insert into cities(country, name) values('RUS', 'Ангарск');
insert into cities(country, name) values('RUS', 'Благовещенск');
insert into cities(country, name) values('RUS', 'Подольск');
insert into cities(country, name) values('RUS', 'Старый Оскол');
insert into cities(country, name) values('RUS', 'Великий Новгород');
insert into cities(country, name) values('RUS', 'Энгельс');
insert into cities(country, name) values('RUS', 'Псков');
insert into cities(country, name) values('RUS', 'Бийск');
insert into cities(country, name) values('RUS', 'Прокопьевск');
insert into cities(country, name) values('RUS', 'Рыбинск');
insert into cities(country, name) values('RUS', 'Балаково');
insert into cities(country, name) values('RUS', 'Южно-Сахалинск');
insert into cities(country, name) values('RUS', 'Армавир');
insert into cities(country, name) values('RUS', 'Королёв');
insert into cities(country, name) values('RUS', 'Северодвинск');
insert into cities(country, name) values('RUS', 'Люберцы');
insert into cities(country, name) values('RUS', 'Мытищи');
insert into cities(country, name) values('RUS', 'Петропавловск-Камчатский');
insert into cities(country, name) values('RUS', 'Норильск');
insert into cities(country, name) values('RUS', 'Сызрань');
insert into cities(country, name) values('RUS', 'Новочеркасск');
insert into cities(country, name) values('RUS', 'Абакан');
insert into cities(country, name) values('RUS', 'Каменск-Уральский');
insert into cities(country, name) values('RUS', 'Златоуст');
insert into cities(country, name) values('RUS', 'Волгодонск');
insert into cities(country, name) values('RUS', 'Уссурийск');
insert into cities(country, name) values('RUS', 'Электросталь');
insert into cities(country, name) values('RUS', 'Находка');
insert into cities(country, name) values('RUS', 'Салават');
insert into cities(country, name) values('RUS', 'Железнодорожный');
insert into cities(country, name) values('RUS', 'Миасс');
insert into cities(country, name) values('RUS', 'Альметьевск');
insert into cities(country, name) values('RUS', 'Березники');
insert into cities(country, name) values('RUS', 'Керчь');
insert into cities(country, name) values('RUS', 'Рубцовск');
insert into cities(country, name) values('RUS', 'Пятигорск');
insert into cities(country, name) values('RUS', 'Майкоп');
insert into cities(country, name) values('RUS', 'Коломна');
insert into cities(country, name) values('RUS', 'Копейск');
insert into cities(country, name) values('RUS', 'Ковров');
insert into cities(country, name) values('RUS', 'Одинцово');
insert into cities(country, name) values('RUS', 'Хасавюрт');
insert into cities(country, name) values('RUS', 'Красногорск');
insert into cities(country, name) values('RUS', 'Кисловодск');
insert into cities(country, name) values('RUS', 'Новомосковск');
insert into cities(country, name) values('RUS', 'Серпухов');
insert into cities(country, name) values('RUS', 'Нефтеюганск');
insert into cities(country, name) values('RUS', 'Первоуральск');
insert into cities(country, name) values('RUS', 'Новочебоксарск');
insert into cities(country, name) values('RUS', 'Черкесск');
insert into cities(country, name) values('RUS', 'Нефтекамск');
insert into cities(country, name) values('RUS', 'Дербент');
insert into cities(country, name) values('RUS', 'Орехово-Зуево');
insert into cities(country, name) values('RUS', 'Димитровград');
insert into cities(country, name) values('RUS', 'Невинномысск');
insert into cities(country, name) values('RUS', 'Батайск');
insert into cities(country, name) values('RUS', 'Новый Уренгой');
insert into cities(country, name) values('RUS', 'Щёлково');
insert into cities(country, name) values('RUS', 'Камышин');
insert into cities(country, name) values('RUS', 'Кызыл');
insert into cities(country, name) values('RUS', 'Октябрьский');
insert into cities(country, name) values('RUS', 'Муром');
insert into cities(country, name) values('RUS', 'Новошахтинск');
insert into cities(country, name) values('RUS', 'Обнинск');
insert into cities(country, name) values('RUS', 'Северск');
insert into cities(country, name) values('RUS', 'Домодедово');
insert into cities(country, name) values('RUS', 'Жуковский');
insert into cities(country, name) values('RUS', 'Ноябрьск');
insert into cities(country, name) values('RUS', 'Сергиев Посад');
insert into cities(country, name) values('RUS', 'Ачинск');
insert into cities(country, name) values('RUS', 'Новокуйбышевск');
insert into cities(country, name) values('RUS', 'Каспийск');
insert into cities(country, name) values('RUS', 'Евпатория');
insert into cities(country, name) values('RUS', 'Елец');
insert into cities(country, name) values('RUS', 'Назрань');
insert into cities(country, name) values('RUS', 'Пушкино');
insert into cities(country, name) values('RUS', 'Арзамас');
insert into cities(country, name) values('RUS', 'Элиста');
insert into cities(country, name) values('RUS', 'Ессентуки');
insert into cities(country, name) values('RUS', 'Раменское');
insert into cities(country, name) values('RUS', 'Бердск');
insert into cities(country, name) values('RUS', 'Артём');
insert into cities(country, name) values('RUS', 'Ногинск');

INSERT INTO er_users(surname, name, patronymic, username, pswd, city_id) VALUES ('Черевичко', 'Сергей', 'Андреевич', 'cherevon', 'DD15672EABBB1189207DEFABC', 10);