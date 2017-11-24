/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"
#include <stdio.h>
#include <string.h>

const int MAXLEN = 65536;

int shrinkTable(int values[], int begin, int end)
{
    int tmp[end];
    int i = 0;
    memcpy(tmp, values, end * sizeof(int));
    while (begin <= end)
    {
        values[i] = tmp[begin];
        i++;
        begin++;
    }
    return 0;
}

bool search(int value, int values[], int n)
{
    int middle = 1;

    while (n > 0)
    {
        middle = values[n / 2];
        if (value == middle)
            return true;
        else if (value > middle)
        {
            shrinkTable(values, (n / 2), n);
            if (search(value, values, (n / 2) + 1))
                return true;
        }
        else if (value < middle)
        {
            shrinkTable(values, 0, (n / 2));
            if (search(value, values, (n / 2)))
                return true;
        }
        n = 0;
    }
    return false;
}

int initArray(int tmp[])
{
    int i = 0;
    while (i < MAXLEN)
    {
        tmp[i++] = 0;
    }
    return 0;
}

void fillArray(int tmp[], int values[], int n)
{
    int i = 0;
    while (i < n)
    {
        tmp[values[i]]++;
        i++;
    }
}

void showArray(int tab[])
{
    int i = 0;
    while (i < MAXLEN)
    {
        printf("%i\n", tab[i]);
        i++;
    }
}

void sort(int values[], int n)
{
    int i = 0;
    int c = 0;
    int tmp[MAXLEN];
    initArray(tmp);
    fillArray(tmp, values, n);
    // showArray(tmp);
    while (i < MAXLEN)
    {
        while (tmp[i] != 0)
        {
            values[c++] = i;
            tmp[i]--;
        }
        i++;
    }
    // showArray(values);
    return;
}
