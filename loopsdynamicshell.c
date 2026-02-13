# include <time.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

int main(int argc, char **argv) {
  int i,j;
  int n = 16384;
  double sum;
  clock_t end, start;
  double *arr = malloc(n*n*sizeof(double));
  
// THIS FILLS THE MATRIX WITH NUMBERS
  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      arr[i*n+j] = (double) rand()/RAND_MAX;
    }
  }

  sum = 0;

  // ROW MAJOR WORK

  start = clock();
  for (i = 0; i<n; i++){ // iterate over rows 
    for (j = 0; j<n; j++){ // iterate over columns 
      sum += arr[i*n + j];
    }
  }

  end = clock();
  printf("N = %d", n);

  printf("Row Major: sum = %lf and Clock Ticks are %ld\n",sum,end-start);

  // COLUMN MAJOR WORK
  start = clock();
  for (j = 0; j<n; j++){ // iterate over columns 
    for (i = 0; i<n; i++){ // iterate over rows 
      sum += arr[i*n + j];
    }
  }
  end = clock();

  printf("Column Major: sum = %lf and Clock Ticks are %ld\n",sum,end-start);

  return 0;
}

