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
    printf("size of int = %ld\n", sizeof(int));         // int �� �ڷ����� ũ��� 4�̴�
    printf("size of short = %ld\n", sizeof(short));     // short �� �ڷ����� ũ��� 2�̴�
    printf("[----- [���ؼ�] [2021041051] -----]");
    return 0;
}