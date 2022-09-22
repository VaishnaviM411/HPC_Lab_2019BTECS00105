#include <iostream>
#include <omp.h>
using namespace std;

long int fib(long int n)
{
  long int i, j;
  if (n<2)
    return n;
  else
    {
       i=fib(n-1);
       j=fib(n-2);
       return i+j;
    }
}

int main()
{
  long int n,ans;
  cout<<"Enter n: ";
  cin>>n;

  double itime, ftime, exec_time;
  itime = omp_get_wtime();

  ans = fib(n);

  ftime = omp_get_wtime();
  exec_time = (ftime - itime);
  printf ("fib(%ld) = %ld\n", n,ans);
  printf("\nTime taken is %f\n", exec_time);
  return 0;
}