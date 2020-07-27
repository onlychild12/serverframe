#include"Socket_m.h"
#include<unistd.h>
Socket_m::Socket_m(int socket_p)
{
  socket_m=socket_p;
 
}
int Socket_m::getclass()
{
    return threadclass;
}
Socket_m::~Socket_m()
{
    close(socket_m);
}
char* Socket_m::rec_m()
{
    char *data=new char[package];
    memset(data,'z',package);
    if(recv(socket_m,data,package,0)==-1)
       {
           delete[] data;
           return NULL;
       }
    return data;
}
void Socket_m::setPacksize(long size)
{
    package=size;
}
void Socket_m::SetHighAuclass()
{
    threadclass=-1;
}
void Socket_m::SetHighclass(int class_p)
{
    threadclass=class_p;
}