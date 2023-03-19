#ifndef USER_H
#define USER_H
#include<string>
using namespace std;

//匹配User表的orm表
class User
{
private:
    /* data */
    int id;
    string name;
    string password;
    string state;
public:
    User(int id=-1,string name="",string pwd="",string state="offline"){
        this->id=id;
        this->name=name;
        this->password=pwd;
        this->state=state;
    }
    void setId(int id){this->id=id;}
    void setName(string name){this->name=name;}
    void setPassword(string password){this->password=password;}
    void setState(string state){this->state=state;}
    int    getId(){return this->id;}
    string getName(){return this->name;}
    string getPassword(){return this->password;}
    string getState(){return this->state;}
};


#endif