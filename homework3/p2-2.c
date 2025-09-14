#include <stdio.h>
void print_one(int *ptr, int rows);

int main(){
    int one[] = {0, 1, 2, 3, 4};            // ũ�� 5�� �迭 ����
    printf("one = %p\n", one);              // �迭�� �̸����μ� ������ �̰� �迭�� ���� �ּҰ� ���
    printf("&one = %p\n", &one);            // �迭�� �̸����μ� ������ �̰� �������� �ּҰ� ���
    printf("&one[0] = %p\n", &one[0]);      // �迭�� �̸����μ� ������ �̰� �迭�� ù��° �ּҰ� ���
    printf("\n");
    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("------------------------------------\n");
    print_one(&one[0], 5);                  // �迭�� ù��° �ּҰ��� �ѱ�
    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    print_one(one, 5);                      // �迭�� �̸�, �� �迭�� �ּҰ��� �ѱ�
    printf("[----- [���ؼ�] [2021041051] -----]");
    return 0;
}

void print_one(int *ptr, int rows){     // �����ͷμ� �迭�� �ּҰ��� ����
/* print out a one-dimensional array using a pointer */
    int i;
    printf ("Address \t Contents\n");
    for (i = 0; i < rows; i++)
        printf("%p \t %5d\n", ptr + i, *(ptr + i));     // �����Ϳ� ������ ���� �������μ� �迭�� �ϳ��� �����Ͽ� �ּҿ� ���� ����ϰ� �ִ�
    printf("\n");
}