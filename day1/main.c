#include <stdio.h>
#include <stdlib.h>

int main() {
    char current_direction = 'N';
    int x = 0, y = 0;
    
    char direction;
    int steps;
    
    int visited_coordinates[1000][1000] = {0};
    int offset = 500; // 0 will be 500, -1 = 499, 1 = 501 etc
    int first_location = 0;
    
    while (scanf("%c%d", &direction, &steps) != EOF) {
        switch (current_direction) {
            case 'N':
                current_direction = (direction == 'R') ? 'E' : 'W';
                break;
            case 'E':
                current_direction = (direction == 'R') ? 'S' : 'N';
                break;
            case 'S':
                current_direction = (direction == 'R') ? 'W' : 'E';
                break;
            case 'W':
                current_direction = (direction == 'R') ? 'N' : 'S';
                break;
        }
        
        switch (current_direction) {
            case 'N':
            {
                for (int i = y; i < y + steps; i++) {
                    if (!first_location && visited_coordinates[x + offset][i + offset]) {
                        first_location = abs(x) + abs(i);
                    }
                    visited_coordinates[x + offset][i + offset] = 1;
                }
                y += steps;
                break;
            }
            case 'E':
            {
                for (int i = x; i < x + steps; i++) {
                    if (!first_location && visited_coordinates[i + offset][y + offset]) {
                        first_location = abs(i) + abs(y);
                    }
                    visited_coordinates[i + offset][y + offset] = 1;
                }
                x += steps;
                break;
            }
            case 'S':
            {
                for (int i = y; i > y - steps; i--) {
                    if (!first_location && visited_coordinates[x + offset][i + offset]) {
                        first_location = abs(x) + abs(i);
                    }
                    visited_coordinates[x + offset][i + offset] = 1;
                }
                y -= steps;
                break;
            }
            case 'W':
            {
                for (int i = x; i > x - steps; i--) {
                    if (!first_location && visited_coordinates[i + offset][y + offset]) {
                        first_location = abs(i) + abs(y);
                    }
                    visited_coordinates[i + offset][y + offset] = 1;
                }
                x -= steps;
                break;
            }
        }
        
        scanf(", ");
    }
    
    printf("%d\n", abs(x) + abs(y));
    printf("%d\n", first_location);
    
    return 0;
}
