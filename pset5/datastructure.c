#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node
{
    int n;
    struct node *next;
} node;

typedef struct queue
{
    int front;
    int *numbers;
    int size;
} queue;

typedef struct node
{
    int n;
    struct node *right;
    struct node *left;
} node;

typedef struct node
{
    bool isWord;
    struct node *children[27];
} node;
node *root;

int main(int ac, char **av)
{
    return 0;
}

// linked list + :
// malloc-> memory use, adaptable size
//
// arrays + : sort, search-> faster
//
// hashtable :
// adaptable size,
// To use when data already sorted
//
// Tries
//

// Stack + : FILO, push() / pop()
//
// Queue + : FIFO, enqueue() / dequeue()

// Binary trees allows binary search and sort in linked list
