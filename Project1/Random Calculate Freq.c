/*
Exercise 2

“Frequency Test” – Write a C program that can generate 10,000 random numbers.
Use an array to count the occurrence of each digit (0 through to 9).
The final output should show that the occurrence of each digit is close to 10%.

int random_number = (int) (10.0*rand()/(RAND_MAX + 1.0));
*/

#include <stdio.h>
#include <stdlib.h>

void calc_frequency(int *random_array, int *random_freq, int array_size) {
	int n;

	// get the array of random numbers and check each for its value between 0 and 9
	for (n = 0; n < array_size; n++) {
		random_array[n] = (int)(10.0 * rand() / (RAND_MAX + 1.0));

		if (random_array[n] == 0) {
			random_freq[0] += 1;
		}
		else if (random_array[n] == 1) {
			random_freq[1] += 1;
		}
		else if (random_array[n] == 2) {
			random_freq[2] += 1;
		}
		else if (random_array[n] == 3) {
			random_freq[3] += 1;
		}
		else if (random_array[n] == 4) {
			random_freq[4] += 1;
		}
		else if (random_array[n] == 5) {
			random_freq[5] += 1;
		}
		else if (random_array[n] == 6) {
			random_freq[6] += 1;
		}
		else if (random_array[n] == 7) {
			random_freq[7] += 1;
		}
		else if (random_array[n] == 8) {
			random_freq[8] += 1;
		}
		else {
			random_freq[9] += 1;
		}
	}
}

