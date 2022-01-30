/* 
Project 4: Optimizer
            IRCode Header File
WRITTEN BY: Logan Hoots, Paul Andrews, Brett Silvey

Class: CST-405-TR100A
Isac Artzi
Date: December 12, 2021

    Our IR code generator prints intermediate three address code to a file. This creates a skeleton for future MIPS code during the code generation
assignment. Using the outputted print statements from these functions, we will have a blueprint with which we will design the algorithms that will
generate the actual MIPS assembly. Our code contains functions for initializing the file, closing the file, getting the next open register,
assigning an ID to a register, assigning a binary operation to a register, and assigning a register to an ID.
*/

// include libraries
#include <stdio.h> // Includes the Standard In/Out library
#include <string.h> // Includes the string library
#include <ctype.h> // Includes the ctype library

// ---- Functions to handle IR code emissions ---- //

FILE* IRcode;

//const int registerCount = 32;
int registers[32];

void initIRcodeFile() {
    IRcode = fopen("IRcode.ir", "a");
    if (IRcode == NULL) {
        printf("Error: file does not exist!");
        exit(0);
    }
}

void closeIRcodeFile() { fclose(IRcode); }

int getOpenReg() {
    int i = 1; // Start at 1 because t0 is reserved for the zero value
    while (registers[i] != 0) { 
        if (i > 32) { 
            printf("Error: OUT OF REGISTERS\n"); 
            exit(0); 
        }
        i++; 
    }
    //printf("Returning register %i\n\n\n", i);
    registers[i] = 1; // Mark register as in use
    return i;
}
 
//binary operations
int assignReg(const char id[50]) {
    int reg = getOpenReg();
    char irSnip[50];
    strcat(irSnip, ("T%i = %s\n", reg, id));
    fprintf(IRcode, "T%i = %s\n", reg, id);
    return reg;
}

int emitBinaryOperation(const char* id1, const char* op, const char* id2) { 
    int reg1 = assignReg(id1);
    int reg2 = assignReg(id2);

    int thisReg = getOpenReg();
    fprintf(IRcode, "T%i = T%i %s T%i\n", thisReg, reg1, op, reg2);
    // char temp[50];
    // strcat(temp, ("T%i = T%c %c T%c\n", thisReg, reg1, op, reg2));
    
    // return "T%i = T%i %c T%i\n", thisReg, reg1, op, reg2;
    // return "test";
    return thisReg;
}

//assignment statements
void emitAssignment(const char id1[50], const char id2[50]){
    fprintf(IRcode, "T1 = %s\n", id1);
    fprintf(IRcode, "T2 = %s\n", id2);
    fprintf(IRcode, "T2 = T1\n");
}

void emitConstantIntAssignment (char id1[50], char id2[50]){ fprintf(IRcode, "%s = %s\n", id1, id2); }

void emitWriteId(char * id){
    //fprintf (IRcode, "output %s\n", id); // This is the intent... :)

    // This is what needs to be printed, but must manage temporary variables
    // We hardcode T2 for now, but you must implement a mechanism to tell you which one...
    fprintf (IRcode, "output %s\n", "T2");
}