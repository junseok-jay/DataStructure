/**
 * circularQ.c
 *
 * School of Computer Science, 
 * Chungbuk National University
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef char element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;     // ���� ť�� ����ü ����

QueueType *createQueue();
int freeQueue(QueueType *cQ);
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);
element getElement();

int main(void)
{
	QueueType *cQ = createQueue();
	element data;
	char command;

	do{
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			data = getElement();
			enQueue(cQ, data);
			break;
		case 'd': case 'D':
			deQueue(cQ, &data);
			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q':
   	        freeQueue(cQ);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');
    printf("[----- [���ؼ�] [2021041051] -----]\n");
	return 1;
}

QueueType *createQueue()
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));    // queuetpye ����ü�� ũ�⸸ŭ �޸� �Ҵ�
    for(int i=0;i<MAX_QUEUE_SIZE;i++){
        cQ->queue[i]=0;    // ť�� ��� ���Ҹ� 0���� �ʱ�ȭ
    }
	cQ->front = 0;  // front�� 0���� �ʱ�ȭ
	cQ->rear = 0;   // rear�� 0���� �ʱ�ȭ    
	return cQ;  // �Ҵ�� queue�� ��ȯ
}

int freeQueue(QueueType *cQ)
{
    if(cQ == NULL) return 1;    // cQ�� ������� �޸� �������� ����
    free(cQ);   
    return 1;
}

element getElement()
{
	element item;
	printf("Input element = ");
	scanf(" %c", &item);
	return item;
}


/* complete the function */
int isEmpty(QueueType *cQ)
{
    if(cQ->front==cQ->rear){    // front�� rear�� ������ ť�� ����ְ� 1 ��ȯ
        return 1;
    }
    return 0;   // front �� rear�� �ٸ��� ť�� ������� �ʰ� 0 ��ȯ
}

/* complete the function */
int isFull(QueueType *cQ)
{
    if(cQ->front==(cQ->rear+1)%MAX_QUEUE_SIZE){
        return 1;   // rear�� 1���Ѱ��� front�̸� ť�� ���������̰� rear+1�� ť�� �������� �����ϸ� �ٽ� ó������ ���ư����Ѵ�
    }
    return 0;
}


/* complete the function */
void enQueue(QueueType *cQ, element item)
{
    if(isFull(cQ)==1){
        printf("queue is full\n");  // ť�� ���Ҹ� �ֱ��� �������ִ��� Ȯ��
        return;
    }
    cQ->rear=(cQ->rear+1)%MAX_QUEUE_SIZE;   // rear�� 1�������� �ش� ť�� �������� �����ϸ� ó������ ���ư���
    cQ->queue[cQ->rear]=item;   // rear�� item ����
	return;
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)
{
    if(isEmpty(cQ)==1){
        printf("queue is empty\n"); // ť�� ����ִ��� Ȯ��
        return;
    }
    cQ->front=(cQ->front+1)%MAX_QUEUE_SIZE; // front�� 1�������� �ش�
    return;
}


void printQ(QueueType *cQ)
{
	int i, first, last;

	first = (cQ->front + 1)%MAX_QUEUE_SIZE;
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;

	printf("Circular Queue : [");

	i = first;
	while(i != last){
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE;

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if(i == cQ->front) {
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}