//声明变量时最好先赋值，生产变量时避免使用未初始化的变量
//只有在新变量时才需要规定
#include <stdio.h>
int main() {
    int mike_score = 89;
    int john_score = 98;
    
    mike_score = john_score;
    john_score = 89; 
    printf("%d\n", mike_score);
    printf("%d\n", john_score);

    return 0;
}
