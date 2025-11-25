#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* decodeCiphertext(char* encodedText, int rows) {
    int strLen = (int) strlen(encodedText)-(rows-1)*2;
    int cols, cp=0;
    if (rows==1) {cols = strLen;}
    else {
        cp = strLen-rows+1;
        if (cp%rows == 0) {cols = cp/rows;}
        else {cols = cp/rows+1;}
    }
    char* originalText = (char*) malloc(sizeof(char)*(cols*rows)+1);
    int Idx=0;
    int spaces = 2;
    for (int c=0; c<cols; c++) {
        for (int r=0; r<rows; r++) {
            int pos = (cp%rows!=0) ? c+r*(rows+1+spaces) : c+r*(rows+spaces);
            originalText[Idx] = encodedText[pos];
            Idx++;
        }
    }
    originalText[Idx]= '\0';
    printf("%s\n", originalText);
    return originalText;
}

int main(void) {
    assert(strncmp(decodeCiphertext("ch   ie   pr", 3),"cipher", 7)==0);
    assert(strncmp(decodeCiphertext("coding", 1), "coding", 7)==0);
    assert(strncmp(decodeCiphertext("iveo    eed   l te   olc", 4),"i love leetcode", 16)==0);
    return 0;
}