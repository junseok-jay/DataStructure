#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int **makematrix(int row,int col){  // 2���� �迭 �����Ҵ� �Լ�
    int **matrix=(int**)malloc(row*sizeof(int*));   // 1���� �迭���� �����Ҵ�
    for(int i=0;i<row;i++){
        matrix[i]=(int*)malloc(col*sizeof(int));    // 1���� �迭�� ���� 2���� �迭 ���� �Ҵ�
    }
    return matrix;  // �����Ҵ�� 2���� �迭
}

void free_matrix(int **matrix,int row){   // 2���� �迭 free �Լ�
    for(int i=0;i<row;i++){
        free(matrix[i]);    // �Ҵ�� 2���� �迭 free
    }
    free(matrix);   // �Ҵ�� 1���� �迭 free
}

void rand_matrix(int **mat,int row,int col){    // 2���� �迭�� �������� ���� �޴� �Լ�
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            mat[i][j]=rand()%10;    // 0���� 9������ ���� �������� �޴´�
        }
    }
}

void print_matrix(int **mat,int row,int col){   // 2���� �迭�� ����ϴ� �Լ�
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int **addition_matrix(int **A,int **B,int **temp,int row,int col){  // 2���� �迭 2�����޾� ���� ���� temp�� �޾� �����ϴ� �Լ�
    printf("addition_matrix\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp[i][j]=A[i][j]+B[i][j]; // 2���� �迭 �ΰ����� �׿� �´� ���Ұ��� ���� temp�� �޾��ش�
        }
    }
    return temp;    // 2���� �迭 temp ����
}

int **subtraction_matrix(int **A,int **B,int **temp,int row,int col){   // 2���� �迭 2���� �޾� �� ���� temp�� �޾� �����ϴ� �Լ�
    printf("subtraction_matrix\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp[i][j]=A[i][j]-B[i][j]; // 2���� �迭 �ΰ����� �׿� �´� ���Ұ��� ���� temp�� �޾��ش�
        }
    }
    return temp;    // 2���� �迭 temp ����
}

int **transpose_matrix(int **mat,int **temp,int row,int col){   // 2���� �迭�� �޾� ��ġ�� ���� temp�� �޾� �����ϴ� �Լ�
    printf("transpose_matrix\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp[i][j]=mat[j][i];   // 2���� �迭�� ��� ���� �ٲپ� temp�� �޾��ش�
        }
    }
    return temp;    // 2���� �迭 temp ����
}

int **multiply_matrix(int **A,int **B,int **temp,int row,int col){  // 2���� �迭 2���� ��İ��� ���� temp�� �޾� �����ϴ� �Լ�
    printf("multiply_matrix\n");
    int t=row;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp[i][j]=0;   // 2���� �迭 temp�� �ʱ�ȭ ���ش�
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            for(int n=0;n<t;n++){
                temp[i][j]+=A[i][n]*B[n][j];    // A�� ���� B�� ���� ���� �ٲٸ� ���Ͽ� temp�� �޾��ش�
            }
        }
    }
    return temp;    // 2���� �迭 temp ����
}

int main(){
    int row,col;
    srand(time(NULL));  // ���� �������� �ޱ����� �ʱ�ȭ ���ش�
    printf("insert row,col : ");
    scanf("%d %d",&row,&col);
    int **matrix_A=makematrix(row,col); // row X col¥�� ��� martrix_A ����
    int **matrix_B=makematrix(row,col); // row X col¥�� ��� martrix_B ����
    int **temp=makematrix(row,col); // row X col¥�� ��� temp ����
    rand_matrix(matrix_A,row,col);  // matrix_A �������� �ʱ�ȭ
    rand_matrix(matrix_B,row,col);  // matrix_B �������� �ʱ�ȭ
    printf("matrix_A\n");
    print_matrix(matrix_A,row,col);
    printf("matrix_B\n");
    print_matrix(matrix_B,row,col);
    print_matrix(addition_matrix(matrix_A,matrix_B,temp,row,col),row,col);  // matrix_A�� matrix_B�� ���� ���� ���
    print_matrix(subtraction_matrix(matrix_A,matrix_B,temp,row,col),row,col);   // matrix_A�� matrix_B�� �� ���� ���
    print_matrix(transpose_matrix(matrix_A,temp,row,col),row,col);  // matrix_A�� ��ġ�� ���� ���
    print_matrix(multiply_matrix(matrix_A,matrix_B,temp,row,col),row,col);  // matrix_A�� matrix_B�� ��İ��� ���� ���
    free_matrix(matrix_A,row);  // �Ҵ�� matrix_A free
    free_matrix(matrix_B,row);  // �Ҵ�� matrix_B free
    free_matrix(temp,row);  // �Ҵ�� temp free
    printf("[----- [���ؼ�] [2021041051] -----]");
    return 0;
}