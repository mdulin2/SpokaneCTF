#!/bin/bash

echo "Shutting down backend..."
BACKEND_PID=$(ps -f | grep "node ./bin/www" | grep -v "sh" | grep -v "grep" | cut -d" " -f2)

if [ -z $BACKEND_PID ]; then 
	echo "No such process" 
	exit 0
fi

RESULT=$(kill -9 $BACKEND_PID)
exit 0 

