// day3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define LINE_LENGTH 14
#define ARRAY_LENGTH LINE_LENGTH - 2

int main()
{
	FILE* input;
	fopen_s(&input, "input.txt", "r");

	if (!input) {
		printf("Could not open file.");
		exit(-1);
	}

	char chunk[LINE_LENGTH];

	int array[ARRAY_LENGTH] = { 0, 0, 0, 0, 0 };

	while (fgets(chunk, sizeof(chunk), input)) {
		for (int x = 0; x < ARRAY_LENGTH; x++) {
			char value = chunk[x];
			if (value == '0') {
				array[x]--;
			}
			else {
				array[x]++;
			}
		}
	}

	char gammaChar[ARRAY_LENGTH];
	char epsilonChar[ARRAY_LENGTH];
	for (int x = 0; x < sizeof(gammaChar); x++) {
		if (array[x] < 0) {
			gammaChar[x] = '0';
			epsilonChar[x] = '1';
		}
		else {
			gammaChar[x] = '1';
			epsilonChar[x] = '0';
		}
	}

	int gamma = toDecimal(gammaChar, sizeof(gammaChar));
	int epsilon = toDecimal(epsilonChar, sizeof(epsilonChar));

	int result = gamma * epsilon;

	printf("Gamma is %d, epsilon is %d, result is %d", gamma, epsilon, result);

	fclose(input);
}

int toDecimal(char array[], int size) {
	int result = 0;
	for (int x = 0; x < size; x++) {
		int multiplier = pow(2, (double)x);
		char bit = array[size - 1 - x];
		result += (bit - '0') * multiplier;
	}

	return result;
}