#ifndef SOCKET_M_H
#define SOCKET_M_H
#include<sys/socket.h>
#include<string.h>
#include<errno.h>
class Socket_m
{
    private:
    int socket_m;
    char *data;
    long package=1024;//包大小
    
    int threadclass=0;
    public:
    Socket_m(int socket_p);
    template<class Data>
    bool litSend(Data *data);//发送
    template<class Data>
    void litEncode(char *,Data *);//解码
    char *rec_m();
    void setPacksize(long size);
    void SetHighAuclass();//设置最高优先级
    void SetHighclass(int);
    int getclass();
};
  template<class Data>
    bool Socket_m::litSend(Data *data)//发送
    {
        char *data_t=new char[package];
        memset(data_t,'z',package);
        memcpy(data_t,data,sizeof(data));
       if(send(socket_m,data_t,package,0)==-1)
       {
           return false;
       }
       else
       {
           return true;/* code */
       }
       

    }
    template<class Data>
    void Socket_m::litEncode(char*data,Data*desd)
    {
            memcpy(desd,data,sizeof(Data));
            delete[] data;
    }
#endif