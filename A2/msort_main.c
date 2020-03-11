// Use "gcc -O3 -fopenmp" to compile

#include <omp.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#define N (10000000)
int A[N],B[N];

void Merge_Sort_Par(int a[],int b[],int n, int nThreads);



void Merge(a,b,lo,mid,hi)
     int a[],b[], lo,mid,hi;
{
  int h,i,j,k;
  h = lo;
  i = lo;
  j = mid+1;
  while ((h<=mid) && (j<=hi))
    { if (a[h]<=a[j]) b[i++] = a[h++]; else b[i++] = a[j++]; }
  if (h>mid)
    {  for(k=j;k<=hi;k++) b[i++] = a[k]; }
  else
    {  for(k=h;k<=mid;k++) b[i++] = a[k]; }
  for(k=lo;k<=hi;k++) a[k] = b[k];
}


void Merge_Sort(int a[],int b[],int lo, int hi)
{
  int temp,mid;
  if (lo < hi)
    { if (hi == lo+1)
	{ if (a[hi]<a[lo]) {temp=a[hi];a[hi]=a[lo];a[lo]=temp;}}
      else
	{ mid = (lo+hi)/2;
	  Merge_Sort(a,b,lo,mid);
	  Merge_Sort(a,b,mid+1,hi);
	  Merge(a,b,lo,mid,hi);
	}
    }
}

void Test_Sorted(a,lo,hi)
     int a[],lo,hi;
{ int i, notsorted;
  notsorted = 0;
  for(i=lo+1;i<=hi;i++)
    if(a[i-1]>a[i]) notsorted++;
  if (notsorted>0) printf("sequence is not sorted in increasing order; # flips =%d\n",notsorted);
  else printf("sequence is sorted\n");
}

void Dump(a,lo,hi)
     int a[],lo,hi;
{ int i;
  for(i=lo;i<=hi;i++) printf("%d ",a[i]);
  printf("\n");
}

int main(int argc, char *argv[]){
    int nThreads;
    
    if ( argc != 2 ) {
      printf("Number of threads not specified\n");
      exit(-1);
    }
    nThreads = atoi(argv[1]);
    if ( nThreads <= 0 ) {
      printf("Num threads <= 0\n");
      exit(-1);
    }
    printf("Num threads = %d\n", nThreads );

    
    double rtclock(void);
    int omp_get_num_threads(void);
    
    double clkbegin, clkend;
    double t;
    
    int i,j,k;
    printf("List Size = %d\n",N);

    for(i=0;i<N;i++)  A[i] = N-i;
    printf("Initial "); Test_Sorted(A,0,N-1); 
    clkbegin = rtclock();
    Merge_Sort(A,B, 0, N-1);
    clkend = rtclock();
    printf("After sequential sort, "); Test_Sorted(A,0,N-1); 
    t = clkend-clkbegin;
    printf("Sequential Sort Rate: %.1f Mega-Elements/Second; Time = %.3f sec; a[n/2] = %d; \n\n",
	   1.0e-6*N/t,t,A[N/2]);
    
    for(i=0;i<N;i++)  A[i] = N-i;
    printf("Reinitialized "); 
    Test_Sorted(A,0,N-1); 
    clkbegin = rtclock();
    Merge_Sort_Par(A,B, N, nThreads);
    clkend = rtclock();
    t = clkend-clkbegin;
    printf("After parallel sort, "); 
    Test_Sorted(A,0,N-1); 
    printf("Parallel Sort Rate: %.1f Mega-Elements/Second; Time = %.3f sec; a[N/2] = %d; \n",
      1.0*N/t/1000000,t,A[N/2]);
    
}
double rtclock(void)
{
  struct timezone Tzp;
  struct timeval Tp;
  int stat;
  stat = gettimeofday (&Tp, &Tzp);
  if (stat != 0) printf("Error return from gettimeofday: %d",stat);
  return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
}
