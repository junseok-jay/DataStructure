#include <stdio.h>
#include <stdlib.h>

void main()
{
    int list[5];            // ũ�� 5�� �迭 ����
    int *plist[5];          // ũ�� 5�� ������ �迭 ����
    list[0] = 10;           // �迭 0��° �ڸ��� 10 �Է�
    list[1] = 11;           // �迭 1��° �ڸ��� 11 �Է�
    plist[0] = (int*)malloc(sizeof(int));       // ������ �迭 0��° �ڸ��� �����Ҵ� 
    printf("list[0] \t= %d\n", list[0]);        // �迭 0��° �ڸ��� 10 ���
    printf("list \t\t= %p\n", list);            // �迭 ù��° �ڸ��� �ּҰ� ���
    printf("&list[0] \t= %p\n", &list[0]);      // �迭 ù��° �ڸ��� �ּҰ� ���
    printf("list + 0 \t= %p\n", list+0);        // �迭 ù��° �ڸ��� �ּҰ� ���
    printf("list + 1 \t= %p\n", list+1);        // �迭 �ι�° �ڸ��� �ּҰ� ���
    printf("list + 2 \t= %p\n", list+2);        // �迭 ����° �ڸ��� �ּҰ� ���
    printf("list + 3 \t= %p\n", list+3);        // �迭 �׹�° �ڸ��� �ּҰ� ���
    printf("list + 4 \t= %p\n", list+4);        // �迭 �ټ���° �ڸ��� �ּҰ� ���
    printf("&list[4] \t= %p\n", &list[4]);      // �迭 �ټ���° �ڸ��� �ּҰ� ���
    printf("[----- [���ؼ�] [2021041051] -----]");
    free(plist[0]);                             // �����Ҵ� ����
}