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
    (001, 'Kimchi 김치', 1.99, "Chili Pickled Cabbage"),
    (002, 'Samgyeopsal 삼겹살', 6.99, "Grilled Pork Belly"),
    (003, 'Daeji Bulgogi 불고기', 6.99, "Sweet BBQ Pork"),
    (004, 'Sundubu Jjigae 순두부 찌게', 5.99, "Tofu Stew"),
    (005, 'Kimchi Jjigae 김치 찌개', 4.99, "Kimchi Stew"),
    (006, 'Seolleongtang 설렁탕', 7.99, "Ox Tale Soup"),
    (007, 'Bibimbap 비빔밥', 5.99, "Korean Fried Rice"),
    (008, 'Kimchi Bokkeumbap 김치 볶음밥', 4.99, "Kimichi Fried Rice"),
    (009, 'Yaki Mandu 만두', 2.99, "Deep Fried Dumplings"),
    (010, 'Mul Naengmyeon 물 냉면', 4.99, "Cold Noodle Soup"),
    (011, 'Japchae 잡채', 2.99, "Fried Sweet Potato Noodles"),
    (012, 'Soondae 순대', 4.99, "Korean Blood Sausage"),
    (013, 'Gimbap 김밥', 2.99, "Korean Rolls"),
    (014, 'Tteokbokki 떡볶이', 2.99, "Spicy Rice Cakes"),
    (015, 'Jjajangmyeon 짜장면', 5.99, "Black Bean Noodles"),
    (016, 'Galbi 갈비', 12.99, "Korean Ribs"),
    (12121323, '', 10.00,"flag: asdfasfd");
