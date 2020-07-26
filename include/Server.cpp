#include<sys/socket.h>
#include"Server.h"
#include<pthread.h>
#include<netinet/in.h>
#include<unistd.h>
void Server::init()
{
    server=socket(AF_INET,SOCK_STREAM,0);
    sockaddr_in sin;
    sin.sin_addr.s_addr=INADDR_ANY;
    sin.sin_family=AF_INET;
    sin.sin_port=htons(2333);
    bind(server,(sockaddr*)&sin,sizeof(server));
    listen(server,200000);
    
}
void *listen_m(void *ptr)
{
    while (/* condition */)
    {
        /* code */
    }
    
}