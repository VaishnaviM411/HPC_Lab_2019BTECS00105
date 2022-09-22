#include<iostream>
#include<omp.h>
#include<vector>
using namespace std;

int main()
{
  long int N = 10000000, i;
  vector<int> v1(N);
  vector<int> v2(N);
  vector<int> res(N);
  //filling the vectors
  for(i=0;i<N;i++)
  {
    v1[i]=i+1;
    v2[i]=i+1;
  }

  omp_set_num_threads(4);
  double itime, ftime, exec_time;
  itime = omp_get_wtime();

  #pragma omp parallel for
  //addition
  for(i=0;i<N;i++)
  {
    res[i]=v1[i]+v2[i];
  }

  ftime = omp_get_wtime();
  exec_time = (ftime - itime);
  printf("\nTime taken is %f\n", exec_time);

  return 0; 
}