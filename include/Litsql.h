#ifndef LIT_SQL_H
#define LIT_SQL_H
#include<mysql/mysql.h>
#include<fstream>
class Litsql{
private:
MYSQL *conn;
char *host;
char *user;
char *password;
char *db;//数据库
unsigned int port;//端口

};
#endif
