#ifndef _TRIE_H_
#define _TRIE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 26

typedef struct Trie_Node root;
struct Trie_Node *EmptyTrie(void);
void insert(struct Trie_Node *root, char *word);
int checkChild(struct Trie_Node *root);
void printTrie_defult(struct Trie_Node *root, char *word, int lev);
void printTrie_parameter(struct Trie_Node *root, char *word, int lev);
void free_trie (struct Trie_Node *del);




#endif