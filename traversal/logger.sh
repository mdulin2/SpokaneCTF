#!/bin/bash 
sudo tcpdump -i lo 'port 24779' -U -w osint.pcap


