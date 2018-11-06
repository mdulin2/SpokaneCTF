CREATE TABLE Login(
    username varchar(200) not null,
    password varchar(200),
    PRIMARY KEY(username)
);

INSERT INTO Login(username, password)
VALUES('Andrew','doomsday');
