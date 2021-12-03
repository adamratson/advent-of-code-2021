// day3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>

#define FULL_LINE_LENGTH 14
#define LINE_LENGTH FULL_LINE_LENGTH - 2

std::vector<int> calculateOccurences(std::vector<std::string> strings) {
	std::vector<int> occurenceArray;

	for (int x = 0; x < LINE_LENGTH; x++) {
		occurenceArray.push_back(0);
	}

	for (int arrayPos = 0; arrayPos < strings.size(); arrayPos++) {
		for (int stringPos = 0; stringPos < LINE_LENGTH; stringPos++) {
			if (strings[arrayPos][stringPos] == '0') {
				occurenceArray[stringPos]--;
			}
			else {
				occurenceArray[stringPos]++;
			}
		}
	}

	return occurenceArray;
}

int toDecimal(std::string string) {
	int result = 0;
	for (int x = 0; x < string.size(); x++) {
		int multiplier = pow(2, (double)x);
		char bit = string[string.size() - 1 - x];
		result += (bit - '0') * multiplier;
	}

	return result;
}

int main()
{
	FILE* input;
	fopen_s(&input, "input.txt", "r");

	if (!input) {
		printf("Could not open file.");
		exit(-1);
	}

	char chunk[FULL_LINE_LENGTH];
	std::vector<std::string> lines;

	while (fgets(chunk, sizeof(chunk), input)) {
		lines.push_back(chunk);
	}

	std::vector<int> occurenceArray = calculateOccurences(lines);

	std::vector<std::string> possibleOxygenGeneratorRatings = lines;
	for (int occurencePos = 0; occurencePos < occurenceArray.size(); occurencePos++) {
		std::vector<std::string> newPossibleOxygenGeneratorRatings;
		int occurence = occurenceArray[occurencePos];
		for (int x = 0; x < possibleOxygenGeneratorRatings.size(); x++) {
			if (occurence < 0 && possibleOxygenGeneratorRatings[x][occurencePos] == '0') {
				newPossibleOxygenGeneratorRatings.push_back(possibleOxygenGeneratorRatings[x]);
			}
			else if (occurence >= 0 && possibleOxygenGeneratorRatings[x][occurencePos] == '1') {
				newPossibleOxygenGeneratorRatings.push_back(possibleOxygenGeneratorRatings[x]);
			}
		}

		possibleOxygenGeneratorRatings = newPossibleOxygenGeneratorRatings;
		if (possibleOxygenGeneratorRatings.size() == 1) {
			break;
		}
		occurenceArray = calculateOccurences(possibleOxygenGeneratorRatings);
	}

	possibleOxygenGeneratorRatings[0].pop_back();
	int oxygenGeneratorRating = toDecimal(possibleOxygenGeneratorRatings[0]);

	occurenceArray = calculateOccurences(lines);

	std::vector<std::string> possibleCo2ScrubberRatings = lines;
	for (int occurencePos = 0; occurencePos < occurenceArray.size(); occurencePos++) {
		std::vector<std::string> newPossibleCo2ScrubberRatings;
		int occurence = occurenceArray[occurencePos];
		for (int x = 0; x < possibleCo2ScrubberRatings.size(); x++) {
			if (occurence < 0 && possibleCo2ScrubberRatings[x][occurencePos] == '1') {
				newPossibleCo2ScrubberRatings.push_back(possibleCo2ScrubberRatings[x]);
			}
			else if (occurence >= 0 && possibleCo2ScrubberRatings[x][occurencePos] == '0') {
				newPossibleCo2ScrubberRatings.push_back(possibleCo2ScrubberRatings[x]);
			}
		}

		possibleCo2ScrubberRatings = newPossibleCo2ScrubberRatings;
		if (possibleCo2ScrubberRatings.size() == 1) {
			break;
		}
		occurenceArray = calculateOccurences(possibleCo2ScrubberRatings);
	}

	possibleCo2ScrubberRatings[0].pop_back();
	int co2ScrubberRating = toDecimal(possibleCo2ScrubberRatings[0]);

	int result = oxygenGeneratorRating * co2ScrubberRating;

	printf("Oxygen generator rating is %d, CO2 scrubber rating is %d, result is %d.\n", oxygenGeneratorRating, co2ScrubberRating, result);

	fclose(input);
}