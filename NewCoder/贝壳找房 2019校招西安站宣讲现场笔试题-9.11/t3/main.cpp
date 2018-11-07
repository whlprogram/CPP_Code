#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
/*
package Hash;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Beike01 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int k=sc.nextInt();
		int q=sc.nextInt();
		int[][] nums=new int[q][2];
		for(int i=0;i<q;i++) {
			nums[i][0]=sc.nextInt();
			nums[i][1]=sc.nextInt();
		}
		for(int j=0;j<q;j++) {
			System.out.println(getSameParIndex(k, nums[j][0], nums[j][1]));
		}
	}

	//根据节点序号获取他的深度
	public static int getLength(int k,int n) {
		return (int)Math.ceil(Math.log(2*n+1)/Math.log(k));
	}

	//根据节点序号获取他的父节点编号
	public static int getParentIndex(int k,int n) {
		if(n==1)
			return 0;
		int sang=n/k;
		int yushu=n%k;
		if(yushu>(k-1)/2)
			return ++sang;
		else
			return sang;

	}

	//根据传入的两个节点编号，找到他们的共同父节点
	public static int getSameParIndex(int k,int n,int m) {
		if(n==1||m==1)
			return 1;
		int parentIndex=1;
		int nlength=getLength(k, n);
		int mlength=getLength(k, m);
		List<Integer> lists=new ArrayList<Integer>();

		int temp=0;
		if(nlength<=mlength) {
			temp=getParentIndex(k, n);
			while(temp>0) {
				lists.add(temp);
				n=temp;
				temp=getParentIndex(k, n);
			}
			temp=getParentIndex(k, m);
			a:while(temp>0) {
				if(lists.contains(temp)) {
					parentIndex=temp;
					break a;
				}
				m=temp;
				temp=getParentIndex(k, m);
			}
		}else {
			temp=getParentIndex(k, m);
			while(temp>0) {
				lists.add(temp);
				n=temp;
				temp=getParentIndex(k, m);
			}
			temp=getParentIndex(k, n);
			b:while(temp>0) {
				if(lists.contains(temp)) {
					parentIndex=temp;
					break b;
				}
				n=temp;
				temp=getParentIndex(k, n);
			}
		}

		return parentIndex;
	}
}
*/
