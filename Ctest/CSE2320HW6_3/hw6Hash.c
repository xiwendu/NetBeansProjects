//Hi Sadia,
//This is the hash function I got. It use the linked list way to create the hash 
//table.
//Hope I can get some partial credit on the hashTable part.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define SPELL_CHECKER
#ifdef SPELL_CHECKER
#define Size 10000
#define WORD_SIZE 100

typedef struct Chain
{
    char word[100];
    struct Chain *next;
}chainElements;

typedef struct Table
{
    int total_elements;
    chainElements *baseElement;
}tablelements;

typedef struct Hashtable
{
    int size;
    tablelements *base;
}hashtable;

hashtable* createHashTable(int size);

int getKey(char *string);
bool searchWord(hashtable *phashtable, char *str);

int main(void)
{
    char ch;
    printf("Which word you want to search? ");
    scanf("%c", &ch);
    FILE *fp1;
    char Engish[WORD_SIZE];
    char c;
    char *searchword = &ch;
    bool ispresent;
    hashtable *phashtable = createHashTable(Size);

    fp1 = fopen("Spanish.txt", "r");

    do
    {
        c = fscanf(fp1, "%s", Engish);
    } while (c != EOF);
    ispresent = searchWord(phashtable, searchword);
    printf("The word is present %d \n", ispresent);
    fclose(fp1);
    return 0;
}
bool searchWord(hashtable *HashTable, char *str)
{

    if (HashTable == NULL || str == NULL)
    {
        fprintf(stderr, " Invalid pointer\n");
        return false;
    }
    int hashindex = getKey(str);
    if (hashindex > Size)
    {
        fprintf(stderr, "Invalid hashIndex\n");
        return false;
    }
    /* point to first element of the chained linked list */
    chainElements *pchainelements = HashTable->base[hashindex].baseElement;
    while (pchainelements != NULL)
    {
        /* compares the given word with present in node */
        if (!strcmp(pchainelements->word, str))
        {
            return true;
        }
        pchainelements = pchainelements->next;
    }
    return false;
}

int getKey(char *string)
{
    unsigned int key = 0;
    char *pstring = string;
    while (*pstring != '\0')
    {
        key += *pstring * 32;
        pstring++;
    }
    key = key % Size;
    return key;
} 

hashtable* createHashTable(int size)
{
    int i;
    if (size < 1 || size > Size)
    {
        fprintf(stderr, " invalid size\n");
        exit(1);
    }
    hashtable *phashtable = (hashtable *)malloc(sizeof(hashtable));
    if (phashtable == NULL)
    {
        fprintf(stderr, "memory allocation failed\n");
    }
    phashtable->size = size;
    if (size > 0)
    {
        phashtable->base = (tablelements *)malloc(sizeof(tablelements) * phashtable->size);

        if (phashtable->base == NULL)
        {
            fprintf(stderr, "memory allocation failed\n");
        }
        for (i = 0; i < size; i++)
        {
            phashtable->base[i].baseElement = NULL;
        }
    }
    return phashtable;
}

#endif