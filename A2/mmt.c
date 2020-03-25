#define size 4096
void parallel_mmt(int n,float c[][n],float a[][n], float b[][n],int nThreads){
  int i,j,k;
  omp_set_num_threads(nThreads);
  #pragma omp parallel private(i,j,k) shared(a,b,c)
  {
      #pragma omp for collapse(2)
      for(j=0;j<n;j++)
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                c[j][i] = c[j][i] + a[k][i]*b[k][j];
  }
}
