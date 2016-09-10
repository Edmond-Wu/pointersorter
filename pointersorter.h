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
