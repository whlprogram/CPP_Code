#ifndef _MYSTRING_
#define _MYSTRING_

int strlen(const char* str);
char* strcpy(char* pre, const char* next);

class String{
public:
    String(const char* cstr=0);//构造函数
    String(const String& str);//拷贝构造函数
    String& operator = (const String& str);
    ~String();//析构函数
    char* get_c_str() const {return m_data;}

private:
    char* m_data;

};

//#include <cstring>
inline
String::String(const char* cstr)
{
    if(cstr){
        m_data = new char[strlen(cstr)+1];
        strcpy(m_data, cstr);
    }else{
        m_data = new char[1];
        *m_data = '\0';
    }
}
inline
String::String(const String& str)
{
    m_data = new char[strlen(str.m_data)+1];
    strcpy(m_data, str.m_data);
}
inline
String& String::operator = (const String& str)
{
    //初级程序员
    /*
    if(this == &str)
        return *this;

    delete[] m_data;
    m_data = new char[strlen(str.m_data)+1];
    strcpy(m_data, str.m_data);
    return *this;
    */

    //高级程序员
    if(this != &str)
    {
        String strTemp(str);

        char* pTemp = strTemp.m_data;
        strTemp.m_data = m_data;
        m_data = pTemp;
    }
    return *this;
}
inline
String::~String()
{
    delete[] m_data;
}
inline int
strlen(const char* str)
{
    if((str==nullptr)||(*str=='\0'))
        return 0;
    else
        return strlen(str+1)+1;
}
inline char*
strcpy(char* pre, const char* next)
{
    if(pre==nullptr || next==nullptr)
        return nullptr;
    if(pre == next)
        return pre;
    while((*pre++ = *next++) != '\0');
    return pre;
}
#include <iostream>
using namespace std;

ostream& operator << (ostream& os, const String& str)
{
    return os << str.get_c_str();
}
#endif
