#!/bin/bash

echo "Starting the frontend..."
cd ./client 
yarn start &

PID=$!
echo $PID > .client_pid
