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
 
  //filling the vectors
  for(long int i=0;i<size;i++)
  {
    v[i]=i%4;
  }

  omp_set_num_threads(4);

  #pragma omp parallel
  {
    #pragma omp for nowait
    for(long int i=0;i<size;i++)
    {
      v[i]+=2;
      cout<<"executing inside loop\n";
    }
    cout<<"Outside loop\n";
  }
  return 0; 
}