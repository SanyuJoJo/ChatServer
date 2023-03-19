#include "friendmodel.hpp"
//  添加好友关系
void FriendModel::insert(int userid, int friendid)
{
    // 组装SQL语句
    char sql[1024] = {0};
    sprintf(sql, "insert into friend values(%d,%d)", userid, friendid);
    MySQL mysql;
    if (mysql.connect())
    {
        mysql.update(sql);
    }
}

// 返回用户好友列表 friendid
vector<User> FriendModel::query(int userid)
{
    // 组装SQL语句
    char sql[1024] = {0};
    sprintf(sql, "select a.id,a.name,a.state from user a inner join friend b on b.friendid=a.id where b.userid=%d", userid);
    vector<User> vec;
    MySQL mysql;
    if (mysql.connect())
    {
        // 获取插入成功的用户数据的主键id
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {
            // 查询成功
            MYSQL_ROW row;
            // 把所有离线用户的消息放入vector中
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                User user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setState(row[2]);
                vec.push_back(user);

            }
            mysql_free_result(res);
            return vec;
        }
    }
    return vec;
}