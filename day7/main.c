#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
	int tls_ips = 0;
	int ssl_ips = 0;
	char line[1024];

	while (scanf("%s\n", line) != EOF) {
		char currently_in_hypernet_sequence = 0;
		char found_abba_inside_hypernet_sequence = 0;
		char found_abba_outside_hypernet_sequence = 0;
		char found_ssl_pattern = 0;
		size_t i, length = strlen(line);

		for (i = 0; i <= length - 3; i++) {
			if (line[i] == '[') {
				currently_in_hypernet_sequence = 1;
			}
			else if (line[i] == ']') {
				currently_in_hypernet_sequence = 0;
			}
			else if ( // ABBA
				line[i] == line[i + 3] &&
				line[i + 1] == line[i + 2] &&
				line[i] != line[i + 1] &&
				i <= length - 4
			) {
				if (currently_in_hypernet_sequence) {
					found_abba_inside_hypernet_sequence = 1;
				}
				else {
					found_abba_outside_hypernet_sequence = 1;
				}
			}
			else if ( // Part 2
				!currently_in_hypernet_sequence &&
				line[i] == line[i + 2] &&
				line[i + 1] != line[i] &&
				line[i + 1] != '[' &&
				line[i + 1] != ']' &&
				!found_ssl_pattern
			) {
				// Found an ABA in "supernet" sequence
				// Search the string again for a BAB in a "hypernet" sequence.
				char a = line[i];
				char b = line[i + 1];
				char currently_in_hypernet_sequence_part_2 = 0;

				for (size_t j = 0; j <= length - 3; j++) {
					if (line[j] == '[') {
						currently_in_hypernet_sequence_part_2 = 1;
					}
					else if (line[j] == ']') {
						currently_in_hypernet_sequence_part_2 = 0;
					}
					else if (
						currently_in_hypernet_sequence_part_2 &&
						line[j] == b &&
						line[j + 1] == a &&
						line[j] == line[j + 2]
					) {
						found_ssl_pattern = 1;
					}
				}
			}
		}

		if (found_abba_outside_hypernet_sequence && 
			!found_abba_inside_hypernet_sequence) 
		{
			tls_ips++;
		}

		if (found_ssl_pattern) {
			ssl_ips++;
		}
	}

	printf("%d\n", tls_ips);
	printf("%d\n", ssl_ips);
}