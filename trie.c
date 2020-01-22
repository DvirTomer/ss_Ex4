#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

struct Trie_Node
{
    struct Trie_Node *child[SIZE];
    char let;
    int count;
    bool End_Word;
};

struct Trie_Node *EmptyTrie(void)
{
    struct Trie_Node *kNode = NULL;
    kNode = (struct Trie_Node *)malloc(sizeof(struct Trie_Node));
    kNode->End_Word = false;
    kNode->count = 0;
    kNode->let = '\0';
    for (int i = 0; i < SIZE; i++)
    {
        kNode->child[i] = NULL;
    }
    return kNode;
}

void insert(struct Trie_Node *root, char *word)
{
    //int key = 'a';
    int index;
    int lev;
    int len = strlen(word);
    struct Trie_Node *temp = root;

    for (lev = 0; lev < len; lev++)
    {
        index = *word - 'a';
        if (temp->child[index] == NULL)
        {
            temp->child[index] = EmptyTrie();
        }
        temp = temp->child[index];
        temp->let = *word;
        word++;
    }
    temp->End_Word = true;
    temp->count++;
}
int checkChild(struct Trie_Node *root)
{
    int result = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (root->child[i])
        {
            result++;
            return result;
        }
    }
    return result;
}
void printTrie_defult(struct Trie_Node *root, char *word, int lev)
{
    if (root == NULL)
    {
        printf("The trie is empty!");
        return;
    }
    if (root->End_Word == true)
    {
        word[lev]=0;
     printf("%s %d\n", word, root->count);
    }
    for (int p = 0; p < 26; p++)
    {

        if (root->child[p] != NULL)
        {
            word[lev] = 97 + p;
            struct Trie_Node *temp = root->child[p];
             lev++;
            printTrie_defult(temp, word, lev);
            lev--;
            
        }
    }
}
void printTrie_parameter(struct Trie_Node *root, char *word, int lev)
{
    if (root == NULL)
    {
        printf("The trie is empty!");
        return;
    }
    if (root->End_Word == true)
    {
        word[lev]=0;
     printf("%s %d\n", word, root->count);
    }
    for (int p = 25; p >=0; p--)
    {

        if (root->child[p] != NULL)
        {
            word[lev] = 97 + p;
            struct Trie_Node *temp = root->child[p];
            lev++;
            printTrie_parameter(temp, word, lev);
            lev--;
            
        }
    }
}
void free_trie (struct Trie_Node *del)
{
for (int i = 0; i < SIZE; i++)
{
     if(del -> child[i]!=NULL)
     {
        free_trie (del -> child[i]);
     }
}
     free(del);
}


