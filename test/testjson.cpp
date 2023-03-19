#include"json.hpp"

using json =nlohmann::json;

#include <iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

// json序列化示例--反序列化示例

string func1(){
    json js;
    //string user="debian-sys-maint";debian-sys-maint
    //string pw="7pSR9nhRiK7TpowI";7pSR9nhRiK7TpowI
    js["msg_type"]=2;
    js["from"]="zhang san";
    js["to"]="li si";
    js["msg"]="hello,what are you doing now?";
    js["msg1"]["zhang san"]="hello world";
    js["msg1"]["li si"]="hello china";
    //上面等同于
    js["msg1"]={{"zhang san","hellp world"},{"liu shuo","hello china"}};

    string sendBuff=js.dump();
    //cout<<sendBuff.c_str()<<endl;
    return sendBuff;
}
string func2(){
    json js;
    js["id"]={1,2,3,4,5};
    /*
    js["msg"]["zhang san"]="hello world";
    js["msg"]["li si"]="hello china";
    */
    
    //上面等同于
    js["msg"]={{"zhang san","hellp world"},{"liu shuo","hello china"}};

    string sendBuff=js.dump();
    //cout<<sendBuff.c_str()<<endl;
    return sendBuff;
}
string func3(){
    json js;
    //直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    js["list"]=vec;
    //直接序列化一个map容器
    map<int,string> m;
    m.insert({1,"黄山"});
    m.insert({2,"华山"});
    m.insert({3,"泰山"});
    js["path"]=m;
    
     string sendBuff=js.dump();
    //cout<<sendBuff.c_str()<<endl;
    return sendBuff;
}

//反序列化
void func4(){
    /*
    string recvBuf=func1();
    //数据的反序列化
    json jsbuf = json::parse(recvBuf);
    cout<<jsbuf["msg_type"]<<endl;
    cout<<jsbuf["from"]<<endl;
    cout<<jsbuf["to"]<<endl;
    cout<<jsbuf["msg"]<<endl;
    */
   /*
   string recvBuf=func2();
   json jsbuf = json::parse(recvBuf);
   auto arr=jsbuf["id"];

   cout<<arr[3]<<endl;
   auto msg=jsbuf["msg"];
   cout<<msg["zhang san"]<<endl;
   cout<<msg["liu shuo"]<<endl;
   
   */
  string recvBuf=func3();
   json jsbuf = json::parse(recvBuf);
   vector<int> vec =jsbuf["list"];      //js数组类型可以直接放入vector中
   for(int &v:vec){
    cout<<v<<" ";
   }
   cout<<endl;
    
    map<int,string> mymap=jsbuf["path"];
    for(auto &p:mymap){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;
}
int main(){
    func4();
    return 1;
}
