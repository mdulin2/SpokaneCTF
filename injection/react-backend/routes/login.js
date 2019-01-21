// PORT=3001 node bin/www
// each file is its own route!
var express = require("express");
var router = express.Router();
var mysql = require("mysql");
var pbkdf2 = require('pbkdf2');
var rand = require('csprng');

class Database {
  constructor(config) {
    this.connection = mysql.createConnection({
      host: "localhost",
      user: "root",
      password: "Airjordan23",
      database: "injection"
    });
  }
  query(sql, args) {
    return new Promise((resolve, reject) => {
      this.connection.query(sql, args, (err, rows) => {
        if (err) return reject(err);
        resolve(rows);
      });
    });
  }
  close() {
    return new Promise((resolve, reject) => {
      this.connection.end(err => {
        if (err) return reject(err);
        resolve();
      });
    });
  }
}

// returns a promise of a query
async function loginQuery(username, password) {
  // ' UNION SELECT food_id,description FROM korean_food --  is a malicious payload
  // ' OR 1=1 --  (Fun fact, in mysql, there must be a space between the comment and the next character!)

  // vuln is here... At least, one of them is!
  const query =
    "SELECT * FROM Login WHERE username ='" +
    username +
    "' AND password = '" +
    password +
    "';";

  var database = new Database();

  // Might want to send an error message here...
  var rows = await database.query(query);
  database.close();
  return rows;
}

// Login for the user. Will return either "" or a valid session ID.
async function login(username, password) {
  const query_info = await loginQuery(username, password);
  if (query_info.length === 0) {
    return "";
  } else {

    // store the token in the database.
    const token = username;
    return query_info;
  }
}

/* GET users listing. */
router.post("/", async function(req, res, next) {

  const username = req.body.username;
  const password = req.body.password;

  // Hashes the password, with a static salt value.
  const derivedKey = pbkdf2.pbkdf2Sync(password, 'somesalt...', 1, 32, 'sha512').toString('base64');
  const loginResponse = await login(username, derivedKey);

  // sends the login result back to the user
  res.send(loginResponse);
});

module.exports = router;
