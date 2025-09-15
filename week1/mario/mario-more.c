#include <cs50.h>
#include <stdio.h>

int main()
{
    // Request height
    int height = 0;

    // Validate height (1 < height < 9 )
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 9);

    // For each row
    for (int i = 0; i < height; i++)
    {
        // For left columns
        for (int j = 1; j < height - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        // Two-space gap
        printf("  ");

        // For right columns
        for (int h = 0; h <= i; h++)
        {
            printf("#");
        }
        // Next line
        printf("\n");
    }
}
