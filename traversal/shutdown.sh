#!/usr/bin/env bash

# Get the process ID
commandx=$(sudo netstat -ap | grep 24779)
echo $commandx
process_tmp=$(echo ${commandx} | cut  -d ' ' -f 7)
echo $process_tmp
process=$(echo $process_tmp | cut -c 1-4)
echo $process

# Leave if the process does not exist
if [[ -z "$process" ]]; then
    echo "Nothing to shut down..."
    exit 1
fi

# Kill the process if the process exists
echo "Killing process ${process}..."
kill -9 $process
echo "Shut down!"
