#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

# implement a web server
from http.server import BaseHTTPRequestHandler, HTTPServer

# HTTPServer_RequestHandler Class
class HTTPServer_RequestHandler(BaseHTTPRequestHandler):

    # Get
    def do_GET(self):
        # send response status code
        self.send_response(200)
        # send Headers
        self.send_header("Content-type", "text/html")
        self.end_headers()
        # write message
        self.wfile.write(bytes("Hello World", "utf8"))


# configure server
port = 8080
server_address = ("0.0.0.0", port)
httpd = HTTPServer(server_address, HTTPServer_RequestHandler)

# run server
httpd.serve_forever()
