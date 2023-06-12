#include <stdio.h>

void swap(int *, int *);
int findME(int a[], int d[], int n);
void johnson_trotter(int a[], int d[], int n);
void bsort(int a[], int n);
void input(int *a, int *d, int n);

void main()
{
    int a[4];
    int d[4];
    int n;
    printf("Enter size:\n");
    scanf("%d",&n);
    input(a,d,n);
    
    printf("Before sorting...\n");
    johnson_trotter(a, d, n);
    printf("1010\n");

    printf("After sorting...\n");
    bsort(a, n);
    
    johnson_trotter(a, d, n);
    printf("1010\n");

    return;
}

void input(int *a, int *d, int n)
{
    printf("Enter elements and direction: \n");
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        scanf("%d", &d[i]);
    }
}

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void johnson_trotter(int a[], int d[], int n)
{
    int ME, i;
    for (i = 0; i < n; i++)
        printf("%d", a[i]);
    printf("\n");
    ME = findME(a, d, n);
    while (ME != -1)
    {
        if (d[ME] == 0)
        {
            swap(&a[ME], &a[ME - 1]);
            swap(&d[ME], &d[ME - 1]);
            ME--;
        }
        else
        {
            swap(&a[ME], &a[ME + 1]);
            swap(&d[ME], &d[ME + 1]);
            ME++;
        }
        for (i = 0; i < n; i++)
            if (a[i] > a[ME])
                d[i] = ((d[i] == 0) ? 1 : 0);
        for (i = 0; i < n; i++)
            printf("%d", a[i]);
        printf("\n");
        ME = findME(a, d, n);
    }
}

int findME(int a[], int d[], int n)
{
    int curME = -1;
    int MEindex = -1;
    int i;
    for (i = 0; i < n; i++)
    {
        if (i == 0 && d[i] == 0)
            continue;
        else if (i == n - 1 && d[i] == 1)
            continue;
        else
        {
            if (d[i] == 0)
            {
                if (a[i - 1] < a[i] && curME < a[i])
                {
                    MEindex = i;
                    curME = a[i];
                }
            }
            else
            {
                if (a[i + 1] < a[i] && curME < a[i])
                {
                    MEindex = i;
                    curME = a[i];
                }
            } // end of else
        }     // end of for
    }
    return MEindex;
}

void bsort(int a[], int n)
{
    int i, j, t, flag;
    for (i = 0; i < n; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                flag = 1;
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
        if (flag == 0)
            break;
    }
}