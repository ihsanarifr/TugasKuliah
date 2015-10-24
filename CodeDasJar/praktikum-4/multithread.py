import socket
import sys
from thread import *

HOST = ''
PORT = 2001

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print 'Socket created'

s.bind((HOST, PORT))
print 'Socket bind complete'

s.listen(5)
print 'Socket now listening'

def clientthread(conn):
    conn.send('+OK Welcome, type your message.\n');

    data = conn.recv(80)
    print 'Client said: ' + data

    reply = '+OK Message accepted. Bye!\n'
    conn.send(reply)

    conn.close()

while 1:
    conn, addr = s.accept()
    print 'Connected with ' + addr[0] + ':' + str(addr[1])

    start_new_thread(clientthread ,(conn,))

s.close()
