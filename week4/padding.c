#include <stdio.h>
struct student {
char lastName[13]; /* 13 bytes */
int studentId; /* 4 bytes */
short grade; /* 2 bytes */
};

int main(){
    struct student pst;
    printf("size of student = %ld\n", sizeof(struct student));  
    // lastName (13 bytes) + padding (3 bytes) + studentId (4 bytes) + grade (2 bytes) + padding (2 bytes)
    printf("size of int = %ld\n", sizeof(int));         // int 형 자료형의 크기는 4이다
    printf("size of short = %ld\n", sizeof(short));     // short 형 자료형의 크기는 2이다
    printf("[----- [전준석] [2021041051] -----]");
    return 0;
}