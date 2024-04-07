#include<stdio.h>
#include<stdlib.h>

int **makematrix(int row,int col){
    int **matrix=(int**)malloc(row*sizeof(int*));
    for(int i=0;i<row;i++){
        matrix[i]=(int*)malloc(col*sizeof(int));
    }
    return matrix;
}

void free_matrix(int **matrix,int row){
    for(int i=0;i<row;i++){
        free(matrix[i]);
    }
    free(matrix);
}

void rand_matrix(int **mat,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            mat[i][j]=rand()%10;
        }
    }
}

void print_matrix(int **mat,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int **addition_matrix(int **A,int **B,int **temp,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp[i][j]=A[i][j]+B[i][j];
        }
    }
    return temp;
}

int **subtraction_matrix(int **A,int **B,int **temp,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp[i][j]=A[i][j]-B[i][j];
        }
    }
    return temp;
}

int **transpose_matrix(int **mat,int **temp,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp[i][j]=mat[j][i];
        }
    }
    return temp;
}

int **multiply_matrix(int **A,int **B,int **temp,int row,int col){
    int t=row;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp[i][j]=0;
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
    scanf("%d %d",&row,&col);
    int **matrix_A=makematrix(row,col);
    int **matrix_B=makematrix(row,col);
    int **temp=makematrix(row,col);
    rand_matrix(matrix_A,row,col);
    rand_matrix(matrix_B,row,col);
    print_matrix(matrix_A,row,col);
    print_matrix(matrix_B,row,col);
    print_matrix(addition_matrix(matrix_A,matrix_B,temp,row,col),row,col);
    print_matrix(subtraction_matrix(matrix_A,matrix_B,temp,row,col),row,col);
    print_matrix(transpose_matrix(matrix_A,temp,row,col),row,col);
    print_matrix(transpose_matrix(matrix_B,temp,row,col),row,col);
    print_matrix(multiply_matrix(matrix_A,matrix_B,temp,row,col),row,col);
    free_matrix(matrix_A,row);
    free_matrix(matrix_B,row);
    free_matrix(temp,row);
    return 0;
}