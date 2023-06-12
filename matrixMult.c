//Write a function to do matrix addition and find the time
//n = 32, 64, 128, 256

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int addition(int (*a)[256], int (*b)[256], int n)
{
    int c[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int multiplication(int (*a)[256], int (*b)[256], int n)
{
    int c[n][n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; ++k)
                c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

void checkIdentity(int (*a)[256], int n)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && a[i][j] != 1)
            {
                flag = -1;
                break;
            }
            else if (i != j && a[i][j] != 0)
            {
                flag = -1;
                break;
            }
        }
    }

    if (flag == 0)
    {
        printf("It is a IDENTITY MATRIX\n");
    }
    else
    {
        printf("It is NOT an identity matrix\n");
    }
}

void checkSymmetric(int (*a)[256], int n)
{
    
}

    int main()
{
    int n;
    printf("Enter order: ");
    scanf("%d", &n);
    int a[n][n];
    int b[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    }
    addition(a, b, n);
}





