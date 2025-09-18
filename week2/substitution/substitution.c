#include <cs50.h>   // for getting user input
#include <ctype.h>  // for isupper(), islower(), isalpha()
#include <stdio.h>  // for printf()
#include <string.h> // for strchr(), strcpy()

int main(int argc, string argv[])
{

    // Validate just one argument is passed (key)
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return (1);
        // Validate key length == 26
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return (1);
    }
    else
    {
        // Validate key contains only alphabetic and not duplicates
        char key[26];
        strcpy(key, argv[1]); // Copy key into array to check duplicates
        for (int i = 0, length = strlen(argv[1]); i < length; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Key contains non-alphabetic characters\n");
                return (1);
            }
            key[i] = '?'; // Mark char as visited
            char key_char = argv[1][i];
            // Check if chard already appears in key (duplicates)
            if (strchr(key, key_char) != NULL)
            {
                printf("Duplicate found: %c\n", key_char);
                return (1);
            }
        }
        // All is OK - Ask for plaintext
        string plaintext = get_string("plantext: ");
        int length = strlen(plaintext);
        char ciphertext[length + 1]; // +1 for '\0' at the end
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        // For each char in plaintext, we check if it's in alphabet
        // If true, get its index to use as the key index and assign value in ciphertext.
        // If false, its a non alpha char/ So, we just copy the value into the ciphertext.
        for (int i = 0; i < length; i++)
        {
            strcpy(key, argv[1]);
            char plaintext_char = toupper(plaintext[i]);
            // Find position of char in alphabet
            char *pos = strchr(alphabet, plaintext_char);
            if (pos != NULL)
            {
                // Calculate index of char in alphabet
                int index = pos - alphabet;
                if (isupper(plaintext[i]))
                {
                    ciphertext[i] = toupper(key[index]);
                }
                else if (islower(plaintext[i]))
                {
                    ciphertext[i] = tolower(key[index]);
                }
            }
            else
            {
                // If char != alphabetic, copy it as is
                ciphertext[i] = plaintext[i];
            }
        }
        // Add null char '\0' at the array's end to make it valid string
        ciphertext[length] = '\0';

        // Print ciphertext
        printf("ciphertext: %s\n", ciphertext);
        return (0);
    }
}
