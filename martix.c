#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int **makematrix(int row,int col){  // 2차원 배열 동적할당 함수
    int **matrix=(int**)malloc(row*sizeof(int*));   // 1차원 배열부터 동적할당
    for(int i=0;i<row;i++){
        matrix[i]=(int*)malloc(col*sizeof(int));    // 1차원 배열에 따른 2차원 배열 동적 할당
    }
    return matrix;  // 동적할당된 2차원 배열
}

void free_matrix(int **matrix,int row){   // 2차원 배열 free 함수
    for(int i=0;i<row;i++){
        free(matrix[i]);    // 할당된 2차원 배열 free
    }
    free(matrix);   // 할당된 1차원 배열 free
}

void rand_matrix(int **mat,int row,int col){    // 2차원 배열에 무작위로 수를 받는 함수
    srand(time(NULL));  // 수를 무작위로 받기위해 초기화 해준다
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            mat[i][j]=rand()%10;    // 0부터 9까지의 값을 무작위로 받는다
        }
    }
}

void print_matrix(int **mat,int row,int col){   // 2차원 배열을 출력하는 함수
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int **addition_matrix(int **A,int **B,int **temp,int row,int col){  // 2차원 배열 2개를받아 더한 값을 temp에 받아 리턴하는 함수
    printf("addition_matrix\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp[i][j]=A[i][j]+B[i][j]; // 2차원 배열 두개에서 그에 맞는 원소값을 더해 temp에 받아준다
        }
    }
    return temp;    // 2차원 배열 temp 리턴
}

int **subtraction_matrix(int **A,int **B,int **temp,int row,int col){   // 2차원 배열 2개를 받아 뺀 값을 temp에 받아 리턴하는 함수
    printf("subtraction_matrix\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp[i][j]=A[i][j]-B[i][j]; // 2차원 배열 두개에서 그에 맞는 원소값을 빼서 temp에 받아준다
        }
    }
    return temp;    // 2차원 배열 temp 리턴
}

int **transpose_matrix(int **mat,int **temp,int row,int col){   // 2차원 배열을 받아 전치한 값을 temp에 받아 리턴하는 함수
    printf("transpose_matrix\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp[i][j]=mat[j][i];   // 2차원 배열을 행과 열을 바꾸어 temp에 받아준다
        }
    }
    return temp;    // 2차원 배열 temp 리턴
}

int **multiply_matrix(int **A,int **B,int **temp,int row,int col){  // 2차원 배열 2개를 행렬곱한 값을 temp에 받아 리턴하는 함수
    printf("multiply_matrix\n");
    int t=row;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp[i][j]=0;   // 2차원 배열 temp를 초기화 해준다
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            for(int n=0;n<t;n++){
                temp[i][j]+=A[i][n]*B[n][j];
            }
        }
    }
    return temp;
}

int main(){
    int row,col;
    printf("insert row,col : ");
    scanf("%d %d",&row,&col);
    int **matrix_A=makematrix(row,col);
    int **matrix_B=makematrix(row,col);
    int **temp=makematrix(row,col);
    rand_matrix(matrix_A,row,col);
    rand_matrix(matrix_B,row,col);
    printf("matrix_A\n");
    print_matrix(matrix_A,row,col);
    printf("matrix_B\n");
    print_matrix(matrix_B,row,col);
    print_matrix(addition_matrix(matrix_A,matrix_B,temp,row,col),row,col);
    print_matrix(subtraction_matrix(matrix_A,matrix_B,temp,row,col),row,col);
    print_matrix(transpose_matrix(matrix_A,temp,row,col),row,col);
    print_matrix(transpose_matrix(matrix_B,temp,row,col),row,col);
    print_matrix(multiply_matrix(matrix_A,matrix_B,temp,row,col),row,col);
    free_matrix(matrix_A,row);
    free_matrix(matrix_B,row);
    free_matrix(temp,row);
    printf("[----- [전준석] [2021041051] -----]");
    return 0;
}