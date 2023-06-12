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
 insertionSortfxn(a,n);
 clock_gettime(CLOCK_REALTIME,&stop);
 printf("\nAfter sorting...\n");
 for(i=0;i<n;i++)
   printf(" %d",a[i]);
 time=(stop.tv_sec-start.tv_sec)+(double)(stop.tv_nsec-start.tv_nsec)/nano; 
 printf("\nTime = %lf seconds",time);
}
