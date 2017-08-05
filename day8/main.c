#include <stdio.h>
#include <string.h>
#include <regex.h> 
#include <stdlib.h> 

#define WIDTH 50
#define HEIGHT 6

#define RECT "rect ([0-9]+)x([0-9]+)"
#define ROTATE_ROW "rotate row y=([0-9]+) by ([0-9]+)"
#define ROTATE_COLUMN "rotate column x=([0-9]+) by ([0-9]+)"
#define NMATCH 3

void compile_expressions(regex_t *rect, regex_t *rotate_row, regex_t *rotate_column) {
	if (regcomp(rect, RECT, REG_EXTENDED)) {
	    fprintf(stderr, "Could not compile regex: %s\n", RECT);
	    exit(1);
	}
	if (regcomp(rotate_row, ROTATE_ROW, REG_EXTENDED)) {
	    fprintf(stderr, "Could not compile regex: %s\n", ROTATE_ROW);
	    exit(1);
	}
	if (regcomp(rotate_column, ROTATE_COLUMN, REG_EXTENDED)) {
	    fprintf(stderr, "Could not compile regex: %s\n", ROTATE_COLUMN);
	    exit(1);
	}
}

int substring_to_dec(char *start, char *end) {
	int result = 0;
	int base = 1;

	while (start <= end) {
		int current_number = *end - '0';
		result += current_number * base;
		
		base *= 10;
		end--;
	}

	return result;
}

int main(int argc, const char * argv[]) {
	char screen[HEIGHT][WIDTH] = {0};
    
    char *instruction = NULL;
    size_t len = 0;
    int a, b, i, j;

    regex_t rect, rotate_row, rotate_column;
	regmatch_t pmatch[NMATCH];

    compile_expressions(&rect, &rotate_row, &rotate_column);

    while (getline(&instruction, &len, stdin) != -1) {
    	if (!regexec(&rect, instruction, NMATCH, pmatch, 0)) {
    		a = substring_to_dec(instruction + pmatch[1].rm_so, instruction + pmatch[1].rm_eo - 1);
    		b = substring_to_dec(instruction + pmatch[2].rm_so, instruction + pmatch[2].rm_eo - 1);
    		
    		for (i = 0; i < b; i++) {
    			for (j = 0; j < a; j++) {
    				screen[i][j] = 1;
    			}
    		}
    	}
    	else if (!regexec(&rotate_row, instruction, NMATCH, pmatch, 0)) {
    		a = substring_to_dec(instruction + pmatch[1].rm_so, instruction + pmatch[1].rm_eo - 1);
    		b = substring_to_dec(instruction + pmatch[2].rm_so, instruction + pmatch[2].rm_eo - 1);

    		while (b--) {
    			char prev_cell = screen[a][0];
	    		char end = screen[a][WIDTH - 1];
	    		for (i = 1; i < WIDTH; i++) {
	    			char curr_cell = screen[a][i];
	    			screen[a][i] = prev_cell;
	    			prev_cell = curr_cell;
	    		}
	    		screen[a][0] = end;    		
	    	}
    	}
    	else if (!regexec(&rotate_column, instruction, NMATCH, pmatch, 0)) {
    		a = substring_to_dec(instruction + pmatch[1].rm_so, instruction + pmatch[1].rm_eo - 1);
    		b = substring_to_dec(instruction + pmatch[2].rm_so, instruction + pmatch[2].rm_eo - 1);

    		while (b--) {
    			char prev_cell = screen[0][a];
	    		char end = screen[HEIGHT - 1][a];
	    		for (i = 1; i < HEIGHT; i++) {
	    			char curr_cell = screen[i][a];
	    			screen[i][a] = prev_cell;
	    			prev_cell = curr_cell;
	    		}
	    		screen[0][a] = end;
    		}
    	}
    	else {
    		printf("Unknown instruction: %s\n", instruction);
    	}
    }

	regfree(&rect);
	regfree(&rotate_row);
	regfree(&rotate_column);

	int counter = 0;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			if (screen[i][j]) {
				counter++;
			}
			printf("%c", screen[i][j] ? '#' : '.');
		}
		printf("\n");
	}
	printf("%d\n", counter);

    return 0;
}
