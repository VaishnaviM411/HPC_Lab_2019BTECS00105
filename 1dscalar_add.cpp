#include<iostream>
#include<omp.h>
#include<vector>
using namespace std;

int main()
{
  long int size,scalar;
  cout<<"Enter vector size: ";
  cin>>size;
  vector<int> v(size);
  cout<<"Enter scalar: ";
  cin>>scalar; 

  //filling the vectors
  for(long int i=0;i<size;i++)
  {
    v[i]=i%4;
  }

  omp_set_num_threads(4);
  double itime, ftime, exec_time;
  itime = omp_get_wtime();

  #pragma omp parallel for schedule(dynamic,size/4)
  //addition
  for(long int i=0;i<size;i++)
  {
    v[i]+=scalar;
  }

  ftime = omp_get_wtime();
  exec_time = (ftime - itime);
  printf("\nTime taken is %f\n", exec_time);

  return 0; 
}