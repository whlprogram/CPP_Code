#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int arr[100];
int main()
{
    string str, dst;
    getline(str);
    getline(dst);
    int temp=0, i=0;
    while(~scanf("%d", &temp)){
        arr[i] = temp;
        i++;
    }
    printf("%d\n", maxSumIS(arr, 100));
    return 0;
}
/*
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        String arr_input[] = new String[3];

        for (int i = 0; i < 3; i++) {
            arr_input[i] = input.nextLine();
        }
        System.out.println(ReplaceSubStr(arr_input[0],arr_input[1], arr_input[2]));
    }
    private static String ReplaceSubStr(String str, String srcSubStr, String dstSubStr){

        String result = "";
        int start = -1;
        while (true){
            result = str;
            start = kmp(result, srcSubStr, kmpnext(srcSubStr));
            if (-1 == start)
                break;
            str = result.substring(0,start) + dstSubStr + result.substring(start+srcSubStr.length(), result.length());
        }
        return str;
    }

    public static int kmp(String str, String dest,int[] next){//str文本串  dest 模式串

        for(int i = 0, j = 0; i < str.length(); i++){//正序
            while(j > 0 && str.charAt(i) != dest.charAt(j)){
                j = next[j - 1];
            }
            if(str.charAt(i) == dest.charAt(j)){

                j++;
            }
            if(j == dest.length()){
                return i - dest.length()+1;
            }
        }
        return -1;
    }
    public static int[] kmpnext(String dest){
        int[] next = new int[dest.length()];
        next[0] = 0;
        for(int i = 1,j = 0; i < dest.length(); i++){
            while(j > 0 && dest.charAt(j) != dest.charAt(i)){
                j = next[j - 1];
            }
            if(dest.charAt(i) == dest.charAt(j)){
                j++;
            }
            next[i] = j;
        }
        return next;
    }
}
*/
