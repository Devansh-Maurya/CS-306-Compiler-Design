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

    while ((token = strsep(&str, " ;, "))) {
        //printf("\n%s : ", token);

	if(!strcmp(token, " "))
	    continue;

        if (isIntKeyword(token))
            printf("\n%s : <INT_KEYW>", token);
        else if (isCharKeyword(token))
            printf("\n%s : <CHAR_KEYW>", token);
        else if (isInteger(token))
            printf("\n%s : <INT_NUM>", token);
        else if (isFractionalNumber(token))
            printf("\n%s : <FRACT_NUM>", token);
        else if (isIdentifier(token))
            printf("\n%s : <IDENTIFIER>", token);
	else if (isInteger(token))
	    printf("\n%s : <INT_NUM>", token);
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
    int num = strtol(token, &invalidTokenStartPointer, 10);

    if (num == 0) {
		return false;
	}

    if (!strcmp(invalidTokenStartPointer, ""))
        return true;
    else
        return false;
}

bool isFractionalNumber(const char* token) {

    char *invalidTokenStartPointer;
    double num = strtod(token, &invalidTokenStartPointer);

	if (num == 0) {
		return false;
	}

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
