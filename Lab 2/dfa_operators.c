#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define RIGHT_ARROW '>'
#define EQUALS '='

void invalid();
void valid();
void greaterThan();
void rightShiftAssign();
void greaterThanOrEqualTo();
void rightShift();

int main() {

    char str[100];
    int i = 0;

    printf("Input: ");
    scanf("%[^\n]s", str);

    printf("You entered: %s\n\n", str);

    start:
    while (str[i++] != RIGHT_ARROW) {
        if (str[i + 1] == '\0')
            invalid();
    }

    if (str[i] == RIGHT_ARROW) {
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