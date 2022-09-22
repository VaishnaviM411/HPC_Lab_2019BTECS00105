#include<iostream>
#include<omp.h>
#include<vector>
using namespace std;

int main()
{
  int threads,size;
  cout<<"Enter no of threads: ";
  cin>>threads;
  cout<<"Enter matrix size: ";
  cin>>size;
  //making matrices

  
  vector<vector<int>> mat1(size,vector<int>(size));
  for(int i=0;i<size;i++)
  {
    for(int j=0;j<size;j++)
      mat1[i][j]=i%5;
  }

  vector<vector<int>> mat2(size,vector<int>(size));
  for(int i=0;i<size;i++)
  {
    for(int j=0;j<size;j++)
      mat2[i][j]=i%5;
  }

  omp_set_num_threads(threads);
  double itime, ftime, exec_time;
  itime = omp_get_wtime();

  vector<vector<int>> mat3(size,vector<int>(size));
  #pragma omp parallel for collapse(2)
  for(int i=0;i<size;i++)
  {
    for(int j=0;j<size;j++)
      mat3[i][j]=mat1[i][j]+mat2[i][j];
  }

  ftime = omp_get_wtime();
  exec_time = (ftime - itime);
  printf("\nTime taken is %f\n", exec_time);
  return 0;
}