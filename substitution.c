#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

/**
 * 
 * by Daniel Andrew
 * 
 * substitution.c
 * 
 * command: /substitution <reference_key>
 * input:
 *  plaintext: <text_to_be_ciphered>
 * output:
 *  cipheredtext: <ciphered_text>
 * 
 */

bool checkKey(string key);
void substitute(string key);

string old_key = "abcdefghijklmnopqrstuvwxyz";

int main(int n, string args[]) {

    if (n == 2) {
        if (checkKey(args[1]) == true) {
            substitute(args[1]);
        } else {
            printf("Invalid key!\n");
            printf("Usage: /substitution <reference_key>")
            return 0;
        }
    } else {
        printf("Argumentation fault!\n");
        return 0;
    }
}

void substitute(string key) {
    string text = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (islower(text[i])) {
                for (int j = 0; j < strlen(old_key); j++) {
                    if (text[i] == tolower(old_key[j])) {
                        printf("%c", tolower(key[j]));
                    }
                }
            } else if (isupper(text[i])) {
                for (int j = 0; j < strlen(old_key); j++) {
                    if (text[i] == toupper(old_key[j])) {
                        printf("%c", toupper(key[j]));
                    }
                }
            }
        } else {
            printf("%c", text[i]);
        }
    }

    printf("\n");
}

bool checkKey(string key) {
    int count = 0;

    for (int i = 0; i < strlen(key); i++) {
        for (int j = i + 1; j < strlen(key); j++) {
            if (toupper(key[j]) == toupper(key[i])) {
                return false;
            } else {
                return true;
            }
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 0; i < 26; i++) {
            if (tolower(key[i]) == c) {
                count++;
                break;
            }
        }
    }

    if (count == 26) {
        return true;
    } else return false;
}