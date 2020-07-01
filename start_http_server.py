import http.server
import socketserver

server_address = ('127.0.0.1', 8000)
server_handler = http.server.SimpleHTTPRequestHandler

try:
    with socketserver.TCPServer(server_address, server_handler) as httpd:
        print(f'Server running at http://{server_address[0]}:{server_address[1]}/')
        httpd.serve_forever()
except KeyboardInterrupt:
    httpd.shutdown()
