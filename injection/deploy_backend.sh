#!/bin/bash

SHUTDOWN=$(./shutdown_backend.sh)
echo "Deploying the backend..." 
cd ./react-backend
npm run start &
PID=$!
echo $PID > ".backend_pid"
