#include <iostream>
#include <string>
using namespace std;

int main()
{
    /*注释练习 P9 1.3*/
    //   cout << "/*";      //正确输出 /*
    //   cout << "*/";      //正确输出 */
    //  //cout <<  /* "*/" */;  //错误信息 error: expected primary-expression before 'return'|
    //                         //错误信息 error: expected ';' before 'return'|
    //   cout << /* "*/" /* "/*" */;  //正确输出 /*

    /*while循环练习 P11 1.4.1*/
    /*
        int sum = 0,val = 50;
        while(val <= 100)
        {
            sum += val;
            ++val;
        }
        cout << "Sum of 50 to 100 inclusive is " << sum <<endl;
    */
    /*
        int val = 11;
        while(val > 0)
        {
            cout << --val << endl;
        }
     */
     /*
         int val_1 = 0,val_2 = 0;
         cout << "输入两个数，打印它们之间的整数(包括它们)" << endl;
         cin >> val_1 >> val_2;
         if (val_2 < val_1)
         {
             int val = 0;
             val = val_1;
             val_1 = val_2;
             val_2 = val;
         }
         while(val_2 >= val_1)
         {
                cout << val_2 << endl;
                --val_2;
         }
     */

     /*for循环练习 P11 1.4.2*/
     /*
      int sum = 0;
      for (int i = -100; i <= 100; ++i)
         sum += i;
      cout << sum << endl;
     */
     /*
         int val_1 = 0,val_2 = 0;
         cout << "输入两个数，打印它们之间的整数(包括它们)" << endl;
         cin >> val_1 >> val_2;
         for( ; val_2 >= val_1; --val_2)
         {
                cout << val_2 << endl;
         }
     */

     /*读取数量不定的输入数据P13*/
     /*
        int sum = 0, val = 0;
        //读取数据直到遇到文件尾，计算所有读入值的和
        //从键盘输入文件结束符    windows系统 Ctrl+Z   UNIX和Mac OS X系统中是Ctrl+D
        while(cin >> val)
        {
            sum += val;
        }
        cout << sum << endl;
     */

     /*if语句练习 P15 1.4.4*/

     /*
     * 统计输入的每个值 连续出现 次数
     */

     /*
     //currVal是正在统计的数，读入的新值存入val
     int currVal = 0, val = 0;
     //读取第一个数，并确保确实有数据可以处理
     if(cin >> currVal)
     {
         int cut = 1;           //保存正在处理的当前值的个数（计数器）
         while (cin >> val)     //读取剩余的数
         {
             if(val == currVal)
                ++cut;
             else
             {
                 cout << currVal << " occurs "
                      << cut << " times " << endl;
                 currVal = val;   //记住新值
                 cut = 1;         //重置计数器
             }//end else
         }//end while
         //打印文件中最后一个值的个数
         cout << currVal << " occurs " << cut << " times " << endl;
     }//end if
     */
    return 0;
}
