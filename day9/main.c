#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

// Arbitrary size to store input.
#define SIZE 65536

unsigned long marker_length(char*, unsigned long*, int, int);

/*
 * Utility function to read an integer from the given location of string
 * and set location to the last digit position + 1.
 */
int read_int_from_string(char str[], unsigned long *i) {
	int num = 0;

	while (str[*i] >= '0' && str[*i] <= '9') {
		char n = str[*i] - '0';
		num *= 10;
		num += n;
		*i = *i + 1;
	}

	return num;
}

int main(int argc, const char * argv[]) {
	char input[SIZE];
	fread(input, 1, SIZE, stdin);

	char decompressed[SIZE * 4];
	char c;

	unsigned long i, j;
	i = j = 0;
	int a, b;

	/*
	 * Part 1
	 */
	while ((c = input[i])) {
		if (c == '(') { // Found a marker e.g. "(123x45)"
			i += 1;
			a = read_int_from_string(input, &i);
			i += 1;
			b = read_int_from_string(input, &i); // i will stand on ')' here.
			i += 1;

			int seq_start, seq_end, k;
			seq_start = i;
			seq_end = i + a;

			while (b--) {
				for (k = seq_start; k < seq_end; k++) {
					decompressed[j] = input[k];
					j++;
				}
			}

			i = seq_end;
		}
		else { // Plain text w/o markers.
			decompressed[j] = input[i];
			j++;
			i++;
		}
	}

	printf("%lu\n", strlen(decompressed));

	/*
	 * Part 2
	 */
	unsigned long decompressed_length = 0;
	i = 0;

	while ((c = input[i])) {
		if (c == '(') {
			i += 1;
			a = read_int_from_string(input, &i);
			i += 1;
			b = read_int_from_string(input, &i);
			i += 1;

			decompressed_length += marker_length(input, &i, a, b);
		}
		else {
			decompressed_length++;
			i++;
		}
	}

	printf("%lu\n", decompressed_length);

    return 0;
}

/* 
 * Calculate the length of a marker. 
 *
 * str: the whole string
 * start_i: the first position in string after the closing parenthesis of given marker
 *			will be set to the last position of marker sequence + 1
 * a: sequence length of marker
 * b: times to repeat of marker
 */
unsigned long marker_length(char str[], unsigned long *start_i, int a, int b) {
	unsigned long length = 0;
	unsigned long i, l;
	int nested_a, nested_b;

	// Base case: no nested markers.
	for (i = *start_i, l = *start_i + a; i < l; i++) {
		if (str[i] == '(' || str[i] == ')') {
			length = 0;
			break;
		}
		else {
			length += b;
		}
	}
	if (length) {
		*start_i = i;
		return length;
	}

	// Recursion: contains nested markers.
	for (i = *start_i, l = *start_i + a; i < l; i++) {
		if (str[i] == '(') {
			i += 1;
			nested_a = read_int_from_string(str, &i);
			i += 1;
			nested_b = read_int_from_string(str, &i);
			i += 1;

			length += marker_length(str, &i, nested_a, nested_b) * b;
			i -= 1;
		}
		else {
			length += b;
		}
	}

	*start_i = i;
	return length;
}
