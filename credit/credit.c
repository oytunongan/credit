#include <cs50.h>
#include <stdio.h>

long calculate_credit(long number);

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while ((number == 0) || ((number * 1) != number));

    long sum = calculate_credit(number);

    // printf("%ld\n", sum);
}

long calculate_credit(long number)
{
    int count = 0;
    long digit = number;
    int k, l;
    int sum = 0;
    do
    {
        count++;
        digit /= 10;
    }
    while (digit != 0);
    for (k = 1; k <= count; k++)
    {
        if ((k % 2) == 0)
        {
            if ((number % 10) < 5)
            {
                sum += ((number % 10) * 2);
            }
            else
            {
                sum += ((((number % 10) * 2) % 10) + 1);
            }
        }
        else
        {
            sum += number % 10;
        }
        if (k == (count - 2))
        {
            l = number / 10;
        }
        number /= 10;
    }
    if (((sum % 10) == 0) &&
        ((l == 34) || (l == 37) || ((l / 10) == 4) || (l == 51) || (l == 52) || (l == 53) || (l == 54) || (l == 55)) &&
        ((count < 17) && (count > 12)))
    {
        switch (l / 10)
        {
            case 3:
                printf("AMEX\n");
                break;
            case 4:
                printf("VISA\n");
                break;
            case 5:
                printf("MASTERCARD\n");
                break;
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return sum;
}
