#include <stdio.h>
#include <stdlib.h>
#include "libresistance.h"

int main(int argc, char *argv[]){
	int count = 3;
	float *array =  malloc(count * sizeof *array);
	array[0] = 100;
	array[1] = 50;
	array[2] = 50;
	printf("Serial   100,50,50: %f\n",calc_resistance(count,'S',array));
	printf("Parallel 100,50,50: %f\n",calc_resistance(count,'P',array));
	array[2] = 0;
	printf("Serial   100,50, 0: %f\n", calc_resistance(count, 'S', array));
	printf("Parallel 100,50, 0: %f\n", calc_resistance(count, 'P', array));
	free(array);
	array = NULL;
	printf("Serial, nullptr:    %f\n",calc_resistance(count,'S',array));
	printf("Serial, -1 count:   %f\n",calc_resistance(-1,'S',array));
}
