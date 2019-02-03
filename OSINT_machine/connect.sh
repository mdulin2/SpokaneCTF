#!/bin/bash

IP=$1
Port=$2

if [[ -z "$IP" ]]; then
    echo "Usage: connect.sh IP_ADDRESS"
    exit 1
fi

if [[ -z "$Port" ]]; then
    netcat $IP 24779
    exit 1
fi

netcat $IP $Port
