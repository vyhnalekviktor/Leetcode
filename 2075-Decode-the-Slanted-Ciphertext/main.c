#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// works but not for matrix
void decodeCiphertext(char* encodedText, int rows, char** decodedText) {
    int rowLength;
    if (rows>1) {
        rowLength = ((int)strlen(encodedText) - rows+1) / rows;
    }
    else {
        rowLength = ((int)strlen(encodedText));
    }

    char* originalText= (char*) malloc(sizeof(char)*rowLength*rows+1);
    for (int i=0; i<rowLength; i++) {
        for (int j=0; j<rows; j++) {
            originalText[i*rowLength+j] = encodedText[j*rowLength + i + j];
        }
    }
    originalText[rowLength * rows] = '\0';

    *decodedText = strncpy(originalText, encodedText, rowLength*rows);
    (*decodedText)[rowLength*rows]= '\0';
}

constexpr int MAX_LEN = 101;
int main() {
    int rows;
    printf("enter num of rows:\n");
    if (scanf("%d", &rows) != 1 || rows <= 1 || rows > 1000) {return 1;}
    char* str = (char*) malloc(sizeof(char)*MAX_LEN);
    printf("enter string:\n");
    char* decodedText=NULL;
    decodeCiphertext(str, rows, &decodedText);
    printf("%s\n",decodedText);
    free(decodedText);
    return 0;
}