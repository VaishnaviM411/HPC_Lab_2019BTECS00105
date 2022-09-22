#include<iostream>
#include<omp.h>
using namespace std;

int main()
{
    long int N=1000001, sum=0, i;
    double itime, ftime, exec_time;
    itime = omp_get_wtime();
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