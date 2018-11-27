// PORT=3001 node bin/www

var express = require("express");
var router = express.Router();
var mysql = require("mysql");

var connection = mysql.createConnection({
  host: "localhost",
  user: "-",
  password: "-",
  database: "injection"
});

// connection.query('SELECT * FROM Login', function(err, results) {
//     if (err) throw err
//     console.log(results);
// });

/* GET users listing. */
router.get("/", function(req, res, next) {
  // Comment out this line:
  //res.send('respond with a resource');

  // And insert something like this instead:
  res.json([
    {
      id: 1,
      username: "samsepi0l"
    },
    {
      id: 2,
      username: "D0loresH4ze"
    }
  ]);
});

module.exports = router;
