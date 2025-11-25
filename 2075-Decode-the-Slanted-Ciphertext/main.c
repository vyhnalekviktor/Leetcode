#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ch ie pr --> 8 znaku
char* decodeCiphertext(char* encodedText, int rows) {
    int rowLength = (strlen(encodedText) - rows+1) / rows; // = 2
    char* decodedText = (char*) malloc(sizeof(char)*rowLength*rows+1); // size = 6* char

    // save decoded
    for (int i=0; i<rows; i++) {
        for (int j=0; j<rowLength; j++) {
            int spacePos = rows*j;
            decodedText[i*rowLength+j] = encodedText[j*rowLength + i + spacePos];
        }
    }
    decodedText[rowLength*rows]= '\0';
    return decodedText;
}

constexpr int MAX_LEN = 101;
int main() {
    int rows;
    printf("enter num of rows:\n");
    if (scanf("%d", &rows) != 1 || rows <= 1 || rows > 1000) {return 1;}
    char* str = (char*) malloc(sizeof(char)*MAX_LEN);
    printf("enter string:\n");
    scanf("%100s", str);

    printf("%s\n",decodeCiphertext(str, rows));
    free(str);
}