#include <stdio.h>
#include <string.h>

int numDecodings(char* s) {
    int length = (int) strlen(s);
    // catch errors
    if (s[0] == '0') return 0;
    if (s[1]=='0' && s[0]>'2') {return 0;}

    // start of variants. varaints[1] --> num of variants for the first char of string
    int variants[length+1];
    variants[0] = 1;
    variants[1] = 1;

    // go through every char
    for (int i = 2; i <= length; i++) {
        variants[i] = 0;

        // check if is valid num & add write possible variants with single num
        if (s[i-1] >= '1' && s[i-1] <= '9') {
            variants[i] += variants[i-1];
        }

        // check if is valid double number, if yes, add also every variant with this double num
        int two = (s[i-2]-'0')*10 + (s[i-1]-'0');
        if (two >= 10 && two <= 26) {
            variants[i] += variants[i-2];
        }

        if (variants[i] == 0) return 0;
    }
    return variants[length];
}

int main() {
    printf("Write cypher (max 100 chars):\n");
    char string[101];
    scanf("%100s", string);
    printf("%d\n", numDecodings(string));
    return 0;
}