#ifndef SERVER_H
#define SERVER_H
#include<map>
#include<vector>
#include<pthread.h>
class Server
{
private:
   int server;//监听socket /* data */
//    int saccept;//接收socket标识符
   bool exit=false;
   bool index=0;
   std::map<int,pthread_t*>threadlist;
   std::vector<int>cleanlist;//清理队列
   std::vector<int>freelist;//空闲队列
   pthread_t listen_thread;//监听线程
public:
    
    void exit_m();
    void init();
    friend void *listen_m(void *nptr);
    friend void *clean_m(void *nptr);
    friend void *Threaddeal(void *nptr);
    friend void *threaddeal_m(void *nptr);
    Server(/* args */);
    ~Server();
};

Server::Server(/* args */)
{
}

Server::~Server()
{
    
}

#endif