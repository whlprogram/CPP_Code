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
// 判断两条直线段是否有交点，有则计算交点的坐标
// p1,p2是直线一的端点坐标
// p3,p4是直线二的端点坐标
//fabs（）fabs是取绝对值
//abs（）也可取绝对值
//但abs是取绝对值后再取整，而fabs是取绝对值。
bool foo(Point p1, Point p2, Point p3, Point p4)
{
    double line_x,line_y; //交点  如果需要的话 可以返回交点值
    if ( (fabs(p1.x-p2.x)<1e-6) && (fabs(p3.x-p4.x)<1e-6) ){//如果两线段平行 并且 垂直于y轴
        return false;
    }else if ( (fabs(p1.x-p2.x)<1e-6) ){ //如果直线段p1p2垂直与y轴
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
    }else if ( (fabs(p3.x-p4.x)<1e-6) ){ //如果直线段p3p4垂直与y轴
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
    }else{//如果线段均不垂直于X Y轴
        double k1 = (p2.y-p1.y)/(p2.x-p1.x);
        double k2 = (p4.y-p3.y)/(p4.x-p3.x);

        if (fabs(k1-k2)<1e-6){//斜率相等  平行
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
