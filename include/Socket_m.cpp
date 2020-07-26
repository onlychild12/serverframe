#include"Socket_m.h"
Socket_m::Socket_m(int socket_p)
{
  socket_m=socket_p;
 
}
char* Socket_m::rec_m()
{
    char *data=new char[package];
    recv(socket_m,data,package,0);
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