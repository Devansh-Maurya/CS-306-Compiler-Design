#include <stdio.h>
#include "token.h"
#include "lex.yy.c"

char currentToken;

void match(char);
void E();
void E_();
void T();
void T_();
void F();

int main() {
    currentToken = (char) yylex();


    return 0;
}

void E() {
    T();
    E_();
}

void E_() {
    match('+');
    T();
    E_();

}


void match(char ch) {
    if (currentToken == ch) {
        printf("%c", ch);
        currentToken = yylex();
    }
    else {
        printf("\nSYNTAX ERROR");
    }
}