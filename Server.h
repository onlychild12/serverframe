#ifndef SERVER_H
#define SERVER_H
class Server
{
private:
   int server;//监听socket /* data */
   int saccept;//接收socket标识符
public:
    void init
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