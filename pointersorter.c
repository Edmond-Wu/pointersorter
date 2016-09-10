#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pointersorter.h"


char* lower_case(char *word) {
	char *copy = malloc(1 + strlen(word));
	if (copy) {
		strcpy(copy, word);
	}
	else {
		fprintf(stderr, "Malloc failure");
	}
	for (int i = 0; i < strlen(word); i++) {
		copy[i] = tolower(word[i]);
	}
	return copy;
}

Node* create_node(char *word) {
	Node *n;
	n = malloc(sizeof(Node));
	char *copy = lower_case(word);
	n -> key = copy;
	n -> left = NULL;
	n -> right = NULL;
	return n;
}

/**
 * Main method
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
		int length = strlen(argv[1]);
		Node *node;
		node = create_node(argv[1]);
		printf("Length of input: %d\n", length);
		printf("Word: %s\n", node -> key);
		free(node);
	}
	return 0;
}
