#include <stdio.h>
#include <stdlib.h>

void main()
{
    int list[5];            // 크기 5인 배열 선언
    int *plist[5];          // 크기 5인 포인터 배열 선언
    list[0] = 10;           // 배열 0번째 자리에 10 입력
    list[1] = 11;           // 배열 1번째 자리에 11 입력
    plist[0] = (int*)malloc(sizeof(int));       // 포인터 배열 0번째 자리에 동적할당 
    printf("list[0] \t= %d\n", list[0]);        // 배열 0번째 자리에 10 출력
    printf("list \t\t= %p\n", list);            // 배열 첫번째 자리의 주소값 출력
    printf("&list[0] \t= %p\n", &list[0]);      // 배열 첫번째 자리의 주소값 출력
    printf("list + 0 \t= %p\n", list+0);        // 배열 첫번째 자리의 주소값 출력
    printf("list + 1 \t= %p\n", list+1);        // 배열 두번째 자리의 주소값 출력
    printf("list + 2 \t= %p\n", list+2);        // 배열 세번째 자리의 주소값 출력
    printf("list + 3 \t= %p\n", list+3);        // 배열 네번째 자리의 주소값 출력
    printf("list + 4 \t= %p\n", list+4);        // 배열 다섯번째 자리의 주소값 출력
    printf("&list[4] \t= %p\n", &list[4]);      // 배열 다섯번째 자리의 주소값 출력
    printf("[----- [전준석] [2021041051] -----]");
    free(plist[0]);                             // 동적할당 해제
}