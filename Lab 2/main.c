#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

#define DOT '.'

bool isNumber(char);
void invalid();
void valid();

int main() {

    char *str = malloc(100);
    int i = 0;

    printf("Input: ");
    scanf("%[^\n]s", str);

    printf("You entered: %s", str);

    if (str[0] == DOT)
        invalid();
    else {
        if (isNumber(str[i++])) {
            while (str[i++] != DOT) {
                if ((str[i + 1]) == '\0')
                    invalid();
            }
            if (isNumber(str[i++])) {
                while (str[i++] != DOT) {
                    if (str[i + 1] == '\0')
                        valid();
                }
            } else {
                invalid();
            }

        } else {
            invalid();
        }
    }

    free(str);
    return 0;
}

bool isNumber(const char c) {
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}

void invalid() {
    printf("\nNO\n");
    exit(4);
}

void valid() {
    printf("\nYES\n");
    exit(0);
}