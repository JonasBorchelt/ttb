#include <iostream>
#include "CivetServer.h"
#include <unistd.h>

class MainHandler: public CivetHandler
{
public:
    bool handleGet(CivetServer *server, struct mg_connection *conn) {
        mg_printf(conn, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
        mg_printf(conn, "<html><body>\r\n");
        mg_printf(conn, "<h1>hello to the world</h1>\r\n");
        mg_printf(conn, "</body></html>\r\n");
        return true;
    }
};


int main() {
  const char * options[] = { 
    "document_root", 
    ".",
    "listening_ports", 
    "8080", 
    0
  };


  CivetServer server(options);

  MainHandler h_ex;
  server.addHandler("/", h_ex);
  
  while(true) {
    sleep(1);
  }
  return 0;
}
