void p3opt(int n, double a[][n], double b[][n], double c[][n])
//make your changes to optimize this code 
{
  int i,j,k;
  for (i=0;i<n;i++)
   for (j=0;j<n;j++)
    for (k=0;k<i+1;k++)
      c[i][j] += a[k][i]*b[k][j];
}
