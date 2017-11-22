#include <cs50.h>
#include <stdio.h>
#include <string.h>

int getIntFromLetter(char l)
{
    if (l >= 'A' && l <= 'Z')
        return l - 65;
    else if (l >= 'a' && l <= 'z')
        return l - 97;
    return l;
}

char getUpperLetterFromInt(int i)
{
    if (i >= 26)
        i = i - 26;
    return i + 65;
}

char getLowerLetterFromInt(int i)
{
    if (i >= 26)
        i = i - 26;
    return i + 97;
}

bool isLetter(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return true;
    else
        return false;
}

bool isUpperCase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

bool isLowerCase(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    return false;
}

char *get_ciphertext(char *k, char *src)
{
    char *dest = (char *)malloc(strlen(src));
    int i = 0;
    int x = 0;

    while (src[i] != '\0')
    {
        if (k[x] == '\0')
            x = 0;
        if (isLetter(src[i]) && isUpperCase(src[i]))
            dest[i] = getUpperLetterFromInt(getIntFromLetter(src[i]) + getIntFromLetter(k[x++]));
        else if (isLetter(src[i]) && isLowerCase(src[i]))
            dest[i] = getLowerLetterFromInt(getIntFromLetter(src[i]) + getIntFromLetter(k[x++]));
        else
            dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int main(int ac, char **av)
{
    char *str;
    char *cipher;

    if (ac != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    printf("plaintext: ");
    str = get_string();
    cipher = get_ciphertext(av[1], str);
    printf("ciphertext: %s\n", cipher);
    free(cipher);
    return 0;
}
