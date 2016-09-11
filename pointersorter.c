#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pointersorter.h"

Node *root = NULL;

//creates a node with a word as the key
Node* create_node(char *word) {
	Node *n;
	n = malloc(sizeof(Node));
	n -> key = word;
	n -> left = NULL;
	n -> right = NULL;
	return n;
}

//inserts a word into the tree
void insert_word(char *word) {
	if (root == NULL) {
		root = create_node(word);
	}
	else {
		Node *pointer;
		pointer = root;
	}
}

//parses an input string into words
void parse_input(char *input) {
	int length = strlen(input);
	printf("Length of input: %d\n", length);
	for (int i = 0; i < length; i++) {
		printf("%c ", input[i]);
	}
	printf("\n");
}

/**
 * Main function
 * @param  argc [number of command line arguments + 1]
 * @param  argv [array of arguments]
 * @return      [int]
 */
int main(int argc, char *argv[]) {
	//checking for valid number of arguments
	if (argc != 2) {
		fprintf(stderr, "ERROR: Invalid number of arguments; only 1 argument taken\n");
	}
	else {
		parse_input(argv[1]);
	}
	return 0;
}
