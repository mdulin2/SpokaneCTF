DROP TABLE IF EXISTS korean_food;

CREATE TABLE korean_food
(
    food_id INT NOT NULL,
    food_name VARCHAR(30),
    price DECIMAL(5,2),
    description TEXT,
    PRIMARY KEY (food_id)
);

INSERT INTO korean_food
VALUES
    (001, 'Galbi', 23.95, ""),
    (002, 'Dwaeji Galbi', 17.95,""),
    (003, 'Bulgogi', 17.95,""),
    (12121323, '', 10.00,"flag: asdfasfd");
