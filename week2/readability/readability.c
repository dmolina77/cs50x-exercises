#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt user text
    string text = get_string("Text: ");

    // Count n letters, words and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    double L = ((double) letters/ (double) words) * 100;
    double S = ((double) sentences/(double) words) * 100;

    // Compute Coleman-Liau index
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

    // Print grade level
    if (index >= 16) {
        printf("Grade 16+\n");
    } else if (index < 1) {
        printf("Before Grade 1\n");
    } else {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text) {
    int count = 0;
    for (int i = 0; i < strlen(text) ; i++) {
        if (isalpha(text[i])) {
            count++;
        }
    }
    return count;
}

int count_words(string text) {
    int count = 1;
    for (int i = 0; i<strlen(text); i++) {
        if (isspace(text[i])) {
            count++;
        }
    }
    return count;
}

int count_sentences(string text) {
    int count = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == 46 || text[i] == 63 || text[i] == 33 ) {
            count++;
        }
    }
    return count;
}
