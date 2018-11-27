DROP TABLE IF EXISTS session;

CREATE TABLE session(
    username    VARCHAR(200) NOT NULL,
    token       VARCHAR(200) NOT NULL,
    -- should be a date here?
    PRIMARY KEY(username)
);

INSERT INTO Session(username, token) VALUES
    ('peanuts', 'snoopy');
