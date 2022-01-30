/* 
Project 4: Optimizer
            Symbol Table Header File
WRITTEN BY: Logan Hoots, Paul Andrews, Brett Silvey

Class: CST-405-TR100A
Isac Artzi
Date: 12 December, 2021

    Our code generator is similar to the IR code. The code generator is responsible for accurately creating MIPS Assembly language that
represents the code the user wishes to compile. Currently, our code generation only works for basic arithmatic statements.
*/

//include libraries
#include <stdio.h>  // includes the standard in/out library
#include <string.h> // includes the string library
#include <ctype.h>  // includes the c type library
#include <stdlib.h> // includes the standard library
#include "symbolTable.h"
//#include <irCode.h> // includes the irCode class

// Functions to handle MIPS code generation

FILE* ASMfile;

int dataHeaderExists = 0;

struct mipsReg {
    char name[50];
    int value;
    int isFree;
};

struct mipsReg mipsRegs[32];

// create our mips file - called in the parser
void generateMipsFile() {
    openMipsFile();
    //generateMipsHeader();
    closeMipsCodeFile();
}

// opens the file to write the MIPS code
void openMipsFile() {
    ASMfile = fopen("mipsOutput.asm", "w"); // use a to append to the file
    if (ASMfile == NULL) { // check to see if the file does not exist
        printf("Error opening file!\n"); // print error message
        exit(0); // exit the program
    }
}

//closes the file
void closeMipsCodeFile() {
    fprintf(ASMfile, "\tli $v0, 10\n"); // gets rid of the non execution instruction error
    fprintf(ASMfile, "\tsyscall"); 
    fclose(ASMfile);
}

// create basic mips header and write to ASMfile
void generateMipsHeader() {
    fprintf(ASMfile, ".data\n");
    fprintf(ASMfile, "\tnewline:\t.asciiz\t\"\\n\"\n");
    fprintf(ASMfile, ".text\n");
    fprintf(ASMfile, ".globl main\n");
}

// prints the data labels into the .data section in the mips file
void generateDataDeclarations(char type[50], char id[50], int wordSize) {
    if (!dataHeaderExists) { // checks to see if dat header has been created
        fprintf(ASMfile, ".data\n"); // prints .data to mips file
        dataHeaderExists = 1; // sets dataHeaderExists to true
    }
    if (!strcmp(type, "int")) { fprintf(ASMfile, "\t%s:\t.word\t%i\n", id, wordSize); } // determines if variable is an integer
    else if (!strcmp(type, "char")) { fprintf(ASMfile, "\t%s:\t.byte\t%i\n", id, wordSize); } // determines if the variable is a char
}

// allows us to print new method names into the mips file
void generateNewMethod(char type[50]) { fprintf(ASMfile, "%s:\n", type); }

// generates the code for an assignment of a char 
void getValueFromId(char id[50], char reg[50]) { fprintf(ASMfile, "\tlw %s, %s\n", reg, id); }

// prints the mmips code for method instructions
void generateWriteStatement(char id[50]){
    fprintf(ASMfile, "\tli $v0, 1\n");
    fprintf(ASMfile, "\tli $a0, %s\n", id);
    fprintf(ASMfile, "\tsyscall\n");
    fprintf(ASMfile, "\tli $v0, 4\n"); // necessary mode
    fprintf(ASMfile, "\tla $a0, newline\n"); // inserts newline
    fprintf(ASMfile, "\tsyscall\n");
}