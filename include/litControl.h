#ifndef LITCONTROL_H
#define LITCONTROL_H
#include"Socket_m.h"
class litControl:public Socket_m
{
public:
    litControl(int socket_m):Socket_m(socket_m){};
    friend void *ThreadDeal(void*nptr);
    friend void *threaddeal_m(void *nptr);
    void init();//初始化用于设置优先级或者包大小
    void Deal(char*data);//处理数据和响应

};
#endif