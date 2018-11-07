/*
原题链接 https://www.nowcoder.com/question/next?pid=10714908&qid=164575&tid=16850519

牛牛每天必须吃一个水果并且需要每天支付x元的房屋租金。
当前牛牛手中已经有f个水果和d元钱,牛牛也能去商店购买一些水果,商店每个水果售卖p元。
牛牛为了表现他独立生活的能力,希望能独立生活的时间越长越好,牛牛希望你来帮他计算一下他最多能独立生活多少天。
*/
#include <iostream>

using namespace std;

int main()
{
    int x,f,d,p;
    cin >> x >> f >> d >> p;
    if(d-f*x <= 0){//水果足够多 只需要担心房租
        cout << d/x;
    }else{//水果不够多 需要担心房租和水果钱
        cout << f+(d-f*x)/(x+p);
    }
    return 0;
}
