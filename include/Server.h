#ifndef SERVER_H
#define SERVER_H
#include<map>
#include<vector>
class pthread_t;
class Server
{
private:
   int server;//监听socket /* data */
   int saccept;//接收socket标识符
   bool exit;
public:
    std::map<int,pthread_t*>threadlist;
    void exit_m();
    void init();
    friend void *listen_m(void *nptr);
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