/*
��ϰһ����һ����4��ѧ����5�ſΡ�
    (1)���1�ſε�ƽ���֣�
    (2)�ҳ����������Ͽγ̲������ѧ����������ǵ�ѧ�ź�ȫ���γ̳ɼ���ƽ���ɼ���
    (3)�ҳ�ƽ���ɼ���90�����ϻ�ȫ���γ̳ɼ���85�����ϵ�ѧ����
    �ֱ��д3������ʵ������3��Ҫ��
*/
#include <iostream>

using namespace std;


// ����ƽ���ɼ�
double courseAverage(double Array[])
{
    double sum = 0;
     for (int i = 0; i < sizeof(Array); i++)
    {
        sum += Array[i];
    }
    double Average = sum/4;
    return Average;
}

// �������ϲ�����
int twoCourseFailing(double Array[])
{
    int Fail = 0;
    for (int i = 0; i < sizeof(Array); i++)
    {
        if( Array[i] < 60 )
        {
            Fail++;
        }
    }
    if(Fail>2)
        return 0;//�������ϲ�����
    return -1;//�������²�����
}

// ���Ƴɼ�����85����
int onThe85(double Array[])
{
    int Fail = 0;
     for (int i = 0; i < sizeof(Array); i++)
    {
        if( Array[i] <= 85 )
        {
            Fail++;
        }
    }
    if(Fail == 0)
        return 0;//���Ƴɼ�����85����
    return -1;//�еĳɼ���85����
}

//ѧ��ƽ���ɼ�
double stuAverage(double Array[])
{
    double sum = 0.0;
     for (int i = 0; i < sizeof(Array); i++)
    {
        sum += Array[i];
    }
    double Average = sum/5;
    return Average;
}
/*
int main()
{
    double c1Score[] = {58, 59, 89, 85};
    double c1Average = courseAverage(c1Score);//��һ�ſε�ƽ���ɼ�
    cout <<"g"<<",average    score:"<<c1Average<< endl;
    return 0;
}
*/

int main()
{
    cout << "������5�ſγ�:" << endl;
    string course[5]; //��ʾ�γ�������
    for(int i=0;i<5;i++)
    {
        cin >> course[i];
    }
    cout << "������ѧ�ź͸��Ƴɼ�:" << endl;
    cout << "ѧ��:";
    for(int i=0;i<5;i++)
    {
        if(i!=4)
            cout << course[i] << ',';
        else
            cout << course[i] ;
    }
    cout << endl;

    char stuNum[4]={'01','02','03','04'};//��ʾѧ������
    double c1Score[4],c2Score[4],c3Score[4],c4Score[4],c5Score[4];//���Ƴɼ�����
    for(int i=0;i<4;i++)
    {
        cin >> stuNum[i] >> c1Score[i] >> c2Score[i] >> c3Score[i] >> c4Score[i] >> c5Score[i]; //
    }
    //double stu1Score[5],stu2Score[5],stu3Score[5],stu4Score[5];//ѧ�����Ƴɼ�����
    //double stu1Score[5] = {c1Score[0], c2Score[0], c3Score[0], c4Score[0], c5Score[0]}; //���Ƴɼ����䵽ѧ������
    //double stu2Score[5] = {c1Score[1], c2Score[1], c3Score[1], c4Score[1], c5Score[1]};
    //double stu3Score[5] = {c1Score[2], c2Score[2], c3Score[2], c4Score[2], c5Score[2]};
    //double stu4Score[5] = {c1Score[3], c2Score[3], c3Score[3], c4Score[3], c5Score[3]};

    for (int i = 0; i < 4; i++)
    {
        cout << c1Score[i] <<endl;
    }

    double c1Average = courseAverage(c1Score);//��һ�ſε�ƽ���ɼ�
    cout <<"course 1: "<<course[0]<<",average    score:"<<c1Average<< endl;


    cout <<"==============�������ϲ������ͬѧ============"<<endl;
    cout <<"ѧ��:"<< course <<"ƽ���ɼ�"<< endl;


    cout <<"==============�ɼ������ͬѧ============"<<endl;
    cout <<"ѧ��:"<< course <<"ƽ���ɼ�"<< endl;
    return 0;
}

