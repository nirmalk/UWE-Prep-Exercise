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

int random_number = (int) (10.0*rand()/(RAND_MAX + 1.0));
*/

# include <stdio.h>
# include <stdlib.h>
# include<ctype.h>

#define ARRAY_SIZE 10000 //define the array size...helps in testing with variable array sizes

float calc_mean(int*, int);
void calc_frequency(int*, int*, int);
void calc_odd_even_freq(int*, int*, float*, float*, int*, int);
void calc_freq_double(int [ARRAY_SIZE][2], int*, int);
void calc_gap_test(int*, int, int*);

int random_freq[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int random_freq_double[100]; //array to count the occurence of pairs of random numbers
int random_array[ARRAY_SIZE]; //define an array of ARRAY_SIZE integers
int random_array_double[ARRAY_SIZE][2]; //define the array for holding double digits
int random_gap_array[7]; //for gaps of 0, 1, 2, 3, 4, 5 & >5

float array_mean = 0.0000;

main() {
	int row, n = 0;
	int odd_count = 0;
	int even_count = 0;
	float odd_perc = 0.0;
	float even_perc = 0.0;
	int input_digit = 0;
	float gap_total = 0;

	array_mean = calc_mean(random_array, ARRAY_SIZE); //calculate mean for random numbers of ARRAY_SIZE
	calc_frequency(random_array, random_freq, ARRAY_SIZE); //calculate frequency distribution of random numbers between 0 and 9
	calc_odd_even_freq(&odd_count, &even_count, &odd_perc, &even_perc, random_array, ARRAY_SIZE); //calculate % of odd and even random numbers
	calc_freq_double(random_array_double, random_freq_double, ARRAY_SIZE); //frequency of pair of numbers

	//print results
	printf("Mean of %d Random Numbers %.4f\n\n", ARRAY_SIZE, array_mean); //mean
	for (n = 0; n < 10; n++) {
		printf("Frequency of Random Number %d = %d\n", n, random_freq[n]); //freq dist
	}
	printf("\n");
	printf("Percentage of Odd numbers = %.2f\n", odd_perc); //percentage
	printf("Percentage of Even numbers = %.2f\n\n", even_perc); //percentage

	for (row = 0; row < 100; row++) {
		printf("Random combination %02d: %3d %.4f %c\n", row, random_freq_double[row], (float) (100.0*random_freq_double[row]/ARRAY_SIZE), 37);
	}
	printf("\n");

	calc_gap_test(random_array, ARRAY_SIZE, random_gap_array); //calculate gap frequency
	
	//calculate distribution of the gaps
	for (row = 0; row < 7; row++) { 	//calculate the sum total of all gaps
		gap_total += random_gap_array[row];
	}
	//Now print the gap %
	for (row = 0; row < 7; row++) {
		printf("Random gap array %.2f\n", 100*(float) random_gap_array[row]/gap_total);
	}
}