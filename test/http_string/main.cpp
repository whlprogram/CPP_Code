#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

char *str= "GET /download/JBPM4S.tt HTTP/1.1\r\n\
Host: 10.1.18.4\r\n\
User-Agent: Mozilla/5.0 (Windows NT 6.2; rv:40.0) Gecko/20100101 Firefox/40.0\r\n\
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*//*;q=0.8\r\n\
Accept-Language: zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3\r\n\
Accept-Encoding: gzip, deflate\r\n\
Referer: http:http://10.1.18.4/\r\n\
Connection: keep-alive\r\n\
Range: bytes=14584264-\r\n\r\n" ;

string& ltrim(string &str) {
    string::iterator p = find_if(str.begin(), str.end(), not1(ptr_fun<int, int>(isspace)));
    str.erase(str.begin(), p);
    return str;
}

string& rtrim(string &str) {
    string::reverse_iterator p = find_if(str.rbegin(), str.rend(), not1(ptr_fun<int , int>(isspace)));
    str.erase(p.base(), str.end());
    return str;
}

string& trim(string &str) {
    ltrim(rtrim(str));
    return str;
}
string getContent(string& str,int start,char c,int &pos){
    int i=start;
    int len=str.size();
    while(i<len&&str[i]!=c){
        i++;
    }
    pos=i;
    return str.substr(start,i-start);
}
map<string,string> parseHeader(char* str){
    int len=strlen(str);
    vector<string> vs;
    int i=0;
    while(i<len){
        if(str[i]!='\r'){
            int j=i;
            while(i<len&& str[i]!='\r')
                i++;
            vs.push_back(string(str+j,str+i));
        }else{
            i+=2;
        }
    }
    int pos;
    string method=getContent(vs[0],0,' ',pos);
    string url=getContent(vs[0],method.size()+1,' ',pos);
    map<string,string> mp;
    mp["Method"]=method;
    mp["Url"]=url;
    for(int i=1;i<vs.size();i++){
        string key=getContent(vs[i],0,':',pos);
        string value=vs[i].substr(pos+1);
        for(map<string,string>::const_iterator it=mp.begin();it!=mp.end();++it){
            cout<<it->first <<"   "<<it->second<<endl;
        }
        cout<<"   "<<endl;
        mp[key]=trim(value);
    }
    return mp;
}

int main(int argc, char **argv)
{
    map<string,string> mp =parseHeader(str);
    for(map<string,string>::const_iterator it=mp.begin();it!=mp.end();++it){
        cout<<it->first <<"   "<<it->second<<endl;
    }
    return 0;
}
