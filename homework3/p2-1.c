#include <stdio.h>
#define MAX_SIZE 100

float sum1(float list[], int);      // �ּҸ� �迭 ���·� �ޱ�
float sum2(float *list, int);       // �ּҸ� ������ ���·� �ޱ�
float sum3(int n, float *list);     // �ּҸ� ������ ���·� �ޱ�
float input[MAX_SIZE], answer;      // ���� ������ �迭 ����
int i;

void main(void)
{
    for(i=0; i < MAX_SIZE; i++)
        input[i] = i;   // �迭�� 0���� 99���� �� �Է�
    /* for checking call by reference */
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);            // �迭�� �ּ� ���
    answer = sum1(input, MAX_SIZE);             // �迭�� �̸��� �ּҷμ� �Ѱ���
    printf("The sum is: %f\n\n", answer);       // ������ �հ� ���
    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);            // �迭�� �ּ� ���
    answer = sum2(input, MAX_SIZE);             // �迭�� �̸��� �ּҷμ� �Ѱ���
    printf("The sum is: %f\n\n", answer);       // ������ �հ� ���
    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);            // �迭�� �ּ� ���
    answer = sum3(MAX_SIZE, input);             // �迭�� �̸��� �ּҷμ� �Ѱ���
    printf("The sum is: %f\n\n", answer);       // ������ �հ� ���
    printf("[----- [���ؼ�] [2021041051] -----]");
}

float sum1(float list[], int n) {               // �迭�μ� �ּҸ� ����
    printf("list\t= %p\n", list);               // ���� �迭�� �ּҰ� ���
    printf("&list\t= %p\n\n", &list);           // �Լ����� ������� list�迭�� �ּҰ� ���
    int i;
    float tempsum = 0;
    for(i = 0;i < n;i++)
        tempsum += list[i];
    return tempsum;
}
float sum2(float *list, int n) {                // �����ͷμ� �ּҸ� ����
    printf("list\t= %p\n", list);               // ���� �迭�� �ּҰ� ���
    printf("&list\t= %p\n\n", &list);           // �Լ����� ������� list�迭�� �ּҰ� ���
    int i;
    float tempsum = 0;
    for(i = 0;i < n;i++)
        tempsum += *(list + i);                 // �����Ϳ� ������ ���� ���Ͽ� ���� �迭�� ������ �� ���� �����Ѵ�
    return tempsum;
}
/* stack variable reuse test */
float sum3(int n, float *list) {                // �����ͷμ� �ּҸ� ����
    printf("list\t= %p\n", list);               // ���� �迭�� �ּҰ� ���
    printf("&list\t= %p\n\n", &list);           // �Լ����� ������� list�迭�� �ּҰ� ���
    int i;
    float tempsum = 0;
    for(i = 0;i < n;i++)
        tempsum += *(list +i);
    return tempsum;
}