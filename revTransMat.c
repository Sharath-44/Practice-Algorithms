#include <stdio.h>

int mat[10][10];

void swap(int a, int b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

void rotate4(int a, int b, int c, int d)
{
   swap(a, b);
   swap(b, c);
   swap(c, d);
}

void rotateMatrix(int mat[10][10], int N) {
 	// Your code here
    for (int i = 0; i < N/2; i++) {
    for (int j = 0; j < (N + 1)/2; j++) {
        int r_i = (N - 1) - i;
        int r_j = (N - 1) - j;

        rotate4(
             mat[i][j],
             mat[r_j][i],
             mat[r_i][r_j],
             mat[j][r_i]
        );
    }
    }
}

void printMatrix(int mat[10][10], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }
  printf("\n");
}

int main() {
    int N;
    scanf("%d",&N);
        
    for(int i=0; i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &mat[i][j]);
        }
    }

  rotateMatrix(mat, N);
  printMatrix(mat,N);

  return 0;
}