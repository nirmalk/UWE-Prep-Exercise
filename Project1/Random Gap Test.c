/*
Exercise 5:
“Gap Test” – Prompt a user to enter a digit between 0 and 9.
Generate a sequence of 10,000 random numbers and calculate the gap between successive occurrences of the chosen digit.
Use an array to classify into 7 groups where the gap is either 0,1,2,3,4,5 or greater than 5. The distribution should approximately be 10.00%, 9.00%, 8.10%, 7.29%, 6.56%, 5.90%, and 53.14% respectively (to 2 d.p.).
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void calc_gap_test(int *random_array, int array_size, int *random_gap_array) {
	char input_char = '\0';
	int digit;
	int index;
	int n, gap = 0;

	//get the random numbers in the array
	for (n = 0; n < array_size; n++) {
		random_array[n] = (int)(10.0 * rand() / (RAND_MAX + 1.0));
	}

	//get the digit from user
	do {
		printf("Enter a number between 0 and 9: ");
		scanf_s("%c", &input_char, 1);
	} while (!isdigit(input_char));

	digit = (int)(input_char - '0');

	//check through the array to calculate gaps
	gap = 0;

	for (index = 0; index < array_size; index++) {
		if (random_array[index] == digit) {
			if (gap > 5) {
				random_gap_array[6] += 1;
			}
			else {
				random_gap_array[gap] += 1;
			}
			gap = 0;
		}
		else {
			gap++;
		}
	}
}
