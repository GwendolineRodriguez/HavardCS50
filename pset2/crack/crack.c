#include <cs50.h>
#include <stdio.h>
#include <string.h>

char *get_ciphertext(char *src) {
    char *str = (char *)malloc(100);

    return str;
}

int main(int ac, char **av)
{
    char *str = (char *)malloc(100);

    if (ac != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 2;
    }
    printf("plaintext: ");
    str = get_string();
    printf("ciphertext: %s\n", get_ciphertext(av[1]));
    return 0;
}