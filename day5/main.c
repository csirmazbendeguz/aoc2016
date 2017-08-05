#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(__APPLE__)
#  define COMMON_DIGEST_FOR_OPENSSL
#  include <CommonCrypto/CommonDigest.h>
#  define SHA1 CC_SHA1
#else
#  include <openssl/md5.h>
#endif

char *str2md5(const char *str, int length) {
    int n;
    MD5_CTX c;
    unsigned char digest[16];
    char *out = (char*)malloc(33);

    MD5_Init(&c);

    while (length > 0) {
        if (length > 512) {
            MD5_Update(&c, str, 512);
        } else {
            MD5_Update(&c, str, length);
        }
        length -= 512;
        str += 512;
    }

    MD5_Final(digest, &c);

    for (n = 0; n < 16; ++n) {
        snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
    }

    return out;
}


int main(int argc, char **argv) {
    char password[9];
    int hashes_found = 0;

    char password_part_2[9];
    int hashes_found_part_2 = 0;

    char door_id[64];
    unsigned long i = 0;

    scanf("%s", door_id);
    size_t door_id_length = strlen(door_id);

    while (hashes_found < 8 || hashes_found_part_2 < 8) {
      char i_string[48];
      sprintf(i_string, "%lu", i);

      int j = 0;
      while (i_string[j] != '\0') {
        door_id[door_id_length + j] = i_string[j];
        j++;
      }

      char *hash = str2md5(door_id, door_id_length + j);
      char starts_with_5_zeroes = 1;

      int k = 0;
      for (; k < 5; k++) {
        if (hash[k] != '0') {
          starts_with_5_zeroes = 0;
          break;
        }
      }

      if (starts_with_5_zeroes) {
        if (hashes_found < 8) {
          password[hashes_found] = hash[5];
          hashes_found++;
        }

        if (hashes_found_part_2 < 8 &&
          hash[5] >= '0' &&
          hash[5] <= '7' &&
          !password_part_2[hash[5] - '0'])
        {
          password_part_2[hash[5] - '0'] = hash[6];
          hashes_found_part_2++;
        }
      }

      free(hash);

      i++;
    }

    printf("%s\n", password);
    printf("%s\n", password_part_2);

    return 0;
}
