//
// Created by devansh on 11/2/19.
//

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define GREATER_THAN '>'
#define EQUALS '='
#define DOT '.'
#define DELIMITERS ">="

void invalid();
void greaterThan();
void rightShiftAssign();
void greaterThanOrEqualTo();
void rightShift();
bool isAlphabet(char);
bool isDigit(char);
bool isFractionalNumber(const char *);
bool isIntegerNumber(const char *);
bool isIdentifier(const char*);

int main() {

    char *str, *tok, *splitStr;
    int i = 0, len;

    str = malloc(100* sizeof(char));

    printf("Input: ");
    scanf("%[^\n]s", str);

    len = strlen(str);

    printf("You entered: %s\n\n", str);
    strcpy(splitStr, str);

    start:

    if (str[i] != GREATER_THAN && str[i] != EQUALS) {
        tok = strtok(splitStr + i, DELIMITERS);
        if (!isIntegerNumber(tok))
            if(!isFractionalNumber(tok))
                isIdentifier(tok);
        i = i + strlen(tok);
    }

    if (i == len)
        exit(0);


    while (str[i++] != GREATER_THAN) {
        if (str[i + 1] == '\0') {
            invalid();
        }
    }

    if (str[i] == GREATER_THAN) {
        i++;
        if (str[i] == EQUALS) {
            rightShiftAssign();
            goto start;
        } else {
            rightShift();
            goto start;
        }

    } else if (str[i] == EQUALS) {
        greaterThanOrEqualTo();
        i++;
        goto start;
    } else {
        greaterThan();
        goto start;
    }

}

void invalid() {
    printf("\nINVALID\n");
    exit(4);
}

void valid() {
    printf("\nYES\n");
    exit(0);
}

void greaterThan() {
    printf("<GREATER_THAN>\n");
}

void greaterThanOrEqualTo() {
    printf("<GREATER_THAN_OR_EQUAL_TO>\n");
}

void rightShiftAssign() {
    printf("<RIGHT_SHIFT_ASSIGN>\n");
}

void rightShift() {
    printf("<RIGHT_SHIFT>\n");
}

bool isDigit(char c) {
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}

bool isIdentifier(const char* token) {

    if (isAlphabet(token[0]) || token[0] == '_') {
        for (int i = 0; token[i] != NULL ; ++i) {
            if (!isAlphabet(token[i]) && token[i] != '_' && !isDigit(token[i]))
                return false;
        }
        printf("<IDENTIFIER>\n");
    }
    else
        return false;
}

bool isAlphabet(char c) {
    if(tolower(c) >= 'a' && tolower(c) <= 'z')
        return true;
    else
        return false;
}

bool isIntegerNumber(const char *str) {
    for (int i = 0; str[i] != NULL ; ++i) {
        if (!isDigit(str[i])) {
            return false;
        }
    }
    printf("<INT_NUM>\n");
    return true;
}

bool isFractionalNumber(const char *str) {
    int i = 0;
    bool isFract = false;

    if (str[0] == DOT) {
        return false;
    }
    else {
        if (isDigit(str[i++])) {
            while (str[i++] != DOT) {
                if ((str[i]) == '\0') {
                    return false;
                }
            }
            if (isDigit(str[i++])) {
                while (str[i++] != DOT) {
                    if (str[i] == '\0')
                        isFract = true;
                }
            } else {
                return false;
            }

        } else {
            return false;
        }
    }

    if (isFract)
        printf("<FRACT_NUM>\n");
}

