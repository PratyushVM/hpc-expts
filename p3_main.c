#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#define N (1024)
#define tolerance (0.0000001)
double A[N][N],B[N][N],C[N][N];
double AA[N][N],BB[N][N],CC[N][N];

void p3(int n, double a[][n], double b[][n], double c[][n]);
void p3opt(int n, double a[][n], double b[][n], double c[][n]);

int main(){
double rtclock();
double clkbegin, clkend;
double t;
void compare();

int i,j,k;
  printf("Triangular Mat-Mult-Transpose: Matrix Size = %d; \n",N);

  for(i=0;i<N;i++)
    for(j=0;j<N;j++) 
    {
      A[i][j] = sin(i)*cos(j);
      B[i][j] = sin(j)*cos(i);
    }

  clkbegin = rtclock();
// Baseline "reference" version of code to be optimized
//
  p3(N,A,B,C);
// End of base version code
  clkend = rtclock();
  t = clkend-clkbegin;
  if (C[N/2][N/2]*C[N/2][N/2] < -100.0) printf("%f\n",C[N/2][N/2]);
  printf("Reference Version: %.1f GFLOPS; Time = %.3f sec; \n", 1.0e-9*N*N*(N+1)/t,t);

// Optimized test version, initially just a copy of base vesion,
// to be modified by you for improved performance
// 
// Initialization; do not change
  for(i=0;i<N;i++)
   for(j=0;j<N;j++) 
    {
      AA[i][j] = sin(i)*cos(j);
      BB[i][j] = sin(j)*cos(i);
    }

  clkbegin = rtclock();

// Make changes to the code below to improve performance
//
  p3opt(N,AA,BB,CC);
// End of test-version code
  clkend = rtclock();
  t = clkend-clkbegin;
  if (CC[N/2][N/2]*CC[N/2][N/2] < -100.0) printf("%f\n",CC[N/2][N/2]);
  printf("Optimized Version: %.1f GFLOPS; Time = %.3f sec; ", 1.0e-9*N*N*(N+1)/t,t);
// Verify correctness
  compare();
}

void p3(int n, double a[][n], double b[][n], double c[][n]){
  int i,j,k;
  for (i=0;i<n;i++)
   for (j=0;j<n;j++)
    for (k=0;k<i+1;k++)
      c[i][j] += a[k][i]*b[k][j];
}


double rtclock()
{
  struct timezone Tzp;
  struct timeval Tp;
  int stat;
  stat = gettimeofday (&Tp, &Tzp);
  if (stat != 0) printf("Error return from gettimeofday: %d",stat);
  return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
}

void compare()
{
double maxdiff,this_diff;
int numdiffs;
int i,j;
  numdiffs = 0;
  maxdiff = 0;
  for (i=0;i<N;i++)
   for (j=0;j<N;j++)
    {
     this_diff = CC[i][j]-C[i][j];
     if (this_diff < 0) this_diff = -1.0*this_diff;
     if (this_diff>tolerance)
      { numdiffs++;
        if (this_diff > maxdiff) maxdiff=this_diff;
      }
    }
   if (numdiffs > 0)
      printf("Failed Correctness Test: %d Differences found over tolerance %e; Max Diff = %f\n",
               numdiffs,tolerance,maxdiff);
   else
      printf("Passed Correctness Test\n");
}

