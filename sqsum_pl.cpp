#include<iostream>
#include<omp.h>
using namespace std;

int main()
{
    long int N=1000001, sum=0, i;
    double itime, ftime, exec_time;
    omp_set_num_threads(4);
    itime = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum)
      for(i=1;i<N;i++)
      {
          sum+=i*i;
      }
    ftime = omp_get_wtime();
    exec_time = (ftime - itime);
    cout<<"Sum= "<<sum<<endl;
    printf("\nTime taken is %f\n", exec_time);
    return 0;
}