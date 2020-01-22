#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//#define SIZE 26

// struct Trie_Node
// {
//     struct Trie_Node *child[SIZE];
//     char let;
//     int count;
//     bool End_Word;
// };

// struct Trie_Node *EmptyTrie(void)
// {
//     struct Trie_Node *kNode = NULL;
//     kNode = (struct Trie_Node *)malloc(sizeof(struct Trie_Node));
//     kNode->End_Word = false;
//     kNode->count = 0;
//     kNode->let = '\0';
//     for (int i = 0; i < SIZE; i++)
//     {
//         kNode->child[i] = NULL;
//     }
//     return kNode;
// }

// void insert(struct Trie_Node *root, char *word)
// {
//     //int key = 'a';
//     int index;
//     int lev;
//     int len = strlen(word);
//     struct Trie_Node *temp = root;

//     for (lev = 0; lev < len; lev++)
//     {
//         index = *word - 'a';
//         if (temp->child[index] == NULL)
//         {
//             temp->child[index] = EmptyTrie();
//         }
//         temp = temp->child[index];
//         temp->let = *word;
//         word++;
//     }
//     temp->End_Word = true;
//     temp->count++;
// }
// int checkChild(struct Trie_Node *root)
// {
//     int result = 0;
//     for (int i = 0; i < SIZE; i++)
//     {
//         if (root->child[i])
//         {
//             result++;
//             return result;
//         }
//     }
//     return result;
// }
// void printTrie_defult(struct Trie_Node *root, char *word, int lev)
// {
//     if (root == NULL)
//     {
//         printf("The trie is empty!");
//         return;
//     }
//     if (root->End_Word == true)
//     {
//         word[lev]=0;
//      printf("\n%s \n ", word);
//     }
//     for (int p = 0; p < 26; p++)
//     {

//         if (root->child[p] != NULL)
//         {
//             word[lev] = 97 + p;
//             struct Trie_Node *temp = root->child[p];
//              lev++;
//             printTrie_defult(temp, word, lev);
//             lev--;

//         }
//     }
// }
// void printTrie_parameter(struct Trie_Node *root, char *word, int lev)
// {
//     if (root == NULL)
//     {
//         printf("The trie is empty!");
//         return;
//     }
//     if (root->End_Word == true)
//     {
//         word[lev]=0;
//      printf("\n%s \n ", word);
//     }
//     for (int p = 25; p >=0; p--)
//     {

//         if (root->child[p] != NULL)
//         {
//             word[lev] = 97 + p;
//             struct Trie_Node *temp = root->child[p];
//             lev++;
//             printTrie_parameter(temp, word, lev);
//             lev--;

//         }
//     }
// }
// void free_trie (struct Trie_Node *del)
// {
// for (int i = 0; i < SIZE; i++)
// {
//      if(del -> child[i]!=NULL)
//      {
//         free_trie (del -> child[i]);
//      }
// }
//      free(del);
// }

int main(int argc, char *argv[])
{
    struct Trie_Node *trie2 = EmptyTrie();
    char letter = getchar();
    int index = 0;
    char *curr_word = (char *)malloc(sizeof(char));
    curr_word[index] = '\0';
    index++;

    while (letter != EOF)
    {
        while ((letter != EOF && letter != '\t' && letter != '\n' && letter != ' ' )&&
        ( ( letter>='a' && letter<='z') || (letter>='A' && letter<='Z') ) )
        {

            curr_word = realloc(curr_word, (index + 1) * sizeof(char));
            curr_word[index - 1] = letter;
            curr_word[index] = '\0';
            index++;
            // printf("%c",letter);
            letter = getchar();
        }
        int len = strlen(curr_word);
        for (int i = 0; i < len; i++)
        {
            curr_word[i] = tolower(curr_word[i]);
        }
        if (len != 0 && curr_word[index - 1] != ' ' && curr_word[index - 1] != '\n')
        {
            insert(trie2, curr_word);
        }

        free(curr_word);
        letter = getchar();
        if (letter == EOF)
        {
            break;
        }
        else
        {
            index = 1;
            curr_word = (char *)malloc(sizeof(char));
            curr_word[0] = letter;
        }
    }

    char *temp_word = (char *)malloc(sizeof(char));
    int lev2 = 0;
    int lev3 = 0;
    if (argc == 1)
    {
        printf("defult print: \n");
        printTrie_defult(trie2, temp_word, lev3);
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "r") == 0)
        {
            printf("\nparameter print: \n");
            printTrie_parameter(trie2, temp_word, lev2);
        }
    }
    free_trie(trie2);
    //free(trie2);
    free(temp_word);

    return 0;
}