#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pointersorter.h"

Node *root = NULL;

Node* create_node(char *word) {
	Node *node;
	node = malloc(sizeof(Node));
	node -> key = word;
	node -> left = NULL;
	node -> right = NULL;
	return node;
}

void insert_word(char *word) {
	if (root == NULL) {
		root = create_node(word);
		return;
	}
	else {
		Node *inserted;
		inserted = create_node(word);
		Node *pointer;
		pointer = root;
		Node *parent;
		while (pointer != NULL) {
			parent = pointer;
			int comparison = strcmp(inserted -> key, pointer -> key);
			if (comparison < 0) {
				pointer = pointer -> left;
				if (pointer == NULL) {
					parent -> left = inserted;
					return;
				}
			}
			else {
				pointer = pointer -> right;
				if (pointer == NULL) {
					parent -> right = inserted;
					return;
				}
			}
		}
	}
}

void in_order_traversal(Node *rt) {
	if (rt != NULL) {
		in_order_traversal(rt -> left);
		printf("%s\n", rt -> key);
		in_order_traversal(rt -> right);
	}
}

void destroy_tree(Node *rt) {
	if (rt != NULL) {
		destroy_tree(rt -> left);
		destroy_tree(rt -> right);
		free(rt -> key);
		free(rt);
	}
}

char* get_substring(char *string, int start, int end) {
	char *substring;
	int difference = end - start;
	substring = malloc((difference + 1) * sizeof(char));
	int i;
	for (i = start; i < end; i++) {
		substring[i - start] = string[i];
	}
	substring[difference] = '\0';
	return substring;
}

void parse_input(char *input) {
	int length = strlen(input);
	if (length == 0) {
		return;
	}
	else if (length == 1) {
		if (isalpha(input[0])) {
			insert_word(input);
			return;
		}
	}
	int non_letter_index = 0;
	int start = 0;
	if (!isalpha(input[0])) {
		non_letter_index++;
		start++;
	}
	int i;
	for (i = start; i < length; i++) {
		char c = input[i];
		/*checks if it's not a letter*/
		if (!isalpha(c)) {
			char *segment;
			if (non_letter_index == 0) {
				segment = get_substring(input, 0, i);
			}
			else if (non_letter_index == 1) {
				segment = get_substring(input, 1, i);
			}
			else {
				segment = get_substring(input, non_letter_index + 1, i);
			}
			non_letter_index = i;
			if (strlen(segment) > 0) {
				insert_word(segment);
			}
		}
			
	}
	/*adds the last string after the last non-letter character*/
	if (non_letter_index != length - 1) {
		char *last_word;
		int last_starting_index = non_letter_index;
		if (last_starting_index != 1) {
			last_starting_index++;
		}
		last_word = get_substring(input, last_starting_index, length);
		if (strlen(last_word) > 0) {
			insert_word(last_word);
		}
	}
}

/**
 * Main function
 * @param  argc [number of command line arguments + 1]
 * @param  argv [array of arguments]
 * @return      [int]
 */
int main(int argc, char *argv[]) {
	/*checking for valid number of arguments*/
	if (argc != 2) {
		fprintf(stderr, "ERROR: Invalid number of arguments; only 1 argument taken\n");
	}
	else {
		parse_input(argv[1]);
		in_order_traversal(root);
		destroy_tree(root);
	}
	return 0;
}
