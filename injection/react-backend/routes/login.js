// PORT=3001 node bin/www
// each file is its own route!
var express = require("express");
var router = express.Router();
var mysql = require("mysql");

class Database {
  constructor(config) {
    this.connection = mysql.createConnection({
      host: "localhost",
      user: "-",
      password: "-",
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
  // ' OR 1=1 UNION SELECT * FROM Login WHERE '1' = '1 is a malicious payload
  // ' OR 1=1 --  (Fun fact, in mysql, there must be a space between the comment and the next character!)

  // vuln is here... At least, one of them is!
  const query =
    "SELECT * FROM Login WHERE username ='" +
    username +
    "' AND password = '" +
    password +
    "';";
  console.log(query);

  var database = new Database();

  // Might want to send an error message here...
  var rows = await database.query(query);
  database.close();
  return rows;
}

// Genterates a session token for the user.
function genToken(username) {
  // Session fixation
  return username;
}

// invalidate the session for the user
async function logout(username) {}

// Login for the user. Will return either "" or a valid session ID.
async function login(username, password) {
  const query_info = await loginQuery(username, password);
  if (query_info.length === 0) {
    return "";
  } else {
    const token = genToken(username);
    // store the token in the database.
    return token;
  }
}

/* GET users listing. */
router.post("/", async function(req, res, next) {
  // Comment out this line:

  const username = req.body.username;
  const password = req.body.password;
  const loginResponse = await login(username, password);
  res.send(loginResponse);
});

module.exports = router;
