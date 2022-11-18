#include <stdio.h>

void initWith(float num, float *a, int N)
{
  for(int i = 0; i < N; ++i)
  {
    a[i] = num;
  }
}

void addVectorsInto(float *result, float *a, float *b, int N)
{
  for(int i = 0; i < N; i ++)
  {
    result[i] = a[i] + b[i];
  }
}

void checkElementsAre(float target, float *array, int N)
{
  for(int i = 0; i < N; i++)
  {
    if(array[i] != target)
    {
      printf("FAIL: array[%d] - %0.0f does not equal %0.0f\n", i, array[i], target);
      exit(1);
    }
  }
  printf("SUCCESS! All values added correctly.\n");
}

int main()
{
  const int N = 2<<20;

  float *a=(float*)malloc(N * sizeof(float));
  float *b=(float*)malloc(N * sizeof(float));
  float *c=(float*)malloc(N * sizeof(float));

  initWith(3, a, N);
  initWith(4, b, N);
  initWith(0, c, N);

  double time_spent = 0.0;
  clock_t begin = clock();

  addVectorsInto(c, a, b, N);

  clock_t end = clock();
 
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("The elapsed time is %f seconds", time_spent);
 
  checkElementsAre(7, c, N);
}
