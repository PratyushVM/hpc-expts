void Merge_Sort_Par(int a[],int b[],int n, int nThreads)
{
  omp_set_num_threads(nThreads);
  // To be modified to create a parallel merge sort
#pragma omp parallel
  {
#pragma omp master
    Merge_Sort(a,b,0,n-1);
  }
}
