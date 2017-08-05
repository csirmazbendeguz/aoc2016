#include <stdio.h>

int is_possible_triangle(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 0;
    }
    return a + b > c && a + c > b && c + b > a;
}

int main(int argc, const char * argv[]) {
    /* Part 1 */
    int possible_count = 0;
    int a, b, c;
    
    /* Part 2 */
    int possible_count_vertical = 0;
    int current_row = 0;
    int triangle_buffer[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    
    while(scanf(" %d %d %d", &a, &b, &c) != EOF) {
        if (is_possible_triangle(a, b, c)) {
            possible_count++;
        }
        
        triangle_buffer[current_row][0] = a;
        triangle_buffer[current_row][1] = b;
        triangle_buffer[current_row][2] = c;
        
        current_row++;
        
        if (current_row > 2) {
            for (int i = 0; i < 3; i++) {
                if (is_possible_triangle(triangle_buffer[0][i],
                                         triangle_buffer[1][i],
                                         triangle_buffer[2][i]))
                {
                    possible_count_vertical++;
                }
            }
            current_row = 0;
        }
    }
    
    printf("%d\n", possible_count);
    printf("%d\n", possible_count_vertical);
    
    return 0;
}
