#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//defining boolean functionality
typedef enum {true, false} bool;

//struct for a binary tree node
typedef struct Node {
	char *key;
	struct Node *left;
	struct Node *right;
} Node;

/**
 * Function for creating a tree node
 * @param  word [word to be stored in node]
 * @return      [Node]
 */
Node* create_node(char *word);

/**
 * Function to insert a word into the tree structure
 * @param word [word to be inserted]
 */
void insert_word(char *word);

/**
 * Function to parse an input string into words
 * @param input [input to be parsed]
 */
void parse_input(char *input);
