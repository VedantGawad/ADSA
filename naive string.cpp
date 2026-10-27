#include <stdio.h>
#include <string.h>
void naiveSearch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;
    int found = 0;  // flag to track matches
    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            printf("Pattern found at position: %d\n", i);
            found = 1;
        }
    }
    if (found==0) {
        printf("No match found!\n");
    }
}
int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    gets(text);  // (unsafe, but okay for simple lab programs)
    printf("Enter the pattern: ");
    gets(pattern);
    naiveSearch(text, pattern);
    return 0;
}
