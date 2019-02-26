#include <stdio.h>
#include <stdlib.h>

#define a 'a'
#define b 'b'
#define c 'c'

char* input;

void match(char);
void S();
void S_();
void A();
void A_();

int main() {

    input = malloc(100*sizeof(char));

    printf("Input: ");
    scanf("%s", input);
    S();

    if (*input == NULL)
        printf("\nVALID");
    else
        printf("\nSYNTAX ERROR");

    free(input);
    return 0;
}

void S() {
    match(a);
    S_();
    match(c);
}

void S_() {
    switch (*input) {
        case a:
            match(a);
            S_();
            match(c);
            break;
        case b:
            A();
            break;
    }
}

void A() {
    match(b);
    A_();
}

void A_() {
    switch (*input) {
        case b:
            A();
            match(c);
            break;
        case c:
            match(c);
            break;
    }
}

void match(char ch) {
    if (*input == ch) {
        printf("%c", *input);
        input += 1;
    }
    else {
        printf("\nSYNTAX ERROR");
    }
}