#include <stdio.h>
#include <string.h>

int estPalindrome(const char *chaine) {
    int length = strlen(chaine);
    
    // Check for empty string
    if (length == 0) {
        printf("La chaîne est vide.\n");
        return 0; // Not a palindrome
    }

    // Remove newline character if present
    if (chaine[length - 1] == '\n') {
        length--;
    }

    // Check for palindrome
    for (int i = 0; i < length / 2; i++) {
        if (chaine[i] != chaine[length - 1 - i]) {
            return 0; // Not a palindrome
        }
    }
    
    return 1; // Is a palindrome
}

int main() {
    char chaine[100];

    printf("Entrez une chaîne de caractères : ");
    fgets(chaine, sizeof(chaine), stdin);

    int isPalindrome = estPalindrome(chaine);

    if (isPalindrome) {
        printf("%s est un palindrome.\n", chaine);
    } else {
        printf("\"%s\" n'est pas un palindrome.\n", chaine);
    }

    return 0;
}