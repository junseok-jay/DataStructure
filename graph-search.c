#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 10

typedef struct node{    // 각 그래프의 노드로써 vertex의 값과 다음 노드를 가리키는 포인터를 가지고 있다
    int vertex;
    struct node* next;
} Node;

typedef struct graph{   // 각 그래프의 노드를 가리키는 헤드노드로써 방문했는지를 판단하는 bool변수 flag를 가지고 있다
    struct node *link;
    bool flag;
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
    Graph *adjlists[SIZE];

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
            printf("enter vertex number : ");
            scanf("%d",&index);
            insert_vertex(adjlists,index);
			break;
		case 'e': case 'E':
            printf("enter starting vertex : ");
            scanf("%d",&index);
            if(index>=0&&index<SIZE){
                printf("enter destination vertex : ");
                scanf("%d",&vertex);
                if(vertex>=0&&vertex<SIZE&&index!=vertex){
                    insert_edge(adjlists,index,vertex);
                }
                else printf("invalid vertex for edge\n");
            }
            else printf("this graph does not have that vertex\n");
			break;
		case 'd': case 'D':
			printf("enter strating vertex for dfs : ");
			scanf("%d",&index);
            if(index>=0&&index<SIZE){
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
            if(index>=0&&index<SIZE){
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

void initialize_graph(Graph **g){
    for(int i=0;i<SIZE;i++){
        g[i]=NULL;
    }
}

void free_graph(Graph **g) {
    for (int i=0;i<SIZE;i++) {
        if (g[i]!=NULL) {
            Node *node=g[i]->link;
            while(node) {
                Node *temp=node;
                node=node->next;
                free(temp);
            }
            free(g[i]);
        }
    }
}

void print_graph(Graph **g){
    Node *pg=NULL;

    for(int i=0;i<SIZE;i++){
        if(g[i]){
            printf("[ %d ]", i);
            pg=g[i]->link;
            while (pg) {
                printf(" -> %d", pg->vertex);
                pg=pg->next;
            }
            printf("\n");
        }
    }
}

void insert_vertex(Graph **g, int index) {
    if (index >= 0 && index < SIZE) {
		if(g[index]!=NULL) printf("vertex already exists");
		else {
			g[index]=(Graph*)malloc(sizeof(Graph));
			g[index]->flag=false;
			g[index]->link=NULL;
		}
    } else {
        printf("This graph does not have that vertex\n");
    }
}

void insert_edge(Graph **g, int index, int vertex) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->vertex = vertex;
    node->next = NULL;

	if(g[index]==NULL||g[vertex]==NULL){
		printf("not exist vertex\n");
		return;
	}

    if (g[index]->link == NULL) {
        g[index]->link = node;
    }
	else {
		Node* prev=NULL;
		Node* current=g[index]->link;
		while(current!=NULL&&current->vertex<node->vertex){
			prev=current;
			current=current->next;
		}

		if(current!=NULL&&current->vertex==node->vertex){
			printf("edge already exsits\n");
			free(node);
			return;
		}

		if(prev==NULL){
			node->next=g[index]->link;
			g[index]->link=node;
		}
		else{
			node->next=current;
			prev->next=node;
		}
	}
}
void reset_flag(Graph **g){
    for(int i=0;i<SIZE;i++){
        if(g[i]!=NULL){
            g[i]->flag=false;
        }
    }
}

void dfs (Graph **g,int start){
    g[start]->flag=true;
    printf("[%d]",start);
    Node *pn=g[start]->link;
    while(pn!=NULL){
        if(g[pn->vertex]->flag==false){
            dfs(g,pn->vertex);
        }
        pn=pn->next;
    }
}

void bfs(Graph **g,int start){
    int queue[SIZE];
    int front=0,rear=0;

    g[start]->flag=true;
    queue[rear++]=start;
    printf("[%d]",start);

    while(front<rear){
        int current=queue[front++];
        Node *pn=g[current]->link;
        while(pn!=NULL){
            if(g[pn->vertex]->flag==false){
                g[pn->vertex]->flag=true;
                printf("[%d]",pn->vertex);
                queue[rear++]=pn->vertex;
            }
            pn=pn->next;
        }
    }
}