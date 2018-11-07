#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class String{
    friend istream& operator>> (istream&, String&);//重载>>运算符
    friend ostream& operator<< (ostream&, String&);//重载>>运算符
public:
    String();                                       //默认构造函数
    String(const char* str);                        //赋值构造(char)
    String(const String& other);                    //赋值构造函数(String)
    String& operator=(const String& other);         //operator=
    String  operator+(const String& other)const;    //operator+
    bool operator==(const String&);                 //operator==
    char& operator[](unsigned int);                 //operator[]
    size_t size(){return strlen(m_data);};
    const char* re_m_data() const;
    char* strcpy1(char* pre, const char* next);//拷贝字符串
    char* strcat1(char* pre, const char* next);//连接字符串
    ~String(void){delete[] m_data;}
private:
    char *m_data;//用于保存字符串
};
inline const char* String::re_m_data() const
{
    return m_data;
}
inline char* strcpy1(char* pre, const char* next)
{
    if(pre==nullptr || next==nullptr)
    {
        return nullptr;
    }
    if(pre == next)
        return pre;
    while((*pre++ = *next++) != '\0');
    return pre;
}
inline char* String::strcat1(char* pre, const char* next)
{
    if(pre==nullptr || next==nullptr)
        return pre;
    char* tmp = pre + strlen(pre);
    while((*tmp++ = *next++) != '\0');
    return pre;
}
//声明为inline函数，则该函数在程序中被执行时是语句直接替换，而不是被调用
inline String::String()
{
    m_data = new char[1];
    *m_data = '\0';
}
inline String::String(const char* str){
    if(str == nullptr)
    {
        m_data = new char[1];
        *m_data = '\0';
    }
    else{
        m_data = new char[strlen(str)+1];//+1是存放字符串最后的字符\0
        strcpy(m_data, str);
    }
}
inline String::String(const String& other)
{
    if(!other.re_m_data())//在类的成员函数内可以访问同种对象的私有成员（同种类则是友元关系）
    {
        m_data = new char[1];
        m_data[0] = '\0';
    }
    else
    {
        m_data = new char[strlen(other.re_m_data())+1];
        strcpy(m_data, other.re_m_data());
    }
}
inline String& String::operator=(const String& other)
{
    if(this!=&other)
    {
        delete[] m_data;
        if(!other.re_m_data())
        {
            m_data = new char[1];
            m_data[0] = '\0';
        }
        else
        {
            m_data = new char[strlen(other.re_m_data())+1];
            strcpy(m_data, other.re_m_data());
        }
    }
    return *this;
}
inline String String::operator+(const String &other)const
{
    String newString;
    if(!other.re_m_data())
        newString = *this;
    else if(!m_data)
        newString = other;
    else
    {
        newString.m_data = new char[strlen(m_data)+strlen(other.re_m_data())+1];
        strcpy(newString.m_data, m_data);
        strcat(newString.m_data, other.re_m_data());
    }
    return newString;
}
inline bool String::operator==(const String &s)
{
    if(strlen(s.re_m_data()) != strlen(m_data))
        return false;
    return strcmp(m_data, s.re_m_data()) ? false : true;
}
inline char& String::operator[](unsigned int e)
{
    if(e>=0 && e<=strlen(m_data))
        return m_data[e];
}
ostream& operator<<(ostream& os, String& str)
{
    os << str.re_m_data();
    return os;
}
istream& operator>>(istream& input, String &s)
{
    char temp[255]; //用于存储输入流
    input >> setw(255) >> temp;
    s = temp; //使用赋值运算符
    return input; //使用return可以支持连续使用>>运算符
}
int main()
{
    String s0;
    String s1("s111111");
    cout << "s1 = " << s1 << endl;
    String str1 = "aaa";
    String str2 = "bbb ccc";
    String str3 = str1 + str2;
    cout << str1 << " " << str2 << endl;
    cout << str3 << "\n" << str3.size() << endl;
    String str4 = "456";
    String str5 = "456";
    if(str4 == str5)
        cout << "str4 == str5" << endl;
    else
        cout << "str4 != str5" << endl;
    String str6 = str5;
    cout << "str6=" << str6 << endl;

    char m[100] = "12345678910";
    char n[20] = "helloworld";
    strcat(m, n);
    cout << m << endl;
    strcpy1(m, n);
    cout << m << endl;
    return 0;
}
