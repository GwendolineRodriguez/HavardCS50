#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int initLetterTab(char *tab)
{
    int i = 0;
    int b = 0;
    while (i < 52)
    {
        if (i <= 25)
            tab[i] = 65 + i;
        else
        {
            tab[i] = 97 + b;
            b++;
        }
        i++;
    }
    tab[i] = '\0';
    return 0;
}

int getMaxLen(int a)
{
    if (a < 52)
        return 1;
    else if (a < (52 * 52))
        return 2;
    else if (a < (52 * 52 * 52))
        return 3;
    return 4;
}

int genString(char *tab, char *str, int a, int c)
{
    int i = 0;
    while ((i < 52) && (c < getMaxLen(a)))
    {
        str[c] = tab[(a + i++) % 52];
        if (i == 52)
            c++;
        genString(tab, str, a, c + 1);
    }
    return 0;
}

bool decode(char *hash, char *tab)
{
    char *tmp = (char *)malloc(4);
    int attempt = 0;
    // while (attempt < 520)
    while (attempt < (52 * 52))
    {
        // generateStr(tmp, attempt, tab);
        genString(tab, tmp, attempt, 0);
        tmp[getMaxLen(attempt)] = '\0';
        printf("%s\n", tmp);

        // if (strcmp(tmp, crypt(tmp, "50")) == 0)
        // {
        // printf("%s\n",tmp);
        // free(tmp);
        // return true;
        // }
        attempt++;
    }
    free(tmp);
    return false;
}

int main(int ac, char **av)
{
    char *tab = (char *)malloc(52);
    if (ac != 2)
    {
        printf("Usage: ./crack hash\n");
        free(tab);
        return 2;
    }
    initLetterTab(tab);
    decode(av[1], tab);
    free(tab);
    return 0;
}