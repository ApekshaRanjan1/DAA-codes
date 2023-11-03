#include <stdio.h>
#include <string.h>

void naiveStringMatching(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[100]; // Assuming a maximum length for the text
    char pattern[100]; // Assuming a maximum length for the pattern

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    printf("Occurrences:\n");
    naiveStringMatching(text, pattern);
    return 0;
}

