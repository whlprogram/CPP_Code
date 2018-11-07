#include<iostream>

using namespace std;


/* 基本思想
1．先从数列中取出一个数作为基准数。
2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
3．再对左右区间重复第二步，直到各区间只有一个数。
*/
//  第一种  挖坑法
/*不容易理解*/
void Quick_Sort(int* a,int le,int ri){
	if (le >= ri){
		return;
	}
	int left = le;
	int right = ri;
	int key = a[right];	 //第一个坑为最右结点	   //5 7 6 2 3 4 3
	while (left < right){ //从大到小
		while (left < right && a[left] <= key){   //这里必须判断 l < r  不然虽然外层的判断已经判断过了，
			left++;						          //  里面的while会++ -- 就会重叠 相遇
		}
		a[right] = a[left];
		while (left < right && a[right] >= key){
			right--;
		}
		a[left] = a[right];
	}
	a[right] = key;
	Quick_Sort(a, le, right - 1);
	Quick_Sort(a, right + 1, ri);

}

/*博客看到的   易理解*/
void quick_Sort(int* arr, int left, int right){
	if (left >= right){
		return;
	}

	int left_index = left;
	int right_index = right;
	int key = arr[left];

	while (left_index < right_index){
		/*如果让最左边的节点作为 基准点，那么就要从右边开始比较，反之亦然*/
		//从小到大
		while ((key <= arr[right_index]) && (left_index < right_index)){
			right_index--;
		}
		while ((key >= arr[left_index]) && (left_index < right_index)){
			left_index++;
		}
		if (left_index < right_index){
			swap(arr[left_index], arr[right_index]);
		}
	}
	/*最后将基准位归位*/
	arr[left] = arr[left_index];
	arr[left_index] = key;

	quick_Sort(arr, left, left_index - 1);
	quick_Sort(arr, left_index+1, right);
}

int main()
{
	int a[10] = { 12, 14, 25, 23, 45, 23, 45, 12, 63, 24};
	quick_Sort(a, 0, 9);
	//Quick_Sort(a, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
