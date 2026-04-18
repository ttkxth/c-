#include<stdio.h>
struct student{
    char name[20];
    int score;
 };
 void change(struct student *p){
    p->score=100;
 }

int main(){
  struct student s1={"TOm",90};
  change(&s1);
  printf("姓名：%s 成绩: %d",s1.name,s1.score);


    return 0;
}