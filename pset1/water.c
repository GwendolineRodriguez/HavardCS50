#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int minutes = 0;
    bool isValid = false;
    do
    {
        printf("Minutes : ");
        minutes = get_int();
        if (minutes <= 0)
        {
            printf("it's not possible to have a negative value.\n");
        }
        else
        {
            isValid = true;
        }
    } while (!isValid);
    printf("Bottles: %i\n", minutes * 12);
    return true;
}