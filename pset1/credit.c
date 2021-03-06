#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool isLuhnAlgVerified(char *nb)
{
    char c[20][20];
    char tmp[10];
    int total = 0;
    int subtotal = 0;
    int i = 0;
    int x = 0;
    while (i < strlen(nb))
    {
        if (i % 2 != 0)
        {
            sprintf(tmp, "%i", ((nb[i] - '0') * 2));
            if (atoi(tmp) > 9)
            {
                strcpy(c[x], "1");
                x++;
            }
            sprintf(tmp, "%i", (atoi(tmp) % 10));
            strcpy(c[x], tmp);
            x++;
        }
        else
            total = total + (nb[i] - '0');
        i++;
    }
    strcpy(c[x], "\0");
    i = 0;
    while (strcmp(c[i], "\0") != 0)
    {
        subtotal = subtotal + atoi(c[i]);
        i++;
    }
    if ((total + subtotal) % 10 == 0)
        return true;
    return false;
}

bool isValid(char *nb)
{
    int len = strlen(nb);
    if ((len == 15 || len == 16 || len == 13) &&
        isLuhnAlgVerified(nb))
        return true;
    return false;
}

bool isMastercard(char *nb)
{
    int len = strlen(nb);
    if (len == 16 && nb[0] == '5' &&
        (nb[1] == '1' || nb[1] == '2' || nb[1] == '3' || nb[1] == '4' || nb[1] == '5'))
        return true;
    return false;
}

bool isVisa(char *nb)
{
    int len = strlen(nb);
    if ((len != 16 && len != 13) && nb[0] != '4')
        return false;
    return true;
}

bool isAmex(char *nb)
{
    int len = strlen(nb);
    if (len == 15 && nb[0] == '3' &&
        (nb[1] == '4' || nb[1] == '7'))
        return true;
    return false;
}

bool checkCard(char *nb)
{
    if (isMastercard(nb))
    {
        printf("MASTERCARD\n");
        return true;
    }
    else if (isVisa(nb))
    {
        printf("VISA\n");
        return true;
    }
    else if (isAmex(nb))
    {
        printf("AMEX\n");
        return true;
    }
    return false;
}

int main(void)
{
    char nb[100] = "";
    long long number = 0;

    printf("Number : ");
    number = get_long_long();
    sprintf(nb, "%lld", number);

    if (!isValid(nb))
        printf("INVALID\n");
    else
        checkCard(nb);
    return 0;
}