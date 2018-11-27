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
// payload: ' UNION SELECT 1, concat(username, password), 1 FROM login; --
async function foodQuery(food_name) {
  const query =
    "SELECT * FROM korean_food WHERE food_name LIKE '%" + food_name + "%';";
  console.log(query);

  var database = new Database();

  // Might want to send an error message here...
  var rows = await database.query(query);
  database.close();
  return rows;
}

/* GET foods listing. */
router.post("/", async function(req, res, next) {
  // Comment out this line:

  const food_name = req.body.food_name;
  const foodResponse = await foodQuery(food_name);
  res.send(foodResponse);
});

module.exports = router;
