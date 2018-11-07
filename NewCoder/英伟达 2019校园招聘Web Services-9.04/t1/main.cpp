#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int L(int n, int m) {
    int i, res;
	int a[1001];
	int dead = 0;          //表示已经死了多少人
	int count = 0;           //num模拟没有被杀的人的喊数
	for (i = 1; i<=n; i++){//开始时每个人都可以报数，为了能得到最后一个人的编号，我们让初始值为i下标
		a[i] = i;
	}
	for (i = 1;; i++){
		if (i > n){//如果大于总人数，我们就从头开始
			i = i%n;
		}
		if (a[i] == 0)//如果当前这个人死亡，跳过
		  continue;
		if (a[i] > 0)//如果当前这个人没有死，就报数
		  count++;
		if (m == count && dead != n-1){ //如果当前这个人报的数等于k 并且没有已经死亡n-1个人
			count = 0;
			a[i] = 0;//死亡的人置为0
			dead++;
			//cout << i << endl;
		}else if(m == count && dead == n-1){  //如果这个人报数等于k，并且已经死了n-1个人，说明当前这个人就是最后的一个活着的了。。
			res = a[i];
			break;
		}
	}
	return res;
}
/******************************结束写代码******************************/


int main() {
    int res;

    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');



    res = L(_n, _m);
    cout << res << endl;

    return 0;

}
