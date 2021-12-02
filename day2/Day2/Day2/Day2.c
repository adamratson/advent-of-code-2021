// Day2.c : This file contains the 'main' function. Program execution begins and ends there.

#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE* input;
	fopen_s(&input, "input.txt", "r");

	if (!input) {
		printf("Could not open file.");
		exit(-1);
	}

	char chunk[11];

	int horizontal = 0;
	int depth = 0;
	int aim = 0;

	while (fgets(chunk, sizeof(chunk), input)) {
		if (chunk[0] == 'f') {
			int value = chunk[8] - '0';
			horizontal += value;
			depth += aim * value;
		}
		else if (chunk[0] == 'd') {
			aim += chunk[5] - '0';
		}
		else if (chunk[0] == 'u') {
			aim -= chunk[3] - '0';
		}
		else {
			printf("Invalid character found.");
			exit(-1);
		}
	}

	int result = horizontal * depth;

	printf("Depth is %d, horizontal is %d, final result is %d", depth, horizontal, result);

	fclose(input);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu