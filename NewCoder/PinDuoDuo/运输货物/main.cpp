#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> w;
    vector<int> v;
    int temp;
    while(scanf("%d", &temp) != EOF){
        if(temp>=100 && temp<=300){
            w.push_back(temp);
            v.push_back(1);
            //printf("%d ", temp);
        }
    }
    sort(w.rbegin(), w.rend());
    int res = 0;
    int x = 300;
    bool flag = true;
    while(flag){
        int sum = 0;
        for(int i=0; i<v.size(); i++){
            sum += v[i];
            if(v[i]){
                break;
            }
        }
        if(sum == 0)
            break;
        for(int i=0; i<w.size(); i++){
            if(w[i] < x && v[i]){
                x -= w[i];
                v[i] = 0;
            }
            if(i == w.size()-1 || i == 0){
                res++;
            }
        }
    }

    printf("%d ", res);
    return 0;
}
