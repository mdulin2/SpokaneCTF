#!/usr/bin/env bash

# Get the process ID
process=$(pgrep python)

# Leave if the process does not exist
if [[ -z "$process" ]]; then
    echo "Nothing to shut down..."
    exit 1
fi

# Kill the process if the process exists
echo "Killing process ${process}..."
kill -9 $process
echo "Shut down!"
