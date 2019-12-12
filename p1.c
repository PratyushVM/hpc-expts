void p1opt(int n, double A[][n], double x[n], double y[n], double z[n])
// Initially identical to reference; make your changes to optimize this code
{ 

  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      {
	y[i] = y[i] + A[j][i]*x[j];
	z[i] = z[i] + A[i][j]*x[j];
      }
}
