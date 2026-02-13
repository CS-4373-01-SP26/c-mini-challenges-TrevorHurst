// 3. Implement matrix – vector multiplication. Read in the following text file (mv.txt) which contains the matrix and vector to be multiplied. Print your answer to the screen and time the computation. The format of mv.txt is: line 1 contains numrows, numcols. The next numrows contains the rows of the matrix, each with numcols integer values. The next line contains the length of the vector. The next line contains the vector of that length.

#include <stdio.h>
#include <string.h>
#include <math.h>


int main(){
	
	FILE *fptr;
	int numrows, numcols;
	fptr = fopen("mv.txt", "r");

	fscanf(fptr, "%d %d", &numrows, &numcols);

	int matrix[numrows][numcols];
	for (int i = 0; i < numrows; i++){
		for(int j = 0; j < numcols; j++){
			fscanf(fptr, "%d", &matrix[i][j]);
		}
	}

	int vectorlen;
	fscanf(fptr, "%d", &vectorlen);
	int vector[vectorlen];

	for (int i = 0; i < vectorlen; i++){
		fscanf(fptr, "%d", &vector[i]);
	}

	int result[numrows];
	memset(result, 0, sizeof(result));

	for (int i = 0; i < numrows; i++){
		for (int j = 0; j < numcols; j++){
			result[i]+=vector[j]*matrix[i][j];
		}
	}

	for (int i = 0; i < numrows; i++){
		printf("%d ", result[i]);
	}
	fclose(fptr);

	return 0;

}

