#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int MAXLEN = 1;

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

int genString(char *tab, char *str, int c, char *hash)
{
    int i = 0;
    while (i < 52)
    {
        str[c] = tab[i];
        if ((c + 1) < MAXLEN)
            genString(tab, str, (c + 1), hash);
        else
        {
            str[c + 1] = '\0';
            if (strcmp(hash, crypt(str, "50")) == 0)
            {
                printf("%s\n", str);
                exit(0);
            }
        }
        i++;
    }
    return 1;
}

int main(int ac, char **av)
{
    char *tab = (char *)malloc(52);
    char *tmp = (char *)malloc(4);

    if (ac != 2)
    {
        printf("Usage: ./crack hash\n");
        free(tab);
        return 2;
    }
    initLetterTab(tab);
    while (MAXLEN <= 4)
    {
        genString(tab, tmp, 0, av[1]);
        MAXLEN++;
    }
    free(tab);
    free(tmp);
    return 0;
}