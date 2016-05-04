CREATE TABLE IF NOT EXISTS er_objects (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        obj_type VARCHAR(10) NOT NULL,
        city VARCHAR(255) NOT NULL,
        address VARCHAR(255),
        first_floor INT NOT NULL,
        floor_count INT NOT NULL,
        square_total FLOAT NOT NULL,
        contact VARCHAR(255),
        additional_info VARCHAR(5000)
);


CREATE TABLE IF NOT EXISTS er_room_types (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name VARCHAR(20) NOT NULL
);
INSERT INTO er_room_types(name) VALUES("Комната");
INSERT INTO er_room_types(name) VALUES("Кухня");


CREATE TABLE IF NOT EXISTS er_object_rooms (
        obj_id INTEGER NOT NULL REFERENCES er_objects(id),
        room_type INTEGER NOT NULL REFERENCES er_room_types(id),
        square FLOAT NOT NULL
);


CREATE TABLE IF NOT EXISTS er_object_photos (
        obj_id INTEGER NOT NULL REFERENCES er_objects(id),
        photo BLOB NOT NULL
);


CREATE TABLE IF NOT EXISTS er_query_types (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name VARCHAR(25) NOT NULL
);
INSERT INTO er_query_types(name) VALUES("Продажа");
INSERT INTO er_query_types(name) VALUES("Покупка");
INSERT INTO er_query_types(name) VALUES("Продажа (аренда)");
INSERT INTO er_query_types(name) VALUES("Покупка (аренда)");


CREATE TABLE IF NOT EXISTS er_priority_queries (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        query_type INTEGER NOT NULL REFERENCES er_query_types(id),
        create_date TIMESTAMP NOT NULL,
        price INTEGER NOT NULL,
        source VARCHAR(255),
        search_object INTEGER REFERENCES er_objects(id)
);


/*
ОТКАТ СКРИПТА

DROP TABLE er_object_photos;
DROP TABLE er_priority_queries;
DROP TABLE er_query_types;
DROP TABLE er_object_rooms;
DROP TABLE er_room_types;
DROP TABLE er_objects;
*/