#include <cs50.h>
#include <stdio.h>
#include <string.h>

char *rmSpace(char *str)
{
    int i = 0;
    int x = 0;
    char *new = (char *)malloc(100);
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            while (str[i] == ' ')
                i++;
            new[x] = ' ';
            x++;
        }
        if (str[i] != 0)
            new[x] = str[i];
        i++;
        x++;
    }
    new[x] = '\0';
    return new;
}

char *getInitials(char *name)
{
    char *tmp;
    int i = 0;
    int x = 0;
    tmp = (char *)malloc(strlen(name));
    while (name[i] != '\0')
    {
        tmp[x] = name[i];
        while (name[i] != ' ')
        {
            if (name[i] == '\0')
                break;
            i++;
        }
        x++;
        i++;
    }
    tmp[x] = '\0';
    return tmp;
}

int main()
{
    char *name = (char *)malloc(100);
    char *cleanName = (char *)malloc(100);
    strcpy(name, get_string());
    strcpy(cleanName, rmSpace(name));
    printf("%s\n", getInitials(cleanName));
    return 0;
}