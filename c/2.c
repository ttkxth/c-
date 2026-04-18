#include <stdio.h>

int main(void) {
    int age = 21;
    float gpa = 2.05f;
    char grade = 'c';
    char name[] = "bro";

    printf("Hello %s\n", name);
    printf("You are %d years old\n", age);
    printf("your gpa is %.2f\n", gpa);
    printf("your grade is %c\n", grade);
    return 0;
}

