#include <stdio.h>
#include <string.h>
#include <limits.h>

// Modify this according to your input.
#define COLUMNS 8

int main(int argc, const char * argv[]) {
	// Store input.
	int char_frequency[COLUMNS][26] = {0};

	char line[COLUMNS + 1];
	while (scanf("%s\n", line) != EOF) {
		for (int i = 0; i < COLUMNS; i++) {
			char c = line[i];
			char_frequency[i][c - 'a']++;
		}
	}

	// Do min/max search.
	char error_corrected_message[COLUMNS + 1];
	char error_corrected_message_part_2[COLUMNS + 1];

	for (int i = 0; i < COLUMNS; i++) {
		int most_frequent_char = 0;
		int max_frequency = 0;

		int least_frequent_char = 0;
		int min_frequency = INT_MAX;

		for (int j = 0; j < 26; j++) {
			if (max_frequency < char_frequency[i][j]) {
				max_frequency = char_frequency[i][j];
				most_frequent_char = j;
			}

			if (min_frequency > char_frequency[i][j] &&
				char_frequency[i][j] >= 1
			) {
				min_frequency = char_frequency[i][j];
				least_frequent_char = j;
			}
		}

		error_corrected_message[i] = most_frequent_char + 'a';
		error_corrected_message_part_2[i] = least_frequent_char + 'a';
	}

	printf("%s\n", error_corrected_message);
	printf("%s\n", error_corrected_message_part_2);

    return 0;
}
