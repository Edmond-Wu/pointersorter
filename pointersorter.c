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

void parse_input(char *input) {
	int length = strlen(input);
	int non_letter_index = 0;
	printf("Length of input: %d\n", length);
	for (int i = 0; i < length; i++) {
		char c = input[i];
		//checks if it's not a letter
		if (!isalpha(c)) {
			int difference = i - non_letter_index;
			char *segment;
			segment = malloc((difference) * sizeof(char));
			if (non_letter_index == 0) {
				for (int j = 0; j < i; j++) {
					segment[j] = input[j];
				}
			}
			else {
				if (non_letter_index + 1 != length) {	
					for (int j = non_letter_index + 1; j < i; j++) {
						segment[j - non_letter_index - 1] = input[j];
					}
				}
			}
			segment[i] = '\0';
			non_letter_index = i;
			printf("%s\n", segment);
			insert_word(segment);
		}
	}
	//the last string after the last non-letter character
	if (non_letter_index != length - 1) {
		char *last_word;
		int starting_index;
		if (non_letter_index == 0) {
			starting_index = non_letter_index;
		}
		else {
			starting_index = non_letter_index + 1;
		}
		last_word = malloc((length - non_letter_index - 1) * sizeof(char));
		for (int x = starting_index; x < length; x++) {
			last_word[x - starting_index] = input[x];
		}
		last_word[strlen(last_word)] = '\0';
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
