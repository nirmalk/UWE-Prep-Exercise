/*
Exercise 4:calculate the frequency of consecutive two random digits
“Serial Test” - Write a C program that can generate 10,000 pairs of random numbers (e.g., 02, 14).
Use an array to count the occurrence of pairs of digits (00 through to 99).
The final output should show that the occurrence of each pair is close to 1%.
*/

#include <stdio.h>
#include <stdlib.h>

int row, col = 0;
int *array_ptr;
int index, tens, units;

void calc_freq_double(int* random_array_double, int* random_freq_double, int array_size) {

	array_ptr = random_array_double; //point the pointer to the start of the array

	for (row = 0; row < array_size; row++) {
		*(array_ptr) = (int)(10.0 * rand() / (RAND_MAX + 1.0)); //get the first random digit
		tens = *array_ptr;
		*(++array_ptr) = (int)(10.0 * rand() / (RAND_MAX + 1.0)); //get the second random digit
		units = *array_ptr;

		index = 10 * tens + units; //index will not be reduced by 1 since the number pairs cannot be > 99
		random_freq_double[index] += 1; //count the occurence of a particular pair
	}
}