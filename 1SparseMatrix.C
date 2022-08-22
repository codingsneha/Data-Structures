/* Program to convert sparse matrix to compact matrix and compact matrix to sparse matrix

A matrix such that most of the elements have value 0, is a Sparse Matrix.

The non-zero values are represented in a compact form in order to reduce space occupied by the matrix.

The compact form of a sparse matrix contains three columns,
    comlumn 1 has row number,
    column 2 has column number,
    column 3 has the value of non-zero element.

The first row of our sparse matrix will contain [total number of rows], 
    [total number of columns] and [total number of non-zero elements]  */


#include <stdio.h>
#define MAX 20


void GetMatrix(int a[10][10], int row, int column);
void Display(int b[MAX][3]);
void CompactToSparse(int a[10][10], int row, int column, int b[MAX][3]);


int main(){
    int a[10][10], b[MAX][3], row, column;
    printf("\nEnter the number of rows and columns:\n");
    scanf("%d%d", &row, &column);

    GetMatrix(a, row, column);
    CompactToSparse(a, row, column, b);
    Display(b);
    return 0;
}



void GetMatrix(int a[10][10], int row, int column){
    printf("\nEnter elements of matrix\n");
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            printf("\nRow %d Column %d: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nSparse Form -\n");
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}



void CompactToSparse(int a[10][10], int row, int column, int b[MAX][3]){
    int k = 1;
    b[0][0] = row;
    b[0][1] = column;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (a[i][j] != 0){
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
        b[0][2] = k - 1;
    }
}




void Display(int b[MAX][3]){
    int i, column;
    column = b[0][2];
    printf("\nCompact Form - \n\n");
    for (i = 0; i <= column; i++){
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}