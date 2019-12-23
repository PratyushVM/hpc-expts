void p2opt(int n, double a[][n], double b[][n])
// make your changes to optimize this code 
{
  int i,j;
  
  for(i=0;i<n;i+=8)
  {
  	for(j=0;j<n;j+=8)
  	{
		  
		b[i][j] = 0.5*(a[i][j] + a[j][i]);
		b[i][j+1] = 0.5*(a[i][j+1] + a[j+1][i]);
		b[i][j+2] = 0.5*(a[i][j+2] + a[j+2][i]);
		b[i][j+3] = 0.5*(a[i][j+3] + a[j+3][i]);
		b[i][j+4] = 0.5*(a[i][j+4] + a[j+4][i]);
		b[i][j+5] = 0.5*(a[i][j+5] + a[j+5][i]);
		b[i][j+6] = 0.5*(a[i][j+6] + a[j+6][i]);
		b[i][j+7] = 0.5*(a[i][j+7] + a[j+7][i]);
		
		b[i+1][j] = 0.5*(a[i+1][j] + a[j][i+1]);
		b[i+1][j+1] = 0.5*(a[i+1][j+1] + a[j+1][i+1]);
		b[i+1][j+2] = 0.5*(a[i+1][j+2] + a[j+2][i+1]);
		b[i+1][j+3] = 0.5*(a[i+1][j+3] + a[j+3][i+1]);
		b[i+1][j+4] = 0.5*(a[i+1][j+4] + a[j+4][i+1]);
		b[i+1][j+5] = 0.5*(a[i+1][j+5] + a[j+5][i+1]);
		b[i+1][j+6] = 0.5*(a[i+1][j+6] + a[j+6][i+1]);
		b[i+1][j+7] = 0.5*(a[i+1][j+7] + a[j+7][i+1]);
		
		b[i+2][j] = 0.5*(a[i+2][j] + a[j][i+2]);
		b[i+2][j+1] = 0.5*(a[i+2][j+1] + a[j+1][i+2]);
		b[i+2][j+2] = 0.5*(a[i+2][j+2] + a[j+2][i+2]);
		b[i+2][j+3] = 0.5*(a[i+2][j+3] + a[j+3][i+2]);
		b[i+2][j+4] = 0.5*(a[i+2][j+4] + a[j+4][i+2]);
		b[i+2][j+5] = 0.5*(a[i+2][j+5] + a[j+5][i+2]);
		b[i+2][j+6] = 0.5*(a[i+2][j+6] + a[j+6][i+2]);
		b[i+2][j+7] = 0.5*(a[i+2][j+7] + a[j+7][i+2]);
		
		b[i+3][j] = 0.5*(a[i+3][j] + a[j][i+3]);
		b[i+3][j+1] = 0.5*(a[i+3][j+1] + a[j+1][i+3]);
		b[i+3][j+2] = 0.5*(a[i+3][j+2] + a[j+2][i+3]);
		b[i+3][j+3] = 0.5*(a[i+3][j+3] + a[j+3][i+3]);
		b[i+3][j+4] = 0.5*(a[i+3][j+4] + a[j+4][i+3]);
		b[i+3][j+5] = 0.5*(a[i+3][j+5] + a[j+5][i+3]);
		b[i+3][j+6] = 0.5*(a[i+3][j+6] + a[j+6][i+3]);
		b[i+3][j+7] = 0.5*(a[i+3][j+7] + a[j+7][i+3]);
		
		b[i+4][j] = 0.5*(a[i+4][j] + a[j][i+4]);
		b[i+4][j+1] = 0.5*(a[i+4][j+1] + a[j+1][i+4]);
		b[i+4][j+2] = 0.5*(a[i+4][j+2] + a[j+2][i+4]);
		b[i+4][j+3] = 0.5*(a[i+4][j+3] + a[j+3][i+4]);
		b[i+4][j+4] = 0.5*(a[i+4][j+4] + a[j+4][i+4]);
		b[i+4][j+5] = 0.5*(a[i+4][j+5] + a[j+5][i+4]);
		b[i+4][j+6] = 0.5*(a[i+4][j+6] + a[j+6][i+4]);
		b[i+4][j+7] = 0.5*(a[i+4][j+7] + a[j+7][i+4]);
		
		b[i+5][j] = 0.5*(a[i+5][j] + a[j][i+5]);
		b[i+5][j+1] = 0.5*(a[i+5][j+1] + a[j+1][i+5]);
		b[i+5][j+2] = 0.5*(a[i+5][j+2] + a[j+2][i+5]);
		b[i+5][j+3] = 0.5*(a[i+5][j+3] + a[j+3][i+5]);
		b[i+5][j+4] = 0.5*(a[i+5][j+4] + a[j+4][i+5]);
		b[i+5][j+5] = 0.5*(a[i+5][j+5] + a[j+5][i+5]);
		b[i+5][j+6] = 0.5*(a[i+5][j+6] + a[j+6][i+5]);
		b[i+5][j+7] = 0.5*(a[i+5][j+7] + a[j+7][i+5]);
		
		b[i+6][j] = 0.5*(a[i+6][j] + a[j][i+6]);
		b[i+6][j+1] = 0.5*(a[i+6][j+1] + a[j+1][i+6]);
		b[i+6][j+2] = 0.5*(a[i+6][j+2] + a[j+2][i+6]);
		b[i+6][j+3] = 0.5*(a[i+6][j+3] + a[j+3][i+6]);
		b[i+6][j+4] = 0.5*(a[i+6][j+4] + a[j+4][i+6]);
		b[i+6][j+5] = 0.5*(a[i+6][j+5] + a[j+5][i+6]);
		b[i+6][j+6] = 0.5*(a[i+6][j+6] + a[j+6][i+6]);
		b[i+6][j+7] = 0.5*(a[i+6][j+7] + a[j+7][i+6]);
		
		b[i+7][j] = 0.5*(a[i+7][j] + a[j][i+7]);
		b[i+7][j+1] = 0.5*(a[i+7][j+1] + a[j+1][i+7]);
		b[i+7][j+2] = 0.5*(a[i+7][j+2] + a[j+2][i+7]);
		b[i+7][j+3] = 0.5*(a[i+7][j+3] + a[j+3][i+7]);
		b[i+7][j+4] = 0.5*(a[i+7][j+4] + a[j+4][i+7]);
		b[i+7][j+5] = 0.5*(a[i+7][j+5] + a[j+5][i+7]);
		b[i+7][j+6] = 0.5*(a[i+7][j+6] + a[j+6][i+7]);
		b[i+7][j+7] = 0.5*(a[i+7][j+7] + a[j+7][i+7]);


  	}
    
  }
	

}
