#include <stdio.h>
void print_one(int *ptr, int rows);

int main(){
    int one[] = {0, 1, 2, 3, 4};            // 크기 5인 배열 선언
    printf("one = %p\n", one);              // 배열의 이름으로서 포인터 이고 배열의 시작 주소값 출력
    printf("&one = %p\n", &one);            // 배열의 이름으로서 포인터 이고 포인터의 주소값 출력
    printf("&one[0] = %p\n", &one[0]);      // 배열의 이름으로서 포인터 이고 배열의 첫번째 주소값 출력
    printf("\n");
    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("------------------------------------\n");
    print_one(&one[0], 5);                  // 배열의 첫번째 주소값을 넘김
    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    print_one(one, 5);                      // 배열의 이름, 즉 배열의 주소값을 넘김
    printf("[----- [전준석] [2021041051] -----]");
    return 0;
}

void print_one(int *ptr, int rows){     // 포인터로서 배열의 주소값을 받음
/* print out a one-dimensional array using a pointer */
    int i;
    printf ("Address \t Contents\n");
    for (i = 0; i < rows; i++)
        printf("%p \t %5d\n", ptr + i, *(ptr + i));     // 포인터에 일정한 수를 더함으로서 배열에 하나씩 접근하여 주소와 값을 출력하고 있다
    printf("\n");
}