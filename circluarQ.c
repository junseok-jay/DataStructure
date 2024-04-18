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
}QueueType;     // 원형 큐의 구조체 선언

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
    printf("[----- [전준석] [2021041051] -----]\n");
	return 1;
}

QueueType *createQueue()
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));    // queuetpye 구조체의 크기만큼 메모리 할당
    for(int i=0;i<MAX_QUEUE_SIZE;i++){
        cQ->queue[i]=0;    // 큐의 모든 원소를 0으로 초기화
    }
	cQ->front = 0;  // front를 0으로 초기화
	cQ->rear = 0;   // rear를 0으로 초기화    
	return cQ;  // 할당된 queue를 반환
}

int freeQueue(QueueType *cQ)
{
    if(cQ == NULL) return 1;    // cQ가 비었으면 메모리 해제하지 않음
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
    if(cQ->front==cQ->rear){    // front와 rear가 같으면 큐가 비어있고 1 반환
        return 1;
    }
    return 0;   // front 와 rear가 다르면 큐가 비어있지 않고 0 반환
}

/* complete the function */
int isFull(QueueType *cQ)
{
    if(cQ->front==(cQ->rear+1)%MAX_QUEUE_SIZE){
        return 1;   // rear에 1더한값이 front이면 큐가 가득찬것이고 rear+1이 큐의 마지막에 도달하면 다시 처음으로 돌아가야한다
    }
    return 0;
}


/* complete the function */
void enQueue(QueueType *cQ, element item)
{
    if(isFull(cQ)==1){
        printf("queue is full\n");  // 큐에 원소를 넣기전 가득차있는지 확인
        return;
    }
    cQ->rear=(cQ->rear+1)%MAX_QUEUE_SIZE;   // rear를 1증가시켜 준다 큐의 마지막에 도달하면 처음으로 돌아간다
    cQ->queue[cQ->rear]=item;   // rear에 item 삽입
	return;
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)
{
    if(isEmpty(cQ)==1){
        printf("queue is empty\n"); // 큐가 비어있는지 확인
        return;
    }
    cQ->front=(cQ->front+1)%MAX_QUEUE_SIZE; // front를 1증가시켜 준다
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