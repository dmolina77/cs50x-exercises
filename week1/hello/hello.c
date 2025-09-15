// CS50 library to use 'get_string'
#include <cs50.h>
#include <stdio.h>

int main()
{   // Request name
    string name = get_string("What's your name ");
    // Print hello + name
    printf("hello, %s\n", name);
}