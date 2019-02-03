Korean food is a react website with a node express.js backend. On the site, you can register a user, login and search for korean food dishes. 


# Exploit: 
There is no input validation or prepared statements being used on the SQL queries for login and searching (there is on registering a user for security purposes). On the search page, ' OR 1=1 -- (must be a space before and after the --) will get the flag.  

The second exploit is in the the usage of the login page. After a login attempt an object is logged to the user that has creditional information about the user. However, because of this, we can use a fairly complicated query to get the data from another table. Using a query such as the previous will log in the user, but to no avail. Using this query (' UNION select 1,description FROM korean_food; -- ) then viewing the console in the browser tools will return an object that has the flag in it. 

# Mitigation: 
Use prepared statements; there is an example of this in the register.js route. 