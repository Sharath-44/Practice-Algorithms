#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *bin2hex(char *bin)
{
    // int i, j, length = strlen(bin);
    // char *hex = (char *) malloc(length / 4 + 1);
    // for (i = 0, j = 0; i < length; i += 4, j++) {
    //     int decimal = 0;
    //     for (int k = 0; k < 4; k++) {
    //         decimal += (bin[i + k] - '0') * (1 << (3 - k));
    //     }
    //     if (decimal < 10) {
    //         hex[j] = decimal + '0';
    //     } else {
    //         hex[j] = decimal - 10 + 'A';
    //     }
    // }
    // hex[j] = '\0';
    // return hex;

    int length = strlen(bin);
    char *outStr;
    static char hex[] = "0123456789ABCDEF";
    int len = strlen(bin) / 4;
    int i = strlen(bin) % 4;
    char current = 0;
    if (i)
    {
        while (i--)
        {
            current = (current << 1) + (*bin - '0');
            bin++;
        }
        *outStr = hex[current];
        ++outStr;
    }
    while (len--)
    {
        current = 0;
        for (i = 0; i < 4; ++i)
        {
            current = (current << 1) + (*bin - '0');
            bin++;
        }
        *outStr = hex[current];
        ++outStr;
    }
    *outStr = 0;
}

int main()
{
    char bin[100];
    scanf("%s", bin);
    char *hex = bin2hex(bin);
    printf("%s\n", hex);
    free(hex);
    return 0;
}