#include <stdio.h>
#define MAX_SIZE 100

float sum1(float list[], int);      // 주소를 배열 형태로 받기
float sum2(float *list, int);       // 주소를 포인터 형태로 받기
float sum3(int n, float *list);     // 주소를 포인터 형태로 받기
float input[MAX_SIZE], answer;      // 전역 변수와 배열 선언
int i;

void main(void)
{
    for(i=0; i < MAX_SIZE; i++)
        input[i] = i;   // 배열에 0부터 99까지 값 입력
    /* for checking call by reference */
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);            // 배열의 주소 출력
    answer = sum1(input, MAX_SIZE);             // 배열의 이름을 주소로서 넘겨줌
    printf("The sum is: %f\n\n", answer);       // 베열의 합계 출력
    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);            // 배열의 주소 출력
    answer = sum2(input, MAX_SIZE);             // 배열의 이름을 주소로서 넘겨줌
    printf("The sum is: %f\n\n", answer);       // 베열의 합계 출력
    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);            // 배열의 주소 출력
    answer = sum3(MAX_SIZE, input);             // 배열의 이름을 주소로서 넘겨줌
    printf("The sum is: %f\n\n", answer);       // 베열의 합계 출력
    printf("[----- [전준석] [2021041051] -----]");
}

float sum1(float list[], int n) {               // 배열로서 주소를 받음
    printf("list\t= %p\n", list);               // 받은 배열의 주소값 출력
    printf("&list\t= %p\n\n", &list);           // 함수에서 만들어진 list배열의 주소값 출력
    int i;
    float tempsum = 0;
    for(i = 0;i < n;i++)
        tempsum += list[i];
    return tempsum;
}
float sum2(float *list, int n) {                // 포인터로서 주소를 받음
    printf("list\t= %p\n", list);               // 받은 배열의 주소값 출력
    printf("&list\t= %p\n\n", &list);           // 함수에서 만들어진 list배열의 주소값 출력
    int i;
    float tempsum = 0;
    for(i = 0;i < n;i++)
        tempsum += *(list + i);                 // 포인터에 일정한 값을 더하여 다음 배열을 가르켜 그 값에 접근한다
    return tempsum;
}
/* stack variable reuse test */
float sum3(int n, float *list) {                // 포인터로서 주소를 받음
    printf("list\t= %p\n", list);               // 받은 배열의 주소값 출력
    printf("&list\t= %p\n\n", &list);           // 함수에서 만들어진 list배열의 주소값 출력
    int i;
    float tempsum = 0;
    for(i = 0;i < n;i++)
        tempsum += *(list +i);
    return tempsum;
}