void p1opt(int n, double A[][n], double x[n], double y[n], double z[n])
// Initially identical to reference; make your changes to optimize this code
{ 

  int i,j;
  for(i=0;i<n;i+=8)
    for(j=0;j<n;j+=8)
      {

        y[j] = y[j] + A[i][j]*x[i];
        y[j+1] = y[j+1] + A[i][j+1]*x[i];
        y[j+2] = y[j+2] + A[i][j+2]*x[i];
        y[j+3] = y[j+3] + A[i][j+3]*x[i];
        y[j+4] = y[j+4] + A[i][j+4]*x[i];
        y[j+5] = y[j+5] + A[i][j+5]*x[i];
        y[j+6] = y[j+6] + A[i][j+6]*x[i];
        y[j+7] = y[j+7] + A[i][j+7]*x[i];

        y[j] = y[j] + A[i+1][j]*x[i+1];
        y[j+1] = y[j+1] + A[i+1][j+1]*x[i+1];
        y[j+2] = y[j+2] + A[i+1][j+2]*x[i+1];
        y[j+3] = y[j+3] + A[i+1][j+3]*x[i+1];
        y[j+4] = y[j+4] + A[i+1][j+4]*x[i+1];
        y[j+5] = y[j+5] + A[i+1][j+5]*x[i+1];
        y[j+6] = y[j+6] + A[i+1][j+6]*x[i+1];
        y[j+7] = y[j+7] + A[i+1][j+7]*x[i+1];

        y[j] = y[j] + A[i+2][j]*x[i+2];
        y[j+1] = y[j+1] + A[i+2][j+1]*x[i+2];
        y[j+2] = y[j+2] + A[i+2][j+2]*x[i+2];
        y[j+3] = y[j+3] + A[i+2][j+3]*x[i+2];
        y[j+4] = y[j+4] + A[i+2][j+4]*x[i+2];
        y[j+5] = y[j+5] + A[i+2][j+5]*x[i+2];
        y[j+6] = y[j+6] + A[i+2][j+6]*x[i+2];
        y[j+7] = y[j+7] + A[i+2][j+7]*x[i+2];

        y[j] = y[j] + A[i+3][j]*x[i+3];
        y[j+1] = y[j+1] + A[i+3][j+1]*x[i+3];
        y[j+2] = y[j+2] + A[i+3][j+2]*x[i+3];
        y[j+3] = y[j+3] + A[i+3][j+3]*x[i+3];
        y[j+4] = y[j+4] + A[i+3][j+4]*x[i+3];
        y[j+5] = y[j+5] + A[i+3][j+5]*x[i+3];
        y[j+6] = y[j+6] + A[i+3][j+6]*x[i+3];
        y[j+7] = y[j+7] + A[i+3][j+7]*x[i+3];

        y[j] = y[j] + A[i+4][j]*x[i+4];
        y[j+1] = y[j+1] + A[i+4][j+1]*x[i+4];
        y[j+2] = y[j+2] + A[i+4][j+2]*x[i+4];
        y[j+3] = y[j+3] + A[i+4][j+3]*x[i+4];
        y[j+4] = y[j+4] + A[i+4][j+4]*x[i+4];
        y[j+5] = y[j+5] + A[i+4][j+5]*x[i+4];
        y[j+6] = y[j+6] + A[i+4][j+6]*x[i+4];
        y[j+7] = y[j+7] + A[i+4][j+7]*x[i+4];

        y[j] = y[j] + A[i+5][j]*x[i+5];
        y[j+1] = y[j+1] + A[i+5][j+1]*x[i+5];
        y[j+2] = y[j+2] + A[i+5][j+2]*x[i+5];
        y[j+3] = y[j+3] + A[i+5][j+3]*x[i+5];
        y[j+4] = y[j+4] + A[i+5][j+4]*x[i+5];
        y[j+5] = y[j+5] + A[i+5][j+5]*x[i+5];
        y[j+6] = y[j+6] + A[i+5][j+6]*x[i+5];
        y[j+7] = y[j+7] + A[i+5][j+7]*x[i+5];

        y[j] = y[j] + A[i+6][j]*x[i+6];
        y[j+1] = y[j+1] + A[i+6][j+1]*x[i+6];
        y[j+2] = y[j+2] + A[i+6][j+2]*x[i+6];
        y[j+3] = y[j+3] + A[i+6][j+3]*x[i+6];
        y[j+4] = y[j+4] + A[i+6][j+4]*x[i+6];
        y[j+5] = y[j+5] + A[i+6][j+5]*x[i+6];
        y[j+6] = y[j+6] + A[i+6][j+6]*x[i+6];
        y[j+7] = y[j+7] + A[i+6][j+7]*x[i+6];

        y[j] = y[j] + A[i+7][j]*x[i+7];
        y[j+1] = y[j+1] + A[i+7][j+1]*x[i+7];
        y[j+2] = y[j+2] + A[i+7][j+2]*x[i+7];
        y[j+3] = y[j+3] + A[i+7][j+3]*x[i+7];
        y[j+4] = y[j+4] + A[i+7][j+4]*x[i+7];
        y[j+5] = y[j+5] + A[i+7][j+5]*x[i+7];
        y[j+6] = y[j+6] + A[i+7][j+6]*x[i+7];
        y[j+7] = y[j+7] + A[i+7][j+7]*x[i+7];

      }

   for(i=0;i<n;i+=8)
   {
       for(j=0;j<n;j+=8)
       {
         
        z[i] = z[i] + A[i][j]*x[j];
        z[i] = z[i] + A[i][j+1]*x[j+1];
        z[i] = z[i] + A[i][j+2]*x[j+2];
        z[i] = z[i] + A[i][j+3]*x[j+3];
        z[i] = z[i] + A[i][j+4]*x[j+4];
        z[i] = z[i] + A[i][j+5]*x[j+5];
        z[i] = z[i] + A[i][j+6]*x[j+6];
        z[i] = z[i] + A[i][j+7]*x[j+7];

        z[i+1] = z[i+1] + A[i+1][j]*x[j];
        z[i+1] = z[i+1] + A[i+1][j+1]*x[j+1];
        z[i+1] = z[i+1] + A[i+1][j+2]*x[j+2];
        z[i+1] = z[i+1] + A[i+1][j+3]*x[j+3];
        z[i+1] = z[i+1] + A[i+1][j+4]*x[j+4];
        z[i+1] = z[i+1] + A[i+1][j+5]*x[j+5];
        z[i+1] = z[i+1] + A[i+1][j+6]*x[j+6];
        z[i+1] = z[i+1] + A[i+1][j+7]*x[j+7];
        
        z[i+2] = z[i+2] + A[i+2][j]*x[j];
        z[i+2] = z[i+2] + A[i+2][j+1]*x[j+1];
        z[i+2] = z[i+2] + A[i+2][j+2]*x[j+2];
        z[i+2] = z[i+2] + A[i+2][j+3]*x[j+3];
        z[i+2] = z[i+2] + A[i+2][j+4]*x[j+4];
        z[i+2] = z[i+2] + A[i+2][j+5]*x[j+5];
        z[i+2] = z[i+2] + A[i+2][j+6]*x[j+6];
        z[i+2] = z[i+2] + A[i+2][j+7]*x[j+7];
        
        z[i+3] = z[i+3] + A[i+3][j]*x[j];
        z[i+3] = z[i+3] + A[i+3][j+1]*x[j+1];
        z[i+3] = z[i+3] + A[i+3][j+2]*x[j+2];
        z[i+3] = z[i+3] + A[i+3][j+3]*x[j+3];
        z[i+3] = z[i+3] + A[i+3][j+4]*x[j+4];
        z[i+3] = z[i+3] + A[i+3][j+5]*x[j+5];
        z[i+3] = z[i+3] + A[i+3][j+6]*x[j+6];
        z[i+3] = z[i+3] + A[i+3][j+7]*x[j+7];
        
        z[i+4] = z[i+4] + A[i+4][j]*x[j];
        z[i+4] = z[i+4] + A[i+4][j+1]*x[j+1];
        z[i+4] = z[i+4] + A[i+4][j+2]*x[j+2];
        z[i+4] = z[i+4] + A[i+4][j+3]*x[j+3];
        z[i+4] = z[i+4] + A[i+4][j+4]*x[j+4];
        z[i+4] = z[i+4] + A[i+4][j+5]*x[j+5];
        z[i+4] = z[i+4] + A[i+4][j+6]*x[j+6];
        z[i+4] = z[i+4] + A[i+4][j+7]*x[j+7];
        
        z[i+5] = z[i+5] + A[i+5][j]*x[j];
        z[i+5] = z[i+5] + A[i+5][j+1]*x[j+1];
        z[i+5] = z[i+5] + A[i+5][j+2]*x[j+2];
        z[i+5] = z[i+5] + A[i+5][j+3]*x[j+3];
        z[i+5] = z[i+5] + A[i+5][j+4]*x[j+4];
        z[i+5] = z[i+5] + A[i+5][j+5]*x[j+5];
        z[i+5] = z[i+5] + A[i+5][j+6]*x[j+6];
        z[i+5] = z[i+5] + A[i+5][j+7]*x[j+7];
        
        z[i+6] = z[i+6] + A[i+6][j]*x[j];
        z[i+6] = z[i+6] + A[i+6][j+1]*x[j+1];
        z[i+6] = z[i+6] + A[i+6][j+2]*x[j+2];
        z[i+6] = z[i+6] + A[i+6][j+3]*x[j+3];
        z[i+6] = z[i+6] + A[i+6][j+4]*x[j+4];
        z[i+6] = z[i+6] + A[i+6][j+5]*x[j+5];
        z[i+6] = z[i+6] + A[i+6][j+6]*x[j+6];
        z[i+6] = z[i+6] + A[i+6][j+7]*x[j+7];
        
        z[i+7] = z[i+7] + A[i+7][j]*x[j];
        z[i+7] = z[i+7] + A[i+7][j+1]*x[j+1];
        z[i+7] = z[i+7] + A[i+7][j+2]*x[j+2];
        z[i+7] = z[i+7] + A[i+7][j+3]*x[j+3];
        z[i+7] = z[i+7] + A[i+7][j+4]*x[j+4];
        z[i+7] = z[i+7] + A[i+7][j+5]*x[j+5];
        z[i+7] = z[i+7] + A[i+7][j+6]*x[j+6];
        z[i+7] = z[i+7] + A[i+7][j+7]*x[j+7];
       }
   } 
}
