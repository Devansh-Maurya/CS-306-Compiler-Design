#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isIntKeyword(const char *);
bool isCharKeyword(const char *);
bool isInteger(const char*);
bool isFractionalNumber(const char*);
bool isIdentifier(const char*);
bool isAlphabet(char);

int main() {
    char *str = malloc(100);
    char *token, *ptr = str;

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    printf("You entered: %s", str);

    while ((token = strsep(&str, " "))) {
        printf("\n%s : ", token);

        if (isIntKeyword(token))
            printf("<INT_KEYW>");
        else if (isCharKeyword(token))
            printf("<CHAR_KEYW>");
        else if (isInteger(token))
            printf("<INT_NUM>");
        else if (isFractionalNumber(token))
            printf("<FRACT_NUM>");
        else if (isIdentifier(token))
            printf("<IDENTIFIER>");
    }

    free(ptr);
    return 0;
}

bool isIntKeyword(const char *token) {

    if (!strcmp(token, "int"))
        return true;
    else
        return false;
}

bool isCharKeyword(const char *token) {

    if (!strcmp(token, "char"))
        return true;
    else
        return false;
}

bool isInteger(const char* token) {

    //strtol() helps to check any errors in token while trying to parse it as int
    //The error is checked using the pointer passed as second parameter

    char *invalidTokenStartPointer;
    strtol(token, &invalidTokenStartPointer, 10);

    if (!strcmp(invalidTokenStartPointer, ""))
        return true;
    else
        return false;
}

bool isFractionalNumber(const char* token) {

    char *invalidTokenStartPointer;
    strtod(token, &invalidTokenStartPointer);

    if (!strcmp(invalidTokenStartPointer, ""))
        return true;
    else
        return false;
}

bool isIdentifier(const char* token) {

    if (isAlphabet(token[0]) || token[0] == '_')
        return true;
    else
        return false;
}

bool isAlphabet(const char c) {
    if(tolower(c) >= 'a' && tolower(c) <= 'z')
        return true;
    else
        return false;
}