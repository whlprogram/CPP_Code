#include <iostream>

using namespace std;

int main()
{
	int res = 0;
	int temp_A, temp_B;
	cin >> temp_A >> temp_B;
	if (temp_A*6+temp_B<0){
		res = (temp_A*6+temp_B)*2 + temp_A*3;
	}else if(temp_A*5+temp_B*2<0){
		res = (temp_A*5+temp_B*2)*2 + temp_A*3;
	}else if(temp_A*4+temp_B*3<0){
		res = (temp_A*4+temp_B*3)*2 + temp_A*3;
	}else if(temp_A*3+temp_B*4<0){
		res = (temp_A*3+temp_B*4)*2 + temp_A*3;
	}else if(temp_A*2+temp_B*5<0){
		res = (temp_A*2+temp_B*5)*2 + temp_A*2 + temp_B;
	}else if(temp_A*1+temp_B*6<0){
		res = (temp_A*1+temp_B*6)*2 + temp_A + temp_B*2;
	}else{
		res = temp_B*17;
	}
	cout << res << endl;
	return 0;
}
/*
A:1 B:0
(1 1 1 1 1 1 0)  (1 1 1 1 1 1 0)  (1 1 1)
(1 1 1 1 1 0 0)  (1 1 1 1 1 0 0)  (1 1 1)
(1 1 1 1 0 0 0)  (1 1 1 1 0 0 0)  (1 1 1)
(1 1 1 0 0 0 0)  (1 1 1 0 0 0 0)  (1 1 1)
(1 1 0 0 0 0 0)  (1 1 0 0 0 0 0)  (1 1 0)
(1 0 0 0 0 0 0)  (1 0 0 0 0 0 0)  (1 0 0)
(0 0 0 0 0 0 0)  (0 0 0 0 0 0 0)  (0 0 0)
*/
