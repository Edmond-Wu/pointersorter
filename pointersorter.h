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
 * Method for creating a tree node
 * @param  word [word to be stored in node]
 * @return      [Node]
 */
Node* create_node(char *word);
