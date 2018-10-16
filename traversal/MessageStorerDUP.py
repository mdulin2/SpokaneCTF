#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import socket
import threading
import sys
import os

#Modified by from the Buena Vista 2018 challenge by Maxwell "ꓘ" Dulin
secretRepo = "secrets/"

def receiveMsg(clientConn):
    msg = clientConn.recv(1024)
    if msg == b'':
        raise Exception('Client disconnected')
    return msg.decode()[0:-1]

def countFiles(directory):
    return [f for f in os.listdir(directory) if os.path.isfile(os.path.join(directory, f))]

def handleClient(conn):
    conn.send((b"This is the Open Source Intelligence (OSINT) machine. As hackers, we must stick together!\n\n"
                "Options:\n"
                "1. Report intel about a company?\n"
                "2. Read intel about a company?\n"
                "3. List companies that are on record.\n"
                "Select 1, 2 or 3: "))

    choice = receiveMsg(conn)

    if choice == "1":
        conn.send((b"What is the name of the company?\n"
                   b"Company Name: "))
        name = receiveMsg(conn)
        conn.send((b"What is your intelligence?\n"
                   b"Intel: "))
        secret = receiveMsg(conn)

        if(os.path.isdir(secretRepo+name) == False):
            os.mkdir(secretRepo+name)

        directoryCount = countFiles(secretRepo+name)

        fout = open(secretRepo+name+'/'+ str(len(directoryCount)), "w")
        fout.write(secret)
        fout.close()

        conn.send(b"\nThanks! Your Intelligence will make the world a better place...\n")

    elif choice == "2":
        conn.send((b"Which company would you like to hear about?\n"
                   b"Company: "))
        company_name = receiveMsg(conn)

        # The mitigations
        # if('../' in name):
        #   conn.send((b"Good try my ol' friend"))
        #   return
        if os.path.isdir(secretRepo+company_name):

            secretMsg  = b"\n" + company_name.encode("ascii") + b"'s company info:\n"
            file_list = countFiles(secretRepo + company_name)

            file_no = 1
            for file_name in file_list:
                fin = open(secretRepo+company_name+ '/' +file_name, "r")
                secretMsg += str(file_no) + ". " + fin.read().encode("ascii") + b"\n"
                file_no += 1
            secretMsg += b"\nBut, you didn't hear it from here...Say Facebook leaked it...\n\n"
            conn.send( secretMsg )
            fin.close()
        else:
            conn.send((b"\nSorry, we don't have info on that company.\n\n"))

    elif(choice == "3"):
        dirList = os.listdir(secretRepo)
        msg = "\nList of companies in the OSINT system:\n"
        file_no = 1
        for dir_name in dirList:
            msg += str(file_no) + ". " + dir_name + b"\n"
            file_no += 1
        conn.send( msg )
    else:
        conn.send((b"\nThis is why we can't have nice things!\n"
                   b"Next time, pick from one of the provided choices.\n\n"))



port = 24779
serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
serverSocket.bind(('',port))
serverSocket.listen(32)


print("Waiting for connections...") #Might want to delete this...
while True:
    try:
        threading.Thread(target=handleClient, args=(serverSocket.accept()[0],)).start()
    except KeyboardInterrupt:
        print('\n[Shutting Down]')
        sys.exit(1);

