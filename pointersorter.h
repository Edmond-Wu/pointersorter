#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * Defines a struct for a binary tree node
 */
typedef struct {
	char *key;
	struct Node *left;
	struct Node *right;
} Node;

/**
 * Function for creating a tree node
 * @param  word [word to be stored in node]
 * @return [Node struct with the word as its key]
 */
Node* create_node(char *word);

/**
 * Function to insert a word into the tree structure
 * Inserts in alphabetical ASCII order (capital letters take priority)
 * @param word [word to be inserted]
 */
void insert_word(char *word);

/**
 * Performs an in-order traversal of the tree
 * Prints out the keys of the nodes in alphabetical ASCII order (capital letters take priority)
 * @param rt [root to begin traversal]
 */
void in_order_traversal(Node *rt);

/**
 * Frees the tree structure by performing a post-order traversal
 * @param rt [root to be freed]
 */
void destroy_tree(Node *rt);

/**
 * Function for retrieving a substring from an input string
 * @param start [starting index in input string character array]
 * @param end [ending index]
 * @return [substring of the input determined by start and end indices]
 */
char* get_substring(char *string, int start, int end);

/**
 * Function to parse an input string into words
 * @param input [input to be parsed]
 */
void parse_input(char *input);
