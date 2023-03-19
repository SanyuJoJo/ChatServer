#include "offlinemessagemodel.hpp"
#include "db.h"

//存储用户的离线消息
void OfflineMsgModel::insert(int userid,string msg)
{       //组装SQL语句
        char sql[1024]={0};
        sprintf(sql,"insert into offlinemessage values(%d,'%s')",userid,msg.c_str());
        MySQL mysql;
        if(mysql.connect()){
            mysql.update(sql);   
        }
}
//删除用户的离线消息
void OfflineMsgModel::remove(int userid){
 //组装SQL语句
        char sql[1024]={0};
        sprintf(sql,"delete from offlinemessage where userid=%d",userid);
        MySQL mysql;
        if(mysql.connect()){
            mysql.update(sql);   
        }
}
//查询用户的离线消息
vector<string> OfflineMsgModel::query(int userid){
     //组装SQL语句
        char sql[1024]={0};
        sprintf(sql,"select message from offlinemessage where userid=%d",userid);
        vector<string> vec;
        MySQL mysql;
        if(mysql.connect()){
                // 获取插入成功的用户数据的主键id
                MYSQL_RES *res =mysql.query(sql);
                if(res!=nullptr){
                    //查询成功 
                    MYSQL_ROW row;
                     //把所有离线用户的消息放入vector中
                    while ((row=mysql_fetch_row(res))!=nullptr){
                       vec.push_back(row[0]);
                    }
                    mysql_free_result(res);
                    return vec;
                
            }
        }
        return vec;
}