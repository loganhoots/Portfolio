/* 
Project 4:  Optimizer
            Abstract Syntax Tree Implementation
WRITTEN BY: Logan Hoots, Paul Andrews, Brett Silvey

Class: CST-405-TR100A
Isac Artzi
Date: December 12, 2021

	Our abstract syntax tree was made to be as general as possible in order to be as flexible as possible. To achieve this,
we decided to have the main AST struct represent exactly one node. The struct consist of only a label variable, and pointers
to its left-hand and right-hand children. With just these three parameters, we can construct a fully functioning abstract
syntax tree.

    In addition, we have added a way of tracking a node's corresponding register by using the reg variable.
*/

// include libraries
#include <stdio.h> // Includes the Standard In/Out library
#include <string.h> // Includes the string library
#include <ctype.h> // Includes the ctype library

// Creates a struct for the Abstract Syntax Tree
struct AST {
    char nodeType[50]; // Create variable for node label
	struct AST* left;  // Create tree pointer for left child
	struct AST* right; // Create tree pointer for right child
    int reg;
    int val;
};

// Creates a struct Abstract Syntax Tree Function
struct AST *AST_newTree(char nodeType[50], struct AST *left, struct AST *right) { // Sets the Params to nodeType, left, and right
	struct AST *AST_newTree = malloc(sizeof(struct AST)); // Create a blank tree
	strcpy(AST_newTree->nodeType, nodeType); // Sets the new trees nodeType to the passed in nodeType parameter

    AST_newTree->left = left; // Sets the new trees left child to the passed in left tree
	AST_newTree->right = right; // Sets the new trees right child to the passed in right tree

	return AST_newTree; // Returns the newly created tree//
}

void printAST(char prefix[200], struct AST *tree, int isLeft) {
    if (tree != NULL) {
		printf("%s", prefix);
        printf("%s", isLeft ? "├── l: " : "└── r: " );
		printf("%s\n", tree->nodeType);
		
		if (isLeft && tree->right != NULL) {strcat(prefix, "|   "); }
        else if (isLeft && tree->left == NULL) {}
        else { strcat(prefix, "    "); }

        if (!isLeft && tree->right == NULL) {
            while (prefix[strlen(prefix) - 1] == ' ')
                prefix[strlen(prefix) - 1] = '\0';
            prefix[strlen(prefix) - 1] = '\0';
        }
        printAST(prefix, tree->left, 1);
        printAST(prefix, tree->right, 0);
    }
}