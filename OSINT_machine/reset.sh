#!/usr/bin/env bash

echo "Are you sure you want to reset this file?"
echo "Type 'y' to reset"
read response
if [[ "$response" != "y" ]]; then
    echo "Reset cancelled..."
    exit 1
fi

./shutdown.sh
# Will need to need to make this private...and the replace file...
cp .replace MessageStorer.py

echo "Reset Complete"
