# include <time.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

int main(int argc, char **argv) {
  int i,j;
  double sum;
  clock_t end, start;
  double arr[512][512];
  int n = 512;
  
  // THIS FILLS THE MATRIX WITH NUMBERS
  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      arr[i][j] = (double) rand()/RAND_MAX;
    }
  }

  sum = 0;

  start = clock();

  // ROW MAJOR WORK
  for (i = 0; i<n; i++){ // iterate over rows 
    for (j = 0; j<n; j++){ // iterate over columns 
      sum += arr[i][j];
    }
  }
  end = clock();

  printf("N = %d\n", n);

  printf("Row Major: sum = %lf and Clock Ticks are %ld\n",sum,end-start);

  start = clock();

  // COLUMN MAJOR WORK
  for (j = 0; j<n; j++){ // iterate over columns 
    for (i = 0; i<n; i++){ // iterate over rows 
      sum += arr[i][j];
    }
  }

  end = clock();

  printf("Column Major: sum = %lf and Clock Ticks are %ld\n",sum,end-start);



  return 0;
}

