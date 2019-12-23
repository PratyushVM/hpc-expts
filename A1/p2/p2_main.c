#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#define N 8192
#define threshold 0.0000001

double A[N][N], B[N][N], BB[N][N];
int main(){
double rtclock();
void p2(int n, double a[][n], double b[][n]);
void p2opt(int n, double a[][n], double b[][n]);
void compare(int n, double wref[][n], double w[][n]);

double clkbegin, clkend;
double t;
double rtclock();

int i,j,it;

  printf("Symmetrizer: Matrix Size = %d \n", N);

// Initialization
  
  for(i=0;i<N;i++)
   for(j=0;j<N;j++) A[i][j] = (i+2.0*j)/(2.0*N);

  clkbegin = rtclock();
// Baseline "reference" version of code to be optimized
//

  p2(N,A,B);
// End of base version code
//
  clkend = rtclock();
  t = clkend-clkbegin;
  if (B[N/2][N/2]*B[N/2][N/2] < -100.0) printf("%f\n",B[N/2][N/2]);
  printf("Reference Version: %.2f GFLOPS; Time = %.3f sec; \n",
          2.0*1e-9*N*N/t,t);

  clkbegin = rtclock();

// Optimized test version, initially just a copy of base vesion,
// to be modified by you for improved performance
//
//
  p2opt(N,A,BB);
// End of test-version code

  clkend = rtclock();
  t = clkend-clkbegin;
  if (BB[N/2][N/2]*BB[N/2][N/2] < -100.0) printf("%f\n",BB[N/2][N/2]);
  printf("Optimized Version: %.2f GFLOPS; Time = %.3f sec; ",
          2.0*1e-9*N*N/t,t);
  compare(N,B,BB);
}

void p2(int n, double a[][n], double b[][n]){
  int i,j;
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
    b[i][j] = 0.5*(a[i][j] + a[j][i]);

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

void compare(int n, double wref[][n], double w[][n])
{
double maxdiff,this_diff;
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
