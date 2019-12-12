#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#define N 10000
#define threshold 0.00000001

double A[N][N], x[N],y[N],z[N],yy[N],zz[N];
int main(){
  double rtclock();
  void p1opt(int n, double m[][n], double x[n], double y[n], double z[n]);
  void baseversion(int n, double m[][n], double x[n], double y[n], double z[n]);
  int compare(int n, double wref[n], double w[n]);
  
  double clkbegin, clkend;
  double t;

  int i,j,it;

  printf("MV+MTV: Matrix Size = %d\n", N);

// Initialization; 
  for(i=0;i<N;i++)
   { 
     x[i] = i; y[i]= 0; z[i] = 1.0;
     for(j=0;j<N;j++) A[i][j] = (i+2*j)/(2*N);
   }

  clkbegin = rtclock();
// Baseline "reference" version of code to be optimized
//
  baseversion(N,A,x,y,z);
// End of base version code
//
  clkend = rtclock();
  t = clkend-clkbegin;
  if (y[N/2]*y[N/2] < -100.0) printf("%f\n",y[N/2]);
  printf("Reference Version: %.2f GFLOPS; Time = %.3f sec; \n",
          4.0*1e-9*N*N/t,t);

// Optimized test version, initially just a copy of base vesion,
// to be modified by you for improved performance
//
// Initialization; do not change
  for(i=0;i<N;i++) { yy[i]= 0; zz[i] = 1.0; }

// Make changes to the function p1opt  to improve performance
// It initially contains the same code as the reference version
//
  clkbegin =  rtclock();
  p1opt(N,A,x,yy,zz);
  clkend = rtclock();
  t = clkend-clkbegin;
  if (yy[N/2]*yy[N/2] < -100.0) printf("%f\n",yy[N/2]);
  printf("Optimized Version: %.2f GFLOPS; Time = %.3f sec; ",
          4.0*1e-9*N*N/t,t);
// Verify correctness
  if ((compare(N,y,yy) + compare(N,z,zz))==0)
     printf("Passed corectness check\n");
}

void baseversion(int n, double A[][n], double x[n], double y[n], double z[n]){
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      {
	y[i] = y[i] + A[j][i]*x[j];
	z[i] = z[i] + A[i][j]*x[j];
      }
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

int compare(int n, double wref[n], double w[n])
{
  double maxdiff,this_diff;
  int numdiffs;
  int i;
  numdiffs = 0;
  maxdiff = 0;
  for (i=0;i<n;i++)
    {
      this_diff = wref[i]-w[i];
      if (this_diff < 0) this_diff = -1.0*this_diff;
      if (this_diff>threshold)
	{ numdiffs++;
	 if (this_diff > maxdiff) maxdiff=this_diff;
	}
    }
  if (numdiffs>0) printf("Differences found; Max-diff = %f\n",maxdiff);
   return (numdiffs);
}
