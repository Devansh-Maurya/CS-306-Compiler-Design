#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isOperator(char);
bool isAlphabet(char);
bool isDigit(char);
bool isIdentifier(const char *, int, int);
void printSymbolTableEntry(const char*, int, int, const char*);

int main() {
    char str[100];
    int i = 0, j = 0;

    printf("Enter an string: ");
    scanf("%[^\n]s", str);

    printf("You entered: %s\n\n", str);

    printf("Symbol\t\t\tAddress\t\t\t\t\tType\n\n");

    for (i = 0; str[i] != NULL; ++i) {

        while (str[i] == ' ') {
            i++;
        }
        j = i;

        if (isOperator(str[i])) {
            printSymbolTableEntry(str, i, j, "operator");
            continue;
        } else {
            for (j = i; !isOperator(str[j]) && str[j] != NULL && str[j] != ' '; ++j);
            if(isIdentifier(str, i, j-1))
                printSymbolTableEntry(str, i, j-1, "identifier");
            i=j-1;
        }
    }

    return 0;
}

bool isOperator(char c) {
    return (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '=');
}

void printSymbolTableEntry(const char *ptr, int start, int end, const char *type) {
    for (int i = start; i <= end; ++i) {
        printf("%c", ptr[i]);
    }
    printf("\t\t\t\t%p\t\t\t%s\n", ptr + start, type);
}

bool isIdentifier(const char* token, int start, int end) {

    if (isAlphabet(token[start]) || token[start] == '_') {
        for (int i = start; i <= end ; ++i) {
            if (!isAlphabet(token[i]) && token[i] != '_' && !isDigit(token[i]))
                return false;
        }
        return true;
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

bool isDigit(char c) {
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}