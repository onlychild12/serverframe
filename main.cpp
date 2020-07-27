#include<map>
#include<iostream>
#include"include/Server.h"
int main()
{
    int a;
    Server server;
    server.init();
    std::cout<<"开始运行";
    while(true)
    std::cin>>a;
    // std::map<int,char>test;
    // test.insert(std::pair<int,char>(1,'z'));
    // test.insert(std::pair<int,char>(2,'t'));
    // test.erase(3);
    // std::cout<<test.size();
    // return 0;
}