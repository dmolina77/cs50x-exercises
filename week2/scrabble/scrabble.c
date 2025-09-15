#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int score(string s);

int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    int score1 = score(player1);
    int score2 = score(player2);
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int score(string s)
{
    int count = 0;
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' ||
            tolower(s[i]) == 'o' || tolower(s[i]) == 'u' || tolower(s[i]) == 'l' ||
            tolower(s[i]) == 'n' || tolower(s[i]) == 'r' || tolower(s[i]) == 's' ||
            tolower(s[i]) == 't')
        {
            count += 1;
        }
        else if (tolower(s[i]) == 'd' || tolower(s[i]) == 'g')
        {
            count += 2;
        }
        else if (tolower(s[i]) == 'b' || tolower(s[i]) == 'c' || tolower(s[i]) == 'm' ||
                 tolower(s[i]) == 'p')
        {
            count += 3;
        }
        else if (tolower(s[i]) == 'f' || tolower(s[i]) == 'h' || tolower(s[i]) == 'v' ||
                 tolower(s[i]) == 'w' || tolower(s[i]) == 'y')
        {
            count += 4;
        }
        else if (tolower(s[i]) == 'k')
        {
            count += 5;
        }
        else if (tolower(s[i]) == 'j' || tolower(s[i]) == 'x')
        {
            count += 8;
        }
        else if (tolower(s[i]) == 'q' || tolower(s[i]) == 'z')
        {
            count += 10;
        }
    }
    return count;
}
