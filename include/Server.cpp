#include<sys/socket.h>
#include"Server.h"

#include<netinet/in.h>
#include<unistd.h>
#include<time.h>
#include"litControl.h"
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
    tdd* td=static_cast<tdd*>(nptr);
    litControl *mycontrol=new litControl(td->soc);
    mycontrol->init();
    while(true)
    {
           char*data=mycontrol->rec_m();
            if(mycontrol->getclass()==0)
            {
                mycontrol->Deal(data);
            }
          
    }
    return 0;
}
void *clean_m(void *nptr)
{
pthread_detach(pthread_self());
Server*server=(Server*)nptr;
while(!server->exit)
{
    pthread_mutex_lock(&mutex_clean);
    if(server->cleanlist.size()>0)
    {
        pthread_mutex_lock(&mutex_threadlist);
    for(int i=0;i<server->cleanlist.size();)
    {
       pthread_join(*server->threadlist[server->cleanlist[i]],NULL);
       delete server->threadlist[server->cleanlist[i]];
       server->threadlist.erase(server->cleanlist[i]);
       server->cleanlist.erase(server->cleanlist.begin());
    }
    pthread_mutex_unlock(&mutex_threadlist);
    }

pthread_mutex_unlock(&mutex_clean);
sleep(0.2);
    
}
return 0;
}
void *threaddeal_m(void *nptr)
{

}
void Server::init()
{
    pthread_mutex_init(&mutex_clean,NULL);
    pthread_mutex_init(&mutex_free,NULL);
    pthread_mutex_init(&mutex_threadlist,NULL);
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
        int saccept=accept(parent->server,(sockaddr*)&client,(socklen_t*)&len); /* code */
       pthread_t *tmpthread=new pthread_t;
       tdd *tmptdd=new tdd;
       tmptdd->index=parent->index;
       tmptdd->soc=saccept;
       pthread_create(tmpthread,NULL,Threaddeal,(void*)tmptdd);
       pthread_mutex_lock(&mutex_threadlist);
       parent->threadlist.insert(std::pair<int,pthread_t*>(parent->index,tmpthread));//插入队列
       pthread_mutex_unlock(&mutex_threadlist);
       pthread_mutex_lock(&mutex_free);
       if(parent->freelist.size()>0)
       {
           parent->index=parent->freelist[0];
           parent->freelist.erase(parent->freelist.begin());
           pthread_mutex_unlock(&mutex_free);
       }
       else{
           parent->index=parent->threadlist.size();
       }
       

    }
    return 0;
}