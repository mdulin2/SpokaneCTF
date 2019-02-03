#!/bin/bash

PID=$(ps -f | grep "scripts/start.js"  | grep "grep" -v | cut -d" " -f2)

if [ -z $PID ]; then 
	echo "The PID does not exist" 
	exit 0
fi 

echo "Remember, changing to the frontend are rendered dynamically..." 
echo "Shutting down the frontend..."
RESULT=$(kill -9 $PID)

