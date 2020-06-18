//Exercise 3:
//“Odd - Even Test” – As exercise(2), however this time divide the numbers into oddand even groups.
//The final output should show 50 % in each group.

#include <stdio.h>
#include <stdlib.h>

void calc_odd_even_freq(int* odd_count, int* even_count, float* odd_perc, float* even_perc, int* random_array, int array_size) {
	int n = 0;
	float odd, even = 0.0;
	
	//get the random numbers and check if these are odd or even
	for (n = 0; n < array_size; n++) {
		random_array[n] = (int)(10.0 * rand() / (RAND_MAX + 1.0));
		if ((random_array[n] % 2)) { //is it odd?
			*odd_count += 1;
		}
		else {
			*even_count += 1;
		}
	}
	odd = (float) *odd_count; //convert to float for calculation of %
	even = (float) *even_count; //convert to float for calculation of %

	*odd_perc = (odd / (odd + even)) * 100;
	*even_perc = (even / (odd + even)) * 100;
}