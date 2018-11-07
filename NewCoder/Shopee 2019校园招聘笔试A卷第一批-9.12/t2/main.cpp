#include <bits/stdc++.h>

using namespace std;
struct Point{
    double x, y;
};
bool between(double a, double X0, double X1)
{
    double temp1= a-X0;
    double temp2= a-X1;
    if((temp1<1e-8&&temp2>-1e-8) || (temp2<1e-6&&temp1>-1e-8)){
        return true;
    }else{
        return false;
    }
}
// �ж�����ֱ�߶��Ƿ��н��㣬������㽻�������
// p1,p2��ֱ��һ�Ķ˵�����
// p3,p4��ֱ�߶��Ķ˵�����
//fabs����fabs��ȡ����ֵ
//abs����Ҳ��ȡ����ֵ
//��abs��ȡ����ֵ����ȡ������fabs��ȡ����ֵ��
bool foo(Point p1, Point p2, Point p3, Point p4)
{
    double line_x,line_y; //����  �����Ҫ�Ļ� ���Է��ؽ���ֵ
    if ( (fabs(p1.x-p2.x)<1e-6) && (fabs(p3.x-p4.x)<1e-6) ){//������߶�ƽ�� ���� ��ֱ��y��
        return false;
    }else if ( (fabs(p1.x-p2.x)<1e-6) ){ //���ֱ�߶�p1p2��ֱ��y��
        if (between(p1.x,p3.x,p4.x)){
            double k = (p4.y-p3.y)/(p4.x-p3.x);
            line_x = p1.x;
            line_y = k*(line_x-p3.x)+p3.y;

            if (between(line_y,p1.y,p2.y)){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else if ( (fabs(p3.x-p4.x)<1e-6) ){ //���ֱ�߶�p3p4��ֱ��y��
        if (between(p3.x,p1.x,p2.x)){
            double k = (p2.y-p1.y)/(p2.x-p1.x);
            line_x = p3.x;
            line_y = k*(line_x-p2.x)+p2.y;

            if (between(line_y,p3.y,p4.y)){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{//����߶ξ�����ֱ��X Y��
        double k1 = (p2.y-p1.y)/(p2.x-p1.x);
        double k2 = (p4.y-p3.y)/(p4.x-p3.x);

        if (fabs(k1-k2)<1e-6){//б�����  ƽ��
            return false;
        }else{
            line_x = ((p3.y - p1.y) - (k2*p3.x - k1*p1.x)) / (k1-k2);
            line_y = k1*(line_x-p1.x)+p1.y;
        }

        if (between(line_x,p1.x,p2.x)&&between(line_x,p3.x,p4.x)){
            return true;
        }else{
            return false;
        }
    }
}
int main()
{
    Point lineOneStart, lineOneEnd, lineTwoStart, lineTwoEnd;
    cin >> lineOneStart.x >> lineOneStart.y >> lineOneEnd.x >> lineOneEnd.y
        >> lineTwoStart.x >> lineTwoStart.y >> lineTwoEnd.x >> lineTwoEnd.y;
    if(foo(lineOneStart, lineOneEnd, lineTwoStart, lineTwoEnd))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
