#!/bin/bash 

sudo tcpdump -i lo 'port 24779' -w wireshark.pcap
