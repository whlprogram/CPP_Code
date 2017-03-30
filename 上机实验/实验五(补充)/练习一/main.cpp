/*
练习一、有一个班4个学生，5门课。
    (1)求第1门课的平均分；
    (2)找出有两门以上课程不及格的学生，输出他们的学号和全部课程成绩和平均成绩；
    (3)找出平均成绩在90分以上或全部课程成绩在85分以上的学生。
    分别编写3个函数实现以上3个要求
*/
#include <iostream>

using namespace std;


// 单科平均成绩
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

// 两门以上不及格
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
        return 0;//两门以上不及格
    return -1;//两门以下不及格
}

// 各科成绩均在85以上
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
        return 0;//各科成绩均在85以上
    return -1;//有的成绩在85以下
}

//学生平均成绩
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
    double c1Average = courseAverage(c1Score);//第一门课的平均成绩
    cout <<"g"<<",average    score:"<<c1Average<< endl;
    return 0;
}
*/

int main()
{
    cout << "请输入5门课程:" << endl;
    string course[5]; //表示课程名数组
    for(int i=0;i<5;i++)
    {
        cin >> course[i];
    }
    cout << "请输入学号和各科成绩:" << endl;
    cout << "学号:";
    for(int i=0;i<5;i++)
    {
        if(i!=4)
            cout << course[i] << ',';
        else
            cout << course[i] ;
    }
    cout << endl;

    char stuNum[4]={'01','02','03','04'};//表示学号数组
    double c1Score[4],c2Score[4],c3Score[4],c4Score[4],c5Score[4];//单科成绩数组
    for(int i=0;i<4;i++)
    {
        cin >> stuNum[i] >> c1Score[i] >> c2Score[i] >> c3Score[i] >> c4Score[i] >> c5Score[i]; //
    }
    //double stu1Score[5],stu2Score[5],stu3Score[5],stu4Score[5];//学生各科成绩数组
    //double stu1Score[5] = {c1Score[0], c2Score[0], c3Score[0], c4Score[0], c5Score[0]}; //单科成绩分配到学生数组
    //double stu2Score[5] = {c1Score[1], c2Score[1], c3Score[1], c4Score[1], c5Score[1]};
    //double stu3Score[5] = {c1Score[2], c2Score[2], c3Score[2], c4Score[2], c5Score[2]};
    //double stu4Score[5] = {c1Score[3], c2Score[3], c3Score[3], c4Score[3], c5Score[3]};

    for (int i = 0; i < 4; i++)
    {
        cout << c1Score[i] <<endl;
    }

    double c1Average = courseAverage(c1Score);//第一门课的平均成绩
    cout <<"course 1: "<<course[0]<<",average    score:"<<c1Average<< endl;


    cout <<"==============两门以上不及格的同学============"<<endl;
    cout <<"学号:"<< course <<"平均成绩"<< endl;


    cout <<"==============成绩优秀的同学============"<<endl;
    cout <<"学号:"<< course <<"平均成绩"<< endl;
    return 0;
}

