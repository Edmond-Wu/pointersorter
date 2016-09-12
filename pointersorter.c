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
	}
	else {
		Node *pointer;
		pointer = root;
	}
}

char* get_substring(char *string, int start, int end) {
	char *substring;
	substring = malloc((end - start) * sizeof(char));
	for (int i = start; i < end; i++) {
		substring[i - start] = string[i];
	}
	substring[strlen(substring)] = '\0';
	return substring;
}

void parse_input(char *input) {
	int length = strlen(input);
	int non_letter_index = 0;
	printf("Length of input: %d\n", length);
	for (int i = 0; i < length; i++) {
		char c = input[i];
		//checks if it's not a letter
		if (!isalpha(c)) {
			char *segment;
			if (non_letter_index == 0) {
				segment = get_substring(input, 0, i);
			}
			else {
				if (non_letter_index + 1 != length) {
					segment = get_substring(input, non_letter_index + 1, i);
				}
			}
			non_letter_index = i;
			printf("%s\n", segment);
			insert_word(segment);
		}
	}
	//the last string after the last non-letter character
	if (non_letter_index != length - 1) {
		char *last_word;
		int starting_index = non_letter_index;
		if (non_letter_index != 0) {
			starting_index++;
		}
		last_word = get_substring(input, starting_index, length);
		printf("%s\n", last_word);
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
