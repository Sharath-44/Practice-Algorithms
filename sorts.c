#include<stdio.h>
#include<time.h>
#include<stdlib.h>
// sorting.....


void ssort(int *,int);
void bsort(int*,int);
void isort(int*, int);
void insertionSort(int *, int );
int binarySearch(int*, int,int,int);
#define nano 1000000000L
int main()
{  
 int a[1000000];
 int i,n;
  double time ;
 struct timespec start, stop;
 n=100;
 for(i=0;i<n;i++)
   a[i]=rand()%100;
 printf("Before sorting..\n");
 for(i=0;i<n;++i)
  printf("%d ",a[i]);
clock_gettime(CLOCK_REALTIME,&start);
 isort(a, n);
 clock_gettime(CLOCK_REALTIME,&stop);
 printf("\nAfter sorting...\n");
 for(i=0;i<n;i++)
   printf(" %d",a[i]);
 time=(stop.tv_sec-start.tv_sec)+(double)(stop.tv_nsec-start.tv_nsec)/nano; 
 printf("\nTime = %lf seconds",time);
}

void bsort(int a[], int n)
{
    int i,j,t, flag;
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                flag = 1;
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
        if(flag==0)
            break;
    }
}

void ssort(int a[], int n)
{
    int i,j,t, min;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
            if(min != i)
            {
                t=a[i];
                a[i] = a[min];
                a[min] = t;
            }
        }
    }
}

void isort(int a[], int n)
{
    int i, j, key, pos;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        key = a[i];
        pos = binarySearch(a,key,0,j);
        while (j >= pos)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int binarySearch(int a[], int key, int l, int h)
{
    int mid;
    mid = (l+h)/2;
    if(a[mid]==key)
        return mid+1;
    if(h<=l)
    {
        if(key>a[l])
            return l+1;
        else
            return l;
    }
    if(key>a[mid])
        return binarySearch(a,key,mid+1,h);
    else
        return binarySearch(a,key,l,mid-1);
}

