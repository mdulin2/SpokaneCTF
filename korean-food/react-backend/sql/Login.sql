DROP TABLE IF EXISTS login;

CREATE TABLE Login(
    username    VARCHAR(200) NOT NULL,
    password    VARCHAR(200),
    PRIMARY KEY(username)
);

INSERT INTO login(username, password) VALUES
    ('peanuts','snoopy');
