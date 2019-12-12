void p2opt(int n, double a[][n], double b[][n])
// make your changes to optimize this code 
{
  int i,j;
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
    b[i][j] = 0.5*(a[i][j] + a[j][i]);
}
