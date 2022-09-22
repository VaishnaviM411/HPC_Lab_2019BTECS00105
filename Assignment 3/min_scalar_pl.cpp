// C Program to find the minimum scalar product of two vectors (dot product)
#include<iostream>
#include<algorithm>
#include<vector>
#include<omp.h>
using namespace std;

int main()
{
  int n;
  int sum=0;
  cin>>n;
  vector<int> arr1(n);
  vector<int> arr2(n);
  int i;
  //filling the vectors
  for(i = 0; i < n ; i++)
  {
    arr1[i]=(i+1)%2;
    arr2[i]=(i+1)%2;
  }
  sort(arr1.begin(),arr1.end());
  sort(arr1.begin(),arr1.end(), greater<int>());

  omp_set_num_threads(4);

  double itime, ftime, exec_time;
  itime = omp_get_wtime();

  #pragma omp parallel for reduction(+:sum)
  for(i = 0; i < n ; i++)
  {
    sum = sum + (arr1[i] * arr2[i]);
  }

  ftime = omp_get_wtime();
  exec_time = ftime - itime;
  cout<<"Sum= "<<sum<<endl;
  printf("Time taken = %f\n",exec_time);
  return 0;
}
