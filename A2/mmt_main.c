// Use "gcc -O3 -fopenmp" to compile

#include <omp.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#define N (1024)
#define threshold (0.0000001)
void compare(int n, float wref[][n], float w[][n]);
float c[N][N],b[N][N],a[N][N],cc[N][N];
void parallel_mmt(int n,float c[][n],float a[][n],float b[][n],int nThreads);


int main(int argc, char *argv[]){
  int nThreads;
  double rtclock(void);
  double clkbegin, clkend;
  double t1,t2;

  int i,j,k;

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
  omp_set_num_threads(nThreads);
  printf("Matrix Size = %d\n",N);

  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      {  a[i][j] = 1.1*(2*i+j);
	b[i][j] = 1.2*(i+2*j);
      }

  for(i=0;i<N;i++) for(j=0;j<N;j++) c[j][i] = 0;
  t1 = rtclock();
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      for(k=0;k<N;k++)
	c[j][i] = c[j][i] + a[k][i]*b[k][j];
  t2 = rtclock();
  printf("Base version: %.2f GFLOPs; Time = %.2f\n",2.0e-9*N*N*N/(t2-t1),t2-t1);

  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      cc[j][i] = c[j][i];

  // Verson to be parallelized and optimized
  // You can use any valid loop transformation before
  // OpenMP parallelization
  for(i=0;i<N;i++) for(j=0;j<N;j++) c[j][i] = 0;
  t1 = rtclock();

  parallel_mmt(N,c,a,b,nThreads);

  t2 = rtclock();
  printf("Optimized/parallelized version: %.2f GFLOPs; Time = %.2f\n",2.0e-9*N*N*N/(t2-t1),t2-t1);
  compare(N,c,cc);

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

void compare(int n, float wref[][n], float w[][n])
{
  float maxdiff,this_diff;
  int numdiffs;
  int i,j;
  numdiffs = 0;
  maxdiff = 0;
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
      {
	this_diff = wref[i][j]-w[i][j];
	if (this_diff < 0) this_diff = -1.0*this_diff;
	if (this_diff>threshold)
	  { numdiffs++;
	    if (this_diff > maxdiff) maxdiff=this_diff;
	  }
      }
  if (numdiffs > 0)
    printf("%d Diffs found over threshold %f; Max Diff = %f\n",
	   numdiffs,threshold,maxdiff);
  else
    printf("Passed Correctness Check\n");
}

