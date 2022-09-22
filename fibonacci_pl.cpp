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
       #pragma omp task shared(i) firstprivate(n)
       i=fib(n-1);

       #pragma omp task shared(j) firstprivate(n)
       j=fib(n-2);

       #pragma omp taskwait
       return i+j;
    }
}

int main()
{
  long int n,ans;
  cout<<"Enter n: ";
  cin>>n;

  omp_set_num_threads(2);
  double itime, ftime, exec_time;
  itime = omp_get_wtime();

  #pragma omp parallel shared(n)
  {
    #pragma omp single
    ans = fib(n);
  }

  ftime = omp_get_wtime();
  exec_time = (ftime - itime);
  printf ("fib(%ld) = %ld\n", n,ans);
  printf("\nTime taken is %f\n", exec_time);
  return 0;
}