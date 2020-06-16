//Calculate Mean of Random numners passed in an array
#include <stdio.h>
#include <stdlib.h>

float calc_mean(int* random_array, int array_size) {
	int n, array_total = 0;
	float mean;

	for (n = 0; n < array_size; n++) {
		random_array[n] = (int)(10.0 * rand() / (RAND_MAX + 1.0));
		array_total += random_array[n];
	}
	mean = (float) array_total / array_size;

	return mean;
}