#include <stdio.h>
#include <math.h>

int sides = 3;
float len_inner = 0.8660254; // 0.5*sqrt(3);
float len_outer = 1.7320508; // 2*0.5*sqrt(3);
float perimeter_inner;
float perimeter_outer;

int main(){
	while (sides < 100){
		perimeter_outer = len_outer*sides;
		perimeter_inner = len_inner*sides;

		len_outer = len_outer / (1 + sqrt(1 + len_outer * len_outer));
		len_inner = sqrt(0.5-0.5*sqrt(1 - len_inner * len_inner));

		sides*= 2;
	}
	printf("pi bounds: %f <= pi <= %f\n", perimeter_inner, perimeter_outer);
}

