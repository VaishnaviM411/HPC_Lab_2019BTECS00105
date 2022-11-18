#include <stdio.h>

void initWith(float num, float *a, int SIZE)
{
  for(int i = 0; i < SIZE; ++i)
  {
    a[i] = num;
  }
}

void matrixMultiply(float *result, float *a, float *b, int N, int SIZE)
{

  for(int i = 0; i < SIZE; i ++)
  {
    int row = i / N;

    float sum = 0;

    for (int j = 0; j < N; j++)
    {
      sum += a[row * N + j] * b[N * j + row];
    }

    result[i] = sum;
  }
}

void checkElementsAre(float target, float *array, int SIZE)
{
  for(int i = 0; i < SIZE; i++)
  {
    if(array[i] != target)
    {
      printf("FAIL: array[%d] - %0.0f does not equal %0.0f\n", i, array[i], target);
      exit(1);
    }
  }
  printf("SUCCESS! All values multiplied correctly.\n");
}

int main()
{
  const int N = 1024;
  const int SIZE = N * N; // sqaure matrix
  //size_t size = SIZE * sizeof(float);

  float *a=(float*)malloc(N*N * sizeof(float));
  float *b=(float*)malloc(N*N * sizeof(float));
  float *c=(float*)malloc(N*N * sizeof(float));

  initWith(3, a, SIZE);
  initWith(4, b, SIZE);
  initWith(0, c, SIZE);

  double time_spent = 0.0;
  clock_t begin = clock();
  matrixMultiply(c, a, b, N, SIZE);

  clock_t end = clock();
 
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("The elapsed time is %f seconds", time_spent);
 

  checkElementsAre(12288, c, SIZE);

}
