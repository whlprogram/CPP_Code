#include <iostream>
#include <string>
using namespace std;

int main()
{
    /*ע����ϰ P9 1.3*/
    //   cout << "/*";      //��ȷ��� /*
    //   cout << "*/";      //��ȷ��� */
    //  //cout <<  /* "*/" */;  //������Ϣ error: expected primary-expression before 'return'|
    //                         //������Ϣ error: expected ';' before 'return'|
    //   cout << /* "*/" /* "/*" */;  //��ȷ��� /*

    /*whileѭ����ϰ P11 1.4.1*/
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
         cout << "��������������ӡ����֮�������(��������)" << endl;
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

     /*forѭ����ϰ P11 1.4.2*/
     /*
      int sum = 0;
      for (int i = -100; i <= 100; ++i)
         sum += i;
      cout << sum << endl;
     */
     /*
         int val_1 = 0,val_2 = 0;
         cout << "��������������ӡ����֮�������(��������)" << endl;
         cin >> val_1 >> val_2;
         for( ; val_2 >= val_1; --val_2)
         {
                cout << val_2 << endl;
         }
     */

     /*��ȡ������������������P13*/
     /*
        int sum = 0, val = 0;
        //��ȡ����ֱ�������ļ�β���������ж���ֵ�ĺ�
        //�Ӽ��������ļ�������    windowsϵͳ Ctrl+Z   UNIX��Mac OS Xϵͳ����Ctrl+D
        while(cin >> val)
        {
            sum += val;
        }
        cout << sum << endl;
     */

     /*if�����ϰ P15 1.4.4*/

     /*
     * ͳ�������ÿ��ֵ �������� ����
     */

     /*
     //currVal������ͳ�Ƶ������������ֵ����val
     int currVal = 0, val = 0;
     //��ȡ��һ��������ȷ��ȷʵ�����ݿ��Դ���
     if(cin >> currVal)
     {
         int cut = 1;           //�������ڴ���ĵ�ǰֵ�ĸ�������������
         while (cin >> val)     //��ȡʣ�����
         {
             if(val == currVal)
                ++cut;
             else
             {
                 cout << currVal << " occurs "
                      << cut << " times " << endl;
                 currVal = val;   //��ס��ֵ
                 cut = 1;         //���ü�����
             }//end else
         }//end while
         //��ӡ�ļ������һ��ֵ�ĸ���
         cout << currVal << " occurs " << cut << " times " << endl;
     }//end if
     */
    return 0;
}
