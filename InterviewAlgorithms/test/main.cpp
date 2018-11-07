#include<stdio.h>
int i=0;
void f(const char* str){
    printf("i=%d  Level %d : str location %p\n", i, str, &str); /* 1 */
    if(*str != '\0'){
        i++;
        if(i == 4){
            printf("i=%d  Level %d : str location %p\n", i, str, &str); /* 1 */
            return;
        }
        f(str++);
    }
    i--;
    printf("===i=%d  Level %d : str location %p\n", i, str, &str); /* 2 */
}

int main(){
    char* str = nullptr;
    str = "Hello Word";
    f(str);
    printf("==============\n");
    printf("Level %d : str location %p\n",str, &str);
    return 0;
}
