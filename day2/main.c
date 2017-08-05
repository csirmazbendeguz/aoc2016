#include <stdio.h>
#include <string.h>

/* 
 * Part 1 
 */
void solve_part_1() {
    char direction;
    int current_button = 5;

    // 1 2 3
    // 4 5 6
    // 7 8 9
    while ((direction = getchar()) != EOF) {
        switch (direction) {
            case 'U':
                if (current_button - 3 >= 1) {
                    current_button -= 3;
                }
                break;
            case 'L':
                if (current_button % 3 != 1) {
                    current_button--;
                }
                break;
            case 'D':
                if (current_button + 3 <= 9) {
                    current_button += 3;
                }
                break;
            case 'R':
                if (current_button % 3 != 0) {
                    current_button++;
                }
                break;
            default:
                printf("%d", current_button);
                break;
        }
    }
    printf("%d\n", current_button);
}

/*
 * Part 2
 */
void solve_part_2() {
    // 0 0 0 0 0 0 0
    // 0 0 0 1 0 0 0
    // 0 0 2 3 4 0 0
    // 0 5 6 7 8 9 0
    // 0 0 A B C 0 0
    // 0 0 0 D 0 0 0
    // 0 0 0 0 0 0 0
    char key_pad[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, '1', 0, 0, 0},
        {0, 0, '2', '3', '4', 0, 0},
        {0, '5', '6', '7', '8', '9', 0},
        {0, 0, 'A', 'B', 'C', 0, 0},
        {0, 0, 0, 'D', 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
    };
    char direction;
    int current_row = 3;
    int current_column = 1;
    
    while ((direction = getchar()) != EOF) {
        switch (direction) {
            case 'U':
                if (key_pad[current_row - 1][current_column]) {
                    current_row--;
                }
                break;
            case 'L':
                if (key_pad[current_row][current_column - 1]) {
                    current_column--;
                }
                break;
            case 'D':
                if (key_pad[current_row + 1][current_column]) {
                    current_row++;
                }
                break;
            case 'R':
                if (key_pad[current_row][current_column + 1]) {
                    current_column++;
                }
                break;
            default:
                printf("%c", key_pad[current_row][current_column]);
                break;
        }
    }
    printf("%c\n", key_pad[current_row][current_column]);
}

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        return 1;
    }
    if (strcmp(argv[1], "1") == 0) {
        solve_part_1();
    }
    else if (strcmp(argv[1], "2") == 0) {
        solve_part_2();
    }

    return 0;
}
