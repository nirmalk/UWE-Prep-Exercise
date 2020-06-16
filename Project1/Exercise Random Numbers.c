/*
Exercise 1:
“Mean Test” – Write a C program that can generate 1000 random numbers and calculate the mean.
The final output should give a result close to 4.5.

Exercise 2:
“Frequency Test” – Write a C program that can generate 10,000 random numbers.
Use an array to count the occurrence of each digit (0 through to 9).
The final output should show that the occurrence of each digit is close to 10%.

Exercise 3:
“Odd-Even Test” – As exercise (2), however this time divide the numbers into odd and even groups.
The final output should show 50% in each group.

Exercise 4:
“Serial Test” - Write a C program that can generate 10,000 pairs of random numbers (e.g., 02, 14).
Use an array to count the occurrence of pairs of digits (00 through to 99).
The final output should show that the occurrence of each pair is close to 1%.

Exercise 5:
“Gap Test” – Prompt a user to enter a digit between 0 and 9.
Generate a sequence of 10,000 random numbers and calculate the gap between successive occurrences of the chosen digit.
Use an array to classify into 7 groups where the gap is either 0,1,2,3,4,5 or greater than 5. The distribution should approximately be 10.00%, 9.00%, 8.10%, 7.29%, 6.56%, 5.90%, and 53.14% respectively (to 2 d.p.).

Exercise 1

Mean Test” – Write a C program that can generate 1000 random numbers and calculate the mean. The final output should give a result close to 4.5.
For these exercises, you should use the following code to generate random numbers between 0 and 9:

int random_number = (int) (10.0*rand()/(RAND_MAX + 1.0));
*/

# include <stdio.h>
# include <stdlib.h>

#define ARRAY_SIZE 10000 //define the array size...helps in testing with variable array sizes

float calc_mean(int*, int);
void calc_frequency(int*, int*, int);

int random_freq[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int random_array[ARRAY_SIZE]; //define an array of ARRAY_SIZE integers
float array_mean = 0.0000;
//int array_total = 0;

main() {
	int n = 0;
	//get the 1000 random numbers into the array & calculate their sum
	array_mean = calc_mean(random_array, ARRAY_SIZE);
	calc_frequency(random_array, random_freq, ARRAY_SIZE);

	/*
	for (n = 0; n < ARRAY_SIZE; n++) {
		random_array[n] = (int)(10.0 * rand() / (RAND_MAX + 1.0));
		array_total += random_array[n];
		calc_frequency(random_array[n], random_freq);
	}
	*/

	//calculate mean and print
	printf("Mean of %d Random Numbers %.4f\n", ARRAY_SIZE, array_mean);
	for (n = 0; n < 10; n++) {
		printf("Frequency of Random Number %d = %d\n", n, random_freq[n]);
	}
} 