#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {"int", "float", "if", "else", "return", "while"};
int isKeyword(char *word) {
    for (int i = 0; i < 6; i++)
        if (strcmp(word, keywords[i]) == 0) return 1;
    return 0;
}
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || 
           ch == '=' || ch == '>' || ch == '<';
}

int main() {
    FILE *f = fopen("input_code.c", "r");
    if (!f) {
        printf("File not found.\n");
        return 1;
    }

    char ch, word[50];
    int i = 0;

    printf("Lexical Analysis Output:\n\n");

    while ((ch = fgetc(f)) != EOF) {
        if (isspace(ch)) continue;

        if (isalpha(ch)) {
            word[i++] = ch;
            while (isalnum(ch = fgetc(f)))
                word[i++] = ch;
            word[i] = '\0'; i = 0;
            ungetc(ch, f);
            printf("%-10s --> %s\n", word, isKeyword(word) ? "Keyword" : "Identifier");
        }
        else if (isOperator(ch)) {
            printf("%c         --> Operator\n", ch);
        }
    }

    fclose(f);
    return 0;
}

int a = 5;
if (a > 0) {
    return a;
}
