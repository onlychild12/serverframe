#include"include/litControl.h"
#include<iostream>
#include<unistd.h>
void litControl::init()//初始化犹如通信包大小，响应等级等设置
{
  SetHighAuclass();
}
void litControl::Deal(char*data)//请解码
{
//  std::cout<<data;
 sleep(1);
}