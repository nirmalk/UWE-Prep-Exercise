/*
Calculate Mean of Random numners passed in an array
Exercise 1

Mean Test” – Write a C program that can generate 1000 random numbers and calculate the mean.The final output should give a result close to 4.5.
For these exercises, you should use the following code to generate random numbers between 0 and 9:
*/

#include <stdio.h>
#include <stdlib.h>

float calc_mean(int* random_array, int array_size) {
	int n, array_total = 0;
	float mean;

	//Add all random numbers in the array
	for (n = 0; n < array_size; n++) {
		random_array[n] = (int)(10.0 * rand() / (RAND_MAX + 1.0));
		array_total += random_array[n];
	}
	mean = (float) array_total / array_size; //calculate mean

	return mean;
}