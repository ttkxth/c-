#include<stdio.h>
struct Address{
    char province[20];
    char city[20];
    char district[20];
};
struct student{
    char name[20];
    int age;
    struct Address addr;
};
int main(){
    struct student s1 ={
        "Tom",
        19,
        {"重庆","重庆","沙坪坝"}
    };
    printf("%s\n",s1.name);
    printf("%d\n",s1.age);
    printf("%s\n",s1.addr.province);


    return 0;
}