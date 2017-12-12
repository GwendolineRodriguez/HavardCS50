/**
 * Implements a dictionary's functionality.
 */

#include "dictionary.h"

unsigned int nbWordsLoaded = 0;
node *hashtable[27];

int hash(char *key)
{
    int hash = toupper(key[0]) - 'A';
    // Check for apostrophe
    if (hash == 31)
        hash = 26;
    return hash % 27;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    int n = strlen(word);
    char str[n + 1];

    for (int i = 0; i < n; i++)
    {
        str[i] = word[i];
        str[i] = tolower(str[i]);
    }
    str[n] = '\0';
    int hashkey = hash(str);
    node *cursor = hashtable[hashkey];
    while (cursor != NULL)
    {
        if (strcmp(str, cursor->word) == 0)
            return true;
        cursor = cursor->next;
    }

    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        printf("Could not open dictionary.\n");
        return false;
    }
    node *wordBuffer = malloc(sizeof(node));
    while (true)
    {
        if (fscanf(inptr, "%s", wordBuffer->word) == 1)
        {
            node *new = malloc(sizeof(node));
            new->next = NULL;
            strcpy(new->word, wordBuffer->word);
            int hashKey = hash(wordBuffer->word);
            new->next = hashtable[hashKey];
            hashtable[hashKey] = new;
            nbWordsLoaded++;
        }
        else
            break;
    }

    free(wordBuffer);
    fclose(inptr);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return nbWordsLoaded;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < 27; i++)
    {
        node *cursor = hashtable[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }

    return true;
}
