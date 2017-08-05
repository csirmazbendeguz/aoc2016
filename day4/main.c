#include <stdio.h>
#include <string.h>

void decrypt(char string[], int shift) {
    int i = 0;
    
    while (string[i] != '\0') {
        if (string[i] == '-') {
            string[i] = ' ';
        }
        else {
            string[i] = (string[i] - 'a' + shift % 26) % 26 + 'a';
        }
        i++;
    }
}

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        return 1;
    }

    int sector_id_sum = 0;
    char name[100], checksum[6];
    int sector_id;
    
    while (scanf("%[^0-9] %d [ %[^]] ]\n", name, &sector_id, checksum) != EOF) {
        // Get how frequent each character is.
        char char_frequency[26] = {0};
        size_t i, name_length = strlen(name);
        
        for (i = 0; i < name_length; i++) {
            char c = name[i];
            if (c - 'a' >= 0 && c - 'a' <= 25) {
                char_frequency[c - 'a']++;
            }
        }
        
        // Get the 5 most frequent characters (in alphabetical order) into a string.
        char real_checksum[6] = {0};
        
        for (i = 0; i < 5; i++) {
            int j, max = 0;
            
            for (j = 0; j < 26; j++) {
                if (char_frequency[j] > char_frequency[max]) {
                    max = j;
                }
            }
            
            char_frequency[max] = -1;
            real_checksum[i] = max + 'a';
        }
        
        real_checksum[5] = '\0';
        
        // Check whether the checksum is correct.
        if (strcmp(checksum, real_checksum) == 0) {
            sector_id_sum += sector_id;
        }
        
        // Part 2
        // Decrypt name.
        decrypt(name, sector_id);
        if (*argv[1] == '2' && strcmp(name, "northpole object storage ") == 0) {
            printf("%d\n", sector_id);
            return 0;
        }
    }
    
    if (*argv[1] == '1') {
        printf("%d\n", sector_id_sum);
    }
    
    return 0;
}
