#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 10

// Graph는 인접리스트로 구현하였고 방향이 있는 direct graph로 구현하였습니다
typedef struct node{    // 노드는 vertex 값과 다음 노드를 가리키는 포인터로 구성
    int vertex;
    struct node* next;
} Node;

typedef struct graph{   // 그래프는 vertex인 헤드노드를 가지고 있고 헤드노드는 다음 vertex를 가리키는 포인터와 방문 여부를 나타내는 flag로 구성
    struct node *link;
    bool flag;  // 각각의 vertex는 방문여부를 나타내는 bool변수 flag로 ture면 방문되었다, false면 방문되지 않았다
} Graph;

void initialize_graph(Graph **g);
void insert_vertex(Graph **g,int index);
void insert_edge(Graph **g,int index, int vertex);
void dfs(Graph **g, int start);
void bfs(Graph **g, int start);
void print_graph(Graph **g);
void free_graph(Graph **g);
void reset_flag(Graph **g);

int main()
{
	char command;
	int index,vertex;
    Graph *adjlists[SIZE];  // 그래프는 vertex를 10개 가지므로 헤드노드를 배열로써 크기를 10만큼 선언하였다

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                       Graph Searches                           \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph     = z                                       \n");
		printf(" Insert Vertex        = v        Insert Edge                 = e\n");
		printf(" Depth First Search   = d        Breath First Search         = b\n");
		printf(" Print Graph          = p        Quit                        = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
            initialize_graph(adjlists);
			break;
		case 'v': case 'V':
            printf("enter vertex number in 0 ~ 9: ");
            scanf("%d",&index);
            if(index>=0&&index<SIZE){   // 0~9 사이의 숫자를 입력받을 때
                insert_vertex(adjlists,index);
            }
            else{
                printf("out of range\n");
            }
			break;
		case 'e': case 'E':
            printf("enter starting vertex : ");
            scanf("%d",&index);
            if(index>=0&&index<SIZE){   // 0~9 사이의 숫자를 입력받을 때
                printf("enter destination vertex : ");
                scanf("%d",&vertex);
                if(vertex>=0&&vertex<SIZE&&index!=vertex){  // starting vertex와 destination vertex가 같지 않을 때
                    insert_edge(adjlists,index,vertex);
                }
                else printf("invalid vertex for edge\n");
            }
            else printf("this graph does not have that vertex\n");
			break;
		case 'd': case 'D':
			printf("enter strating vertex for dfs : ");
			scanf("%d",&index);
            if(index>=0&&index<SIZE){   // 0~9 사이의 숫자를 입력받을 때
                reset_flag(adjlists);
                printf("dfs traversal : ");
                dfs(adjlists,index);
                printf("\n");
            }
            else{
                printf("invalid vertex\n");
            }
			break;
		case 'b': case 'B':
            printf("enter starting vertex for bfs : ");
            scanf("%d",&index);
            if(index>=0&&index<SIZE){   // 0~9 사이의 숫자를 입력받을 때
                reset_flag(adjlists);
                printf("bfs traversal : ");
                bfs(adjlists,index);
                printf("\n");
            }
            else{
                printf("invslid vertex\n");
            }
            break;
		case 'p': case 'P':
            print_graph(adjlists);
			break;
        case 'q': case 'Q':
            printf("[----- [전준석] [2021041051] -----]\n");
            break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');
    free_graph(adjlists);
	return 1;
}

void initialize_graph(Graph **g){   // 그래프 초기화 하는 함수
    for(int i=0;i<SIZE;i++){
        g[i]=NULL;
    }
}

void free_graph(Graph **g) {    // 그래프를 할당 해제하는 함수
    for (int i=0;i<SIZE;i++) {
        if (g[i]!=NULL) {   // vertex가 존재하는지 확인
            Node *node=g[i]->link;
            while(node) {   // vertex의 edge들을 free
                Node *temp=node;
                node=node->next;
                free(temp);
            }
            free(g[i]); // vertex를 free
        }
    }
}

void print_graph(Graph **g){    // 그래프를 출력하는 함수
    Node *node=NULL;

    for(int i=0;i<SIZE;i++){
        if(g[i]){   // vertex가 존재하는지 확인
            printf("[ %d ]", i);
            node=g[i]->link;
            while (node) {  // vertex의 edge들을 출력
                printf(" -> %d", node->vertex);
                node=node->next;
            }
            printf("\n");
        }
    }
}

void insert_vertex(Graph **g, int index) {  // vertex를 삽입하는 함수
	if(g[index]!=NULL) printf("vertex already exists"); // 삽입할 vertex가 이미 존재할 때

	else {
		g[index]=(Graph*)malloc(sizeof(Graph)); // 삽일할 vertex를 동적할당
		g[index]->flag=false;   // flag를 false값으로 초기화
		g[index]->link=NULL;    // 초기 vertex는 edge가 없기 때문에 link를 NULL로 초기화
	}
}

void insert_edge(Graph **g, int index, int vertex) {    // vertex간의 edge를 삽입하는 함수
	if(g[index]==NULL||g[vertex]==NULL){    // 시작vertex와 도착vertex가 존재하는지 확인
		printf("not exist vertex\n");
		return;
	}

    Node *node = (Node *)malloc(sizeof(Node));  // edge를 삽입할 노드를 동적할당
    node->vertex = vertex;  // edge의 도착vertex를 삽입
    node->next = NULL;  // 초기에는 다음 edge가 없기 때문에 NULL로 초기화

    if (g[index]->link == NULL) {   // vertex에 edge가 없을 때
        g[index]->link = node;
    }
	else {  // vertex에 edge가 있을 때
		Node* prev=NULL;
		Node* current=g[index]->link;
		while(current!=NULL&&current->vertex<node->vertex){ // vertex의 값이 작은 순서대로 edge를 삽입하기 위해
			prev=current;
			current=current->next;
		}

		if(current!=NULL&&current->vertex==node->vertex){   // edge가 이미 존재할 때
			printf("edge already exsits\n");
			free(node); // 할당받은 노드를 해제
			return;
		}

		if(prev==NULL){ // 삽입할 edge가 맨 앞에 삽입할 때
			node->next=g[index]->link;
			g[index]->link=node;
		}
		else{   // 삽입할 edge가 중간에 삽입할 때
			node->next=current;
			prev->next=node;
		}
	}
}

void reset_flag(Graph **g){ // 그래프의 flag를 초기화하는 함수
    for(int i=0;i<SIZE;i++){
        if(g[i]!=NULL){
            g[i]->flag=false;
        }
    }
}

void dfs (Graph **g,int start){ // 깊이 우선 탐색 함수 (deep first search) 재귀적으로 구현 (recursive)
    g[start]->flag=true;    // 탐색할 vertex의 flag를 true로 변경
    printf("[%d]",start);
    Node *pn=g[start]->link;    // vertex의 edge로서 다음 vertex를 가리킴
    while(pn!=NULL){    // edge가 존재할 때까지 반복
        if(g[pn->vertex]->flag==false){ // 다음 vertex가 방문되지 않을 경우
            dfs(g,pn->vertex);  // 다음 vertex로 이동
        }
        pn=pn->next;    // 다음 edge로 이동
    }
}

void bfs(Graph **g,int start){  // 너비 우선 탐색 함수 (breath first search) 반복과 큐로 구현 (iterative + queue)
    int queue[SIZE];    // 크기가 10인 큐 선언
    int front=0,rear=0; // front, rear 초기화

    g[start]->flag=true;    // 탐색할 vertex의 flag를 true로 변경
    queue[rear++]=start;    // 큐에 탐색한 vertex를 삽입
    printf("[%d]",start);

    while(front<rear){  // 큐가 빌때까지 반복
        int current=queue[front++]; // 큐에서 vertex를 꺼냄
        Node *pn=g[current]->link;  // vertex의 edge로서 다음 vertex를 가리킴
        while(pn!=NULL){    // edge가 존재할 때까지 반복
            if(g[pn->vertex]->flag==false){ // 다음 vertex가 방문되지 않았을 때
                g[pn->vertex]->flag=true;   // 다음 vertex가 방문되었음 따라서 flag를 true로 변경
                printf("[%d]",pn->vertex);
                queue[rear++]=pn->vertex;   // 큐에 다음 vertex를 삽입
            }
            pn=pn->next;    // 다음 edge로 이동
        }
    }
}