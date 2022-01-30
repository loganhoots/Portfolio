/* 
Project 4: Optimizer
            Symbol Table Header File
WRITTEN BY: Logan Hoots, Paul Andrews, Brett Silvey

Class: CST-405-TR100A
Isac Artzi
Date: December 12, 2021

    Our symbol table was upgraded from the given symbol table code. We made changes to allow for the ability to search for an entry, add
an entry, and print the current state of the symbol table. A symbol table entry consists of an index, ID, kind, type, value, number of parameters,
list of parameters, array length, scope label, and pointers to its next and previous entries.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct ST_Row { // Creates the Row struct for the symbol table
    int index;                   // Index while inside table
    char id[50];                 // Item name
    char kind[50];               // Item kind
    char type[50];               // Variable type (if entry is a var)
    char valueChar[50];          // Value of variable (if entry is a char)
    int valueInt;                // Value of variable (if entry is a int)
    int numOfParams;             // Number of parameters in the scope (if entry is a func)
    struct Parameter* params;    // Linked list of function parameters (if entry is a func)
    int arrayLen;                // Stores the size of an array (if entry is an array)

    char scopeLabel[50];         // current scope level
    struct ST_Row* subScope;     // scope below current entry
    struct ST_Row* superScope;   // scope above current entry
    
    struct ST_Row* next;         // Next entry in current scope
    struct ST_Row* prev;         // Previous entry in current scope
};

struct ST_Parameter { // Creates the parameter struct for functions
    struct Parameter* next; // Next Parameter
    struct Parameter* prev; // Previous Parameter

    char type[50]; // Parameter Type
    char id[50]; // Parameter name
};

// Does not check multiple scopes
struct ST_Row* ST_lookUp(struct ST_Row* header_, char id_[50], char scopeLabel_[50]) {
    struct ST_Row* nextRow = malloc(sizeof(struct ST_Row));
    nextRow = header_->next;
    while (nextRow != NULL) {
        if (!strcmp(id_, nextRow->id)) { 
            if (!strcmp(nextRow->scopeLabel, scopeLabel_))
                return nextRow; 
            else if (!strcmp(nextRow->scopeLabel, "Global"))
                return nextRow;
        } // means is in table
        nextRow = nextRow->next;
    }
    return NULL; // means not in table
}

void ST_addRow(struct ST_Row* header_, char id_[50], char kind_[50], char type_[50], int numOfParams_, struct Parameter* params_, int arrayLen_, char scopeLabel_[50]) { 
    // Write part to check if it already exists before adding

    if (ST_lookUp(header_, id_, scopeLabel_) != NULL) { 
        // Throw Error
        printf("Error: Variable %s in scope %s already exists in scope %s!\n", id_, scopeLabel_, ST_lookUp(header_, id_, scopeLabel_)->scopeLabel);
        exit(0);
    }

    struct ST_Row* curr = malloc(sizeof(struct ST_Row));
    curr = header_;
    while (curr->next != NULL) {
        // check curr->next's scope for id_
        if (strcmp(curr->id, id_)) {
            // throw error
            // return
        }
        curr = curr->next;
    }
    //create structs
    struct ST_Row* newRow = malloc(sizeof(struct ST_Row));
    newRow->index = curr->index + 1;
    strcpy(newRow->id, id_);
    strcpy(newRow->kind, kind_);
    strcpy(newRow->type, type_);
    newRow->numOfParams = numOfParams_;
    newRow->params = params_;
    newRow->arrayLen = arrayLen_;  
    strcpy(newRow->scopeLabel, scopeLabel_);
    newRow->valueInt = NULL;
    //newRow->valueChar = "";
    curr->next = newRow;
}

void ST_updateVariableValue(struct ST_Row* header_, char scopeLabel_[50], char id_[50], char valueChar_[50], int valueInt_) {
    struct ST_Row* match = malloc(sizeof(struct ST_Row));
    match = ST_lookUp(header_, id_, scopeLabel_);
    if (match == NULL) {
        // Throw Error
        printf("Error: Variable %s is not initialized in scope %s!\n", id_, scopeLabel_);
        exit(0);
    }

    // printf("\n\n\n%i\n", match->valueInt);
    // match->valueInt = valueInt_;
    // printf("%i\n\n\n\n", match->valueInt);


    if (!strcmp(match->type, "int")) {
        match->valueInt = valueInt_;
    } else if (!strcmp(match->type, "char")) {
        strcpy(match->valueChar, valueChar_);
    }
}

void typeCheck(struct ST_Row* rowA, struct ST_Row* rowB) {
    if (rowB == NULL && !strcmp(rowA->type, "int")) { return; }
    if (!strcmp(rowA->type, rowB->type)) { return; } 
    else {
        printf("\nError: Variables %s and %s do not have matching types!\n", rowA->id, rowB->id);
        exit(0);
    }
}

void printSymTable(struct ST_Row* header_) {
    struct ST_Row* nextRow = malloc(sizeof(struct ST_Row));
    nextRow = header_->next;
    printf("--- Symbol Table ---\n\n");
    printf("itemID    itemName    itemKind    itemType     arrayLength        scope     intVal\n");
	printf("----------------------------------------------------------------------------------\n");
    while (nextRow != NULL) {
		printf("%6d %11s %11s %11s %15d %12s %10i\n", nextRow->index, nextRow->id, nextRow->kind, nextRow->type, nextRow->arrayLen, nextRow->scopeLabel, nextRow->valueInt);
        nextRow = nextRow->next;
    }
	printf("----------------------------------------------------------------------------------\n");
}