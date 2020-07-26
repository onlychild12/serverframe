#include<sys/socket.h>
#include"Server.h"
#include<pthread.h>
#include<netinet/in.h>
#include<unistd.h>
void Server::init()
{
    server=socket(AF_INET,SOCK_STREAM,0);
    sockaddr_in sin;
    sin.sin_addr.s_addr=
}