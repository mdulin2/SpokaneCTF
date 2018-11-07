CREATE TABLE Session(
    username varchar(200) not null,
    token varchar(200) not null,
    -- should be a date here?
    PRIMARY KEY(username)
);

INSERT INTO Session(username, token)
VALUES('Andrew','doomsday');
