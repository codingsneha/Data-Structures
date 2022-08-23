/* Program to convert sparse matrix to compact matrix and compact matrix to sparse matrix

A matrix such that most of the elements have value 0, is a Sparse Matrix.

The non-zero values are represented in a compact form in order to reduce space occupied by the matrix.

The compact form of a sparse matrix contains three columns,
    comlumn 1 has row number,
    column 2 has column number,
    column 3 has the value of non-zero element.

The first row of our sparse matrix in compact form will contain [total number of rows]
    [total number of columns] and [total number of non-zero elements]  */


#include <stdio.h>
#include <stdlib.h>

void GetMatrix(int a[10][10], int row, int column);
void CompactToSparse(int a[10][10], int b[20][10], int row);
void SparseToCompact(int a[10][10], int row, int column, int b[20][10]);
void DisplaySparse(int a[10][10], int row, int column);
void DisplayCompact(int b[20][10]);
void transpose(int b[20][10]);


int main(){
    int a[10][10], b[20][10], row, column;
    printf("\nEnter the number of rows and columns:\n");
    scanf("%d%d", &row, &column);

    printf("\nConvert to - \n1. Sparse\n2. Compact\n3.Transpose of compact\nEnter 1 or 2 or 3: ");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            GetMatrix(b, row, column);
            CompactToSparse(a, b, row);
            DisplaySparse(a, row, column);

            break;
        case 2:
            GetMatrix(a, row, column);
            SparseToCompact(a, row, column, b);
            DisplayCompact(b);
            break;

        case 3:
            GetMatrix(b, row, column);
            transpose(b);
            break;

        default:
            printf("\nEnter valid choice!\n");
    }

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

    printf("\nYour Matrix - \n\n");
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}



void SparseToCompact(int a[10][10], int row, int column, int b[20][10]){
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
    }
    b[0][2] = k - 1;
}




void DisplayCompact(int b[20][10]){
    int i, column;
    column = b[0][2];
    printf("\nCompact Form - \n\nR\tC\tV\n");
    for (i = 0; i <= column; i++){
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}




void CompactToSparse(int a[10][10], int b[20][10], int row){

    int r, c;
    r=b[0][0];
    c=b[0][1];

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            a[i][j]=0;
        }
    }

    for(int i=0; i<row; i++){
        a[(b[i][0])][(b[i][1])]=b[i][2];
    }
}


void DisplaySparse(int a[10][10], int row, int column){
    printf("\nSparse Form - \n\nR\tC\tV\n");
    for(int i=0; i<row; i++){
        for (int j=0; j<column; j++){
            printf("%d\t", &a[i][j]);
        }
        printf("\n");
    }
}



void transpose(int b[20][10]){
    int a[10][10];
    a[0][1]=b[0][0];
    a[0][0]=b[0][1];
    a[0][2]=b[0][2];
    int q=1;
    if(a[0][2]<=0)
        exit(0);
    
    for(int i=0; i<a[0][0]; i++){
        for(int p=1; p<=a[0][2]; p++){
            if(b[p][1]==i){
                a[q][0]=b[p][1];
                a[q][1]=b[p][0];
                a[q][2]=b[p][2];
                q=q+1;
            }
        }
    }

    printf("\nTranspose - \n\nR\tC\tV\n");
    for(int i=0; i<=a[0][2]; i++){
        for(int j=0; j<3; j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}