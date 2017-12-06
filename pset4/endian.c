#include <stdio.h>
#include <stdlib.h>

typedef struct car
{
    int year;
    char *name;
} car_t;

int main()
{
    car_t *mycar = malloc(sizeof(car_t));
    // equivalent to
    if ((mycar = malloc(sizeof(car_t))) == 0)
        return 1;
    struct car secondcar;
    // Static access // stack // memory allocated in the executable binary // lifetime of the program
    secondcar.year = 2008;
    // Dynamic access // heap // memory extern of the program // lifetime controlable
    (*mycar).year = 2008;
    mycar->year = 1989;
    unsigned int i = 1;
    char *c = (char *)&i;
    char *str;
    if ((str = (char *)malloc(3)) == 0)
        return 0;
    str[0] = 'a';
    str[1] = 'b';
    str[2] = '\0';
    printf("%c\n", *str);
    if (*c)
        printf("Little endian\n");
    else
        printf("Big endian\n");
    free(str);
    return 0;
}
