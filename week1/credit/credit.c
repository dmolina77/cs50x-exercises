#include <cs50.h>
#include <stdio.h>

int length(long n);
int main()
{
    long number = 0;
    // Validar número
    do
    {
        number = get_long("Number: ");
    }
    while (number < 1);
    // Variables

    long aux = number;
    int number_length = length(number);
    int number_list[number_length];
    int sum_evens = 0;
    int sum_odds = 0;
    int sum_total = 0;
    int even = 0;
    int odd = 0;

    // Agregar cada digito del numero al array
    // 1234... => [1,2,3,4,...]
    for (int i = 0; i < number_length; i++)
    {
        number_list[i] = aux % 10;
        aux /= 10;
    }
    // Verificar array
    // Importante: array invierte el número
    // Numero: 1234... => [... 4,3,2,1]
    // for (int i = 0; i < number_length; i++)
    // {
    //     printf("%i ", number_list[i]);
    // }
    // printf("\n");

    // Algoritmo de validación del número
    for (int i = 0; i < number_length; i++)
    {
        // i empieza en 0, por lo tanto
        // cuando i es par, la posición en array es impar, y viceversa
        // en array [1,2,3,4], los array con posición par (2 y 4) están en i con valor impar (1,3)
        if (i % 2 != 0)
        {
            // num_list[impar]
            even = number_list[i] * 2;
            if (even > 9)
            {
                sum_evens += even / 10;
                sum_evens += even % 10;
            }
            else
            {
                sum_evens += even;
            }
        }
        else
        {
            // num_list[pares]  desde fin al principio
            odd = number_list[i];
            sum_odds += number_list[i];
        }
    }
    sum_total = sum_odds + sum_evens;
    bool is_valid = (sum_total % 10) == 0;
    int digit1 = number_list[number_length - 1];
    int first_two_digits = (digit1 * 10) + number_list[number_length - 2];

    // AMEX
    if (((number_length == 13) || (number_length == 16)) && (digit1 == 4) && (is_valid))
    {
        printf("VISA\n");
    }
    else if ((number_length == 16) && ((first_two_digits > 50) && first_two_digits < 56) &&
             (is_valid))
    {
        printf("MASTERCARD\n");
    }
    else if ((number_length == 15) && ((first_two_digits == 34) || first_two_digits == 37) &&
             (is_valid))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// Obtener cantidad de digitos del numero para crear lista de misma longitud
int length(long n)
{
    long aux = n;
    int l = 0;
    while (aux != 0)
    {
        aux /= 10;
        l++;
    }
    return l;
}
