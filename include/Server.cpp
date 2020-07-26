#include<sys/socket.h>
#include"Server.h"

#include<netinet/in.h>
#include<unistd.h>
pthread_mutex_t mutex_clean;//线程锁
pthread_mutex_t mutex_threadlist;
pthread_mutex_t mutex_free;
struct tdd//用以处理线程传参
{
    int soc;
    int index;
};
void *Threaddeal(void *nptr)
{
    return 0;
}
void *clean_m(void *nptr)
{

}
void *threaddeal_m(void *nptr)
{

}
void Server::init()
{
    server=socket(AF_INET,SOCK_STREAM,0);
    sockaddr_in sin;
    sin.sin_addr.s_addr=INADDR_ANY;
    sin.sin_family=AF_INET;
    sin.sin_port=htons(2333);
    bind(server,(sockaddr*)&sin,sizeof(server));
    listen(server,200000);
    pthread_create(&listen_thread,NULL,listen_m,(void*)this);//开启监听线程
}
void *listen_m(void *ptr)
{
    pthread_detach(pthread_self());
    sockaddr_in client;
    Server *parent=(Server*)ptr;
    int len=sizeof(client);
    while (!parent->exit/* condition */)
    {
       parent->saccept=accept(parent->server,(sockaddr*)&client,(socklen_t*)&len); /* code */
       pthread_t *tmpthread=new pthread_t;
       pthread_create()
       parent->threadlist.insert(std::pair<int,pthread_t*>(parent->index,tmpthread));//插入队列
       

    }
    return 0;
}