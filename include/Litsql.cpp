#include"Litsql.h"
void  Litsql::connect()
{
    conn=mysql_init(NULL);
    mysql_real_connect(conn,"localhost","root",)
}