import http.server

server_address = ('127.0.0.1', 8000)
server_handler = http.server.CGIHTTPRequestHandler

try:
    httpd = http.server.HTTPServer(server_address, server_handler)
    print(f'Server running at http://{server_address[0]}:{server_address[1]}/')
    httpd.serve_forever()
except KeyboardInterrupt:
    httpd.shutdown()
