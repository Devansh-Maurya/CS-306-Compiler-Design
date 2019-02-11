//
// Created by devansh on 11/2/19.
//

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define GREATER_THAN '>'
#define EQUALS '='

void invalid();
void valid();
void greaterThan();
void rightShiftAssign();
void greaterThanOrEqualTo();
void rightShift();
int getOperatorPosition(const char*, int);
bool isAlphabet(char);
bool isNumber(char);
bool isIdentifier(const char*);

int main() {

    char str[100];
    int i = 0;

    printf("Input: ");
    scanf("%[^\n]s", str);

    printf("You entered: %s\n\n", str);

    int pos = getOperatorPosition(str, 0);
    if (pos == 0)
        invalid();

    start:
    while (str[i++] != GREATER_THAN) {
        if (str[i + 1] == '\0')
            exit(4);
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
    } else {
        greaterThan();
        goto start;
    }

}

void invalid() {
    printf("\nNO\n");
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
    printf("<GREATER_THAN_OR_EQUAL_TO\n");
}

void rightShiftAssign() {
    printf("<RIGHT_SHIFT_ASSIGN>\n");
}

void rightShift() {
    printf("<RIGHT_SHIFT>\n");
}

int getOperatorPosition(const char* str, int startPos) {

    int i = startPos;

    while ((str[i++] != GREATER_THAN) || (str[i++] != EQUALS) || (str[i++] != '\0'));
    return i-1;
}

int isValidIdentifierOrNumber(const char* str, int startPos, int endPos) {

}

bool isNumber(char c) {
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}


//TODO: Complete this function
bool isIdentifier(const char* token) {

    if (isAlphabet(token[0]) || token[0] == '_')
        return true;
    else
        return false;
}

bool isAlphabet(char c) {
    if(tolower(c) >= 'a' && tolower(c) <= 'z')
        return true;
    else
        return false;
}

