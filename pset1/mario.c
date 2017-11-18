#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    bool isValid = false;
    char gap[2] = "  ";
    int i = 0;
    int c;
    int space;
    do
    {
        printf("Height : ");
        height = get_int();
        if (height <= 0 || height >= 24)
        {
            printf("Usage : Please enter a value between 0 and 23 included.\n");
        }
        else
        {
            isValid = true;
        }
    } while (!isValid);
    if (height == 0)
        return 0;
    do
    {
        c = 0;
        space = height - i;
        while (c <= i)
        {
            while (space > 0)
            {
                printf(" ");
                space--;
            }
            printf("#");
            c++;
        }
        printf("%s", gap);
        c = 0;
        while (c <= i)
        {
            printf("#");
            c++;
        }
        i++;
        printf("\n");
    } while (i < height);
    return 0;
}
