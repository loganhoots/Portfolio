%{ /*
Project 4: Optimizer
WRITTEN BY: Logan Hoots, Paul Andrews, Brett Silvey

Class: CST-405-TR100A
Isac Artzi
Date: 12 December, 2021

    We have included a test file called "ISAC_TEST_THIS.cmm" that works within our current grammar rules, semantic checks, code generation, and 
optimization.

    Optimization is the process of adding steps in compilation that will reduce the amount of arithemetic, memory, and other operations that are
needed to be performed in the MIPS generated code. The current forms of optimzation that we have implemented are constant folding and constant
propagation. We have implemented constant folding through updating a variable as needed dependent on the test script from within Bison.
Additionally, this variable is then returned during MIPS generation, this bypasses the need to update the variables, or allocate registers within
MIPS, and therefore is our implemention of constant propagation.
    Currently, we have not implemented grammar rules for while loops, arrays, read statements, break statements, logic operaters "&&" and "||", 
and meaningful error statements. As well we have not implemented all semantic checks including: semantic checks related to arrays, functions,
and return statements, and some type checking. And lastly our code generation only works for basic arithmetic statements.
    During tricky situations it was key to first look for syntax errors that we may have made. A few things that also helped tremendously
throughout this project were using the vs code debugging feature to trace our way back throught the code. This allowed us to pin point what part
of the code was and was not working. To implement thet AST we chose to use nodes and linked lists. This allowed for us to trace back through
created trees and determine if the tree had ended or if there was more to print. To implement the symbol table we have made a linked list of
table entries. To implement IRcode we have made a set of functions.
*/

// Include libraries
#include <stdio.h> // Includes the Standard In/Out library
#include <stdlib.h> // Includes the standard library
#include <string.h> // Includes the string library

// Include headers
#include "AST.h" // Header file for the abstract syntax tree
#include "irCode.h" // Header file for IR code
#include "codeGenerator.h" // Header file for the code generator

// Retreives information from the lexer
extern int yylex(); // Retrieves the yylex function from the lexer
extern int yyparse(); // Retrieves the yyparse function from the lexer
extern FILE* yyin; // Retrieves the yyin file from the lexer

void yyerror(const char* s); // Declares the yyerror function
char currentScope[50]; // global or the name of the function
char prevScope[50]; // Save initial search string

struct ST_Row* ST_header; // Declares a struct symbol table header
%}

// Creates the variable types in the parser
%union { // Union is the collection of semantic values
	int number; // Sets number type to int
	char character; // Sets character type to char
	char* string; // Sets string type to char*
	struct AST* ast; // Sets ast type to struct AST*
}

// List of all the possible tokens
    // Tokens for the built in functions
%token <string> RETURN // Token for "return"
%token <string> READ // Token for "read"
%token <string> WRITE // Token for "write"
%token <string> WRITELN // Token for "writeln"
%token <string> BREAK // Token for "break"
%token <string> IF // Token for "if"
%token <string> ELSE // Token for "else"
%token <string> WHILE // Token for "while"

    // Tokens for the variables
%token <string> TYPE //token for TYPE
%token <string> ID //Token for ID
%token <string> ASCII //Token for ASCII
%token <number> NUMBER //Token for NUMBER

    // Tokens for the symbols
%token <string> SEMICOLON // Token for ";""
%token <string> ASSIGN // Token for "="
%token <string> COMMA // Token for ","
%token <string> APOSTROPHE // Token for "'"
%token <string> PAREN_L // Token for "("
%token <string> PAREN_R // Token for ")"
%token <string> CURLY_L // Token for "{"
%token <string> CURLY_R // Token for "}"
%token <string> BRACK_L // Token for "["
%token <string> BRACK_R // Token for "]"
%token <string> MUL //Token for "*"
%token <string> DIV //Token for "/"
%token <string> ADD //Token for "+"
%token <string> SUB //Token for "-"
%token <string> BOOLOP // Token for "==", "!=", "<", "<=", ">", and ">="
%token <string> LOGICOP // Token for "&&", and "||"
%token <string> UNOP // Token for "++", "--", and "!"

// Invoke the print of the returned ID or number
%printer { fprintf(yyoutput, "%s", $$); } ID; // Returns the ID
%printer { fprintf(yyoutput, "%d", $$); } NUMBER; // Returns the number

// Declare rule names
%type <ast> Program StmtList Stmt Exp MulDivExp AddSubExp MulDivOp AddSubOp Unop VarDecl FuncDecl FuncBlock ParamList ParamTail KeyFunc KeyFuncBlock FuncBlockTail BoolExpList VarTypes

// Set "Program" as initial rule
%start Program

// Beginning of the Rule Declarations
%%

// Grammar rule for the Program
Program:	StmtList { // Rule for replacing the program with the statement list
                printf("--- Abstract Syntax Tree ---\n\n"); // Prints the top of the abstract syntax tree 
                char temp[1000] = ""; // Initializes a blank char
                printAST(temp, $$, 0); // Calls the print AST function
                printf("\n\n"); // Prints empty lines at the end of the table
                printSymTable(ST_header); // Calls the print symbol table function
                closeIRcodeFile(); // Closes the IR code file
                closeMipsCodeFile(); // Closes the mips file
            }
;

// Grammar rules for the Statement List
StmtList:   { $$ = NULL; } // Rule for replacing the program with nothing (if nothing is written)
    | Stmt SEMICOLON StmtList { // Rule for replacing the program with a statement followed by a ";" followed by a statement list
        struct AST* curr = $1; // Init 'curr' node at top of this tree
        while(curr->right != NULL) { curr = curr->right; } // Get lowest node in statement tree
        if ($3 != NULL) { curr->right = $3; } // Sets the right of the statement to the statement list tail
    }
    | FuncDecl StmtList { // Rule for replacing the program with a function declaration followed by a statement list
        struct AST* curr = $1; // Init 'curr' node at top of this tree
        while(curr->right != NULL) { curr = curr->right; } // Get lowest node in tree
        if ($2 != NULL) { curr->right = $2; } // Sets the right of the function declaration to the statement list tail
    }
    | KeyFunc StmtList { // Rule for replacing the program with a key function followed by a statement list
        struct AST* curr = $1; // Init 'curr' node at top of this tree
        while(curr->right != NULL) { curr = curr->right; } // Get lowest node in tree
        if ($2 != NULL) { curr->right = $2; } //sets the right of the key function to the statement list tail
    }
;

// Grammar rules for a statement
Stmt:
    ID ASSIGN Exp { // Rule for recognizing assignment operations
        if (ST_lookUp(ST_header, $1, currentScope) == NULL) { // Check if the variable exists in the table
            printf("\nError: row %s does not exist!\n", $1); // Print error
            exit(0); // Exit the code
        }
        struct AST* curr = malloc(sizeof(struct AST)); // Create a temp AST
        struct ST_Row* rowA = malloc(sizeof(struct ST_Row)); // Create a temp ST row
        struct ST_Row* rowB = malloc(sizeof(struct ST_Row)); // Create a temp ST row
        emitAssignment($1, $3->nodeType);
        printf("\nparser.y | RECOGNIZED RULE: Assignment operation\n\n"); // Prints out that the parser recognized an assignment rule
        struct AST* id_ = malloc(sizeof(struct AST)); // Create tree to represent ID being assigned
        id_ = AST_newTree($1, NULL, NULL); // Set id tree as terminator node
        $$ = AST_newTree($2, id_, $3); // Return a new tree with id as the left child and rest of expression as the right
        
        ST_updateVariableValue(ST_header, currentScope, $1, "", $3->val); // Updates the symbol table
        //generateAssignmentInt($1, $3->val);
    } 
    | Unop // Rule for recognizing unary operations
    | VarDecl // Rule for recognizing variable declarations
;

// Grammar rule for expressions

// ------------------- OPTIMIZATION -------------------------
// ------- CONSTANT FOLDING AND CONSTANT PROPAGATION --------
//
// We perform optimization of expression computation by using constant folding and constant propagation.
// Expressions are simplified within Bison by computing the resulting values and using those values instead
// of the original ones within the MIPS assembly. This allows for faster MIPS execution because the MIPS code
// is no longer required to compute these arithmetic values.

Exp:
    AddSubExp // Goes to an addition or subtration statement
    | MulDivExp AddSubOp Exp { // Goes to a multiply or divide statement followed by addition or substraction
        printf("\nparser.y | RECOGNIZED RULE: Addition/Subtraction operation - LHS: ID"); // Prints that the parser recognized a binary operation
        $$ = AST_newTree($2->nodeType, $1, $3); // Return new tree with id as left child and rest of expression as right
        // Check if addition and then add | check if subtraction then substract
        if(!strcmp($2->nodeType, "+")) { $$->val = $1->val + $3->val; } else if (!strcmp($2->nodeType, "-")) { $$->val = $1->val - $3->val; }
    }
    | AddSubExp AddSubOp Exp { // Goes to an addition or subtraction statement followed by another expression
        printf("\nparser.y | RECOGNIZED RULE: Addition/Subtraction operation - LHS: ID"); // Prints that the parser recognized a binary operation
        $$ = AST_newTree($2->nodeType, $1, $3); // Return new tree with id as left child and rest of expression as right
        // Check if addition and then add | check if subtraction then substract
        if(!strcmp($2->nodeType, "+")) { $$->val = $1->val + $3->val; } else if (!strcmp($2->nodeType, "-")) { $$->val = $1->val - $3->val; }
    }
    | ID { // Rule to recognize ID in expression
        struct ST_Row* match = ST_lookUp(ST_header, $1, currentScope); // Find a matches entry in the table
        if (match == NULL) { // Check if the match is null
            printf("\nError: row %s does not exist!\n", $1); // Prints an error
            exit(0); // Exit the code
        }
        printf("\nparser.y | Expression terminated with ID"); // Prints that the parser recognized an ID termination
        $$ = AST_newTree($1, NULL, NULL); // Create terminator node
        $$->val = match->valueInt; // Update the ID's value
    }
    | NUMBER { // Rule to recognize number in expression
        printf("\nparser.y | Expression terminated with number"); // Prints that the parser recognized a number termination
        char num[50]; // Creates a temporary char pointer
        sprintf(num, "%i", $1);  // Convert number to string
        $$ = AST_newTree(num, NULL, NULL); // Create terminator node
        $$->val = $1; // Set the val of the node to the number
    }
;

// determine if it is an add sub expression
AddSubExp:
    ID AddSubOp AddSubExp { // Rule to recognize ID follow by a binary operator
        struct ST_Row* match = ST_lookUp(ST_header, $1, currentScope); // Find a match in the symbol table
        if (match == NULL) { // Check if the match is null
            printf("\nError: row %s does not exist!\n", $1); // Print error message
            exit(0); // Exit the code
        }
        printf("\nparser.y | RECOGNIZED RULE: Multiplication operation - LHS: ID"); // Prints that the parser recognized a binary operation
        struct AST* id_ = malloc(sizeof(struct AST)); // Creates a blank tree for the id
        id_ = AST_newTree($1, NULL, NULL); // Create terminator node
        $$ = AST_newTree($2->nodeType, id_, $3); // Return new tree with id as left child and rest of expression as right
        if(!strcmp($2->nodeType, "+")) { $$->val = match->valueInt + $3->val; } // Adds if addition
        else if (!strcmp($2->nodeType, "-")) { $$->val = match->valueInt - $3->val; } // Subtracts if subtraction
    }
    | MulDivExp // Go to a multiply or division rule
;

// determine if it is a mul div expression
MulDivExp:
    ID MulDivOp MulDivExp { // Rule to recognize ID follow by a binary operator
        struct ST_Row* match = ST_lookUp(ST_header, $1, currentScope); // Check if a match exists in the table
        if (match == NULL) { // Check if match is null
            printf("\nError: row %s does not exist!\n", $1); // Print an error
            exit(0); // Exit the code
        }
        printf("\nparser.y | RECOGNIZED RULE: Multiplication operation - LHS: ID"); // Prints that the parser recognized a binary operation
        struct AST* id_ = malloc(sizeof(struct AST)); // Creates a blank tree for the id
        id_ = AST_newTree($1, NULL, NULL); // Create terminator node
        $$ = AST_newTree($2->nodeType, id_, $3); // Return new tree with id as left child and rest of expression as right
        if(!strcmp($2->nodeType, "*")) { $$->val = match->valueInt * $3->val; } // Multiply
        else if (!strcmp($2->nodeType, "/")) { $$->val = match->valueInt / $3->val; } // Divide
    }
    | NUMBER MulDivOp MulDivExp { // Rule to recognize ID follow by a binary operator
        printf("\nparser.y | RECOGNIZED RULE: Multiplication operation - LHS: ID"); // Prints that the parser recognized a binary operation
        struct AST* num_ = malloc(sizeof(struct AST)); // Creates a blank tree for the id
        char num[50]; // Creates a temporary char pointer
        sprintf(num, "%i", $1);  // Convert number to string
        num_ = AST_newTree(num, NULL, NULL); // Create terminator node
        $$ = AST_newTree($2->nodeType, num_, $3); // Return new tree with id as left child and rest of expression as right
        // Multiply and Divide appropriately
        if(!strcmp($2->nodeType, "*")) { $$->val = $1 * $3->val; } else if (!strcmp($2->nodeType, "/")) { $$->val = $1 / $3->val; }
    }
    | ID { // Rule to recognize ID in expression
        struct ST_Row* match = ST_lookUp(ST_header, $1, currentScope); // Check for a match in the ST
        if (match == NULL) { // Check if match is null
            printf("\nError: row %s does not exist!\n", $1); // Print an error
            exit(0); // Exit the code
        }
        printf("\nparser.y | Expression terminated with ID"); // Prints that the parser recognized an ID termination
        $$ = AST_newTree($1, NULL, NULL); // Create terminator node
        $$->val = match->valueInt; // Update the value in the symbol table
    }
    | NUMBER { // Rule to recognize number in expression
        printf("\nparser.y | Expression terminated with number"); // Prints that the parser recognized a number termination
        char num[50]; // Creates a temporary char pointer
        sprintf(num, "%i", $1);  // Convert number to string
        $$ = AST_newTree(num, NULL, NULL); // Create terminator node
        $$->val = $1; // Set the val of the node to the number
    }
;

// Rule for a multiplication or division symbol
MulDivOp:
    MUL {
        printf("\nparser.y | Expression terminated with %s\n", $1); // Prints that the parser recognized an ID termination
        $$ = AST_newTree($1, NULL, NULL); // Create terminator node
    }
    | DIV {
        printf("\nparser.y | Expression terminated with %s\n", $1); // Prints that the parser recognized an ID termination
        $$ = AST_newTree($1, NULL, NULL); // Create terminator node
    }
;

// Rule for an addition or subtraction symbol
AddSubOp:
    ADD {
        printf("\nparser.y | Expression terminated with %s\n", $1); // Prints that the parser recognized an ID termination
        $$ = AST_newTree($1, NULL, NULL); // Create terminator node
    }
    | SUB {
        printf("\nparser.y | Expression terminated with %s\n", $1); // Prints that the parser recognized an ID termination
        $$ = AST_newTree($1, NULL, NULL); // Create terminator node
    }
;

// Grammar rules for the Unary Operations
Unop:
    ID UNOP { // Rule to recognize ID followed by unary operator
        if (ST_lookUp(ST_header, $1, ST_header->scopeLabel) == NULL) { // Check if match in ST
            printf("\nError: row %s does not exist!\n", $1); // Print error
            exit(0); // Exit Code
        }
        printf("\nparser.y | RECOGNIZED RULE: Unary operation\n\n"); // prints out a recognized rule
        struct AST* id_ = malloc(sizeof(struct AST)); // Create tree to represent operand id
        id_ = AST_newTree($1, NULL, NULL); // Set id as terminator node
        $$ = AST_newTree($2, NULL, id_); // Return new tree with id as right child
    }
    | UNOP ID { // Rule to recognize a unary operator followed by an id
        if (ST_lookUp(ST_header, $2, ST_header->scopeLabel) == NULL) { // Check if match in ST    
            printf("Error: row %s does not exist!\n", $2); // Prints an error
            exit(0); // Exits the code
        }
        printf("\nparser.y | RECOGNIZED RULE: Unary operation\n\n"); // prints out a recognized rule
        struct AST* id_ = malloc(sizeof(struct AST)); // Create tree to represent operand id
        id_ = AST_newTree($2, NULL, NULL); // Set id as terminator node
        $$ = AST_newTree($1, NULL, id_); // Return new tree with id as right child
    }
;

// Grammar rules for the variable declarations
VarDecl:
    TYPE ID { // Rule to recognize 
        ST_addRow(ST_header, $2, "Variable", $1, 0, NULL, 0, currentScope); // Adds a row to the ST
        printSymTable(ST_header); // Prints updated ST
        printf("\nparser.y | RECOGNIZED RULE: Variable declaration\n\n"); // prints out a recognized rule
        struct AST* id_ = malloc(sizeof(struct AST)); // Create tree to represent id
        struct AST* type_ = malloc(sizeof(struct AST)); // Create tree to represent type
        id_ = AST_newTree($2, NULL, NULL); // Set id as terminator node
        type_ = AST_newTree($1, NULL, NULL); // Set type as terminator node
        $$ = AST_newTree("TYPE", type_, id_); // Return tree with type as left and id as right
    }
;

// Grammar rules for the function declarations
FuncDecl:
    TYPE ID PAREN_L { 
            strcpy(currentScope,$2); // Copies a string for the scope
            ST_addRow(ST_header, $2, "Function", $1, 0, NULL, 0, currentScope); // Adds to the ST
            printSymTable(ST_header); // Prints the updated table
            generateNewMethod($2); // prints our new method in mips file
        } ParamList {
            struct AST* curr = $5; // Init 'curr' node at top of param list
            if (curr->right == NULL) { // Checks if there's a right to the tree
            } else {
                curr = curr->right; // Sets curr to curr's right
                while(curr->right != NULL || strcmp(curr->right->nodeType, "END_OF_PARAMS")) { // Loops appropriately
                    //printf("Adding symTable entry for id %s", curr->right->nodeType);
                    ST_addRow(ST_header, curr->right->nodeType, "Variable", curr->left->nodeType, 0, NULL, 0, currentScope); // Adds to the ST
                    if (curr->right->right->nodeType != NULL) { // Checks if there is another parameter
                        curr = curr->right->right; // Sets curr to the next parameter
                    } else break;
                } // Get lowest node in params
            }
        } PAREN_R CURLY_L FuncBlock CURLY_R { // Rule to recognize type followed by id '(' parameter list ')' followed by'{' with our function followed by '}'
            strcpy(currentScope,"Global"); // Resets the scope
            printf("\nparser.y | RECOGNIZED RULE: Function declaration\n\n"); // prints out a recognized rule
            struct AST* id_ = malloc(sizeof(struct AST)); // create new tree to recognize id
            struct AST* type_ = malloc(sizeof(struct AST)); // create new tree to recognize type
            struct AST* block_ = malloc(sizeof(struct AST)); // create new tree to recognize block
            block_ = AST_newTree("BLOCK", NULL, $9); // Set block as tree with function block as right child
            strcat($1, " FUNCTION "); // Copies a string
            $$ = AST_newTree(strcat($1, $2), $5, block_); // Returns the entire function tree
        }
;

// Grammar rules for the function block
FuncBlock:      { $$ = NULL; } // Returns epsilon to handle empty blocks
    | FuncBlockTail
    | Stmt SEMICOLON FuncBlock { // rule to recognize statement followed by a semicolon followed by a function declaration
        struct AST* curr = $1; // Init 'curr' node at top of this tree
        while(curr->right != NULL) { curr = curr->right; } // Get lowest node in tree
        if ($3 != NULL) { curr->right = $3; } // sets the right of the statement to the function block tail
    }
    | KeyFunc FuncBlock { // rule to recognize key function followed by a function block
        struct AST* curr = $1; // Init 'curr' node at top of this tree
        while(curr->right != NULL) { curr = curr->right; } // Get lowest node in tree
        if ($2 != NULL) { curr->right = $2; } // Sets the right of the Key Function to the Function Block Tail
    }
;

// Grammar Rules of the Function Block Tail
FuncBlockTail:  
    RETURN Exp SEMICOLON { 
        $$ = AST_newTree($1, NULL, $2);
        char temp[50];
        sprintf(temp, "%i", $2->val);
        printf("\n\n\n%s\n\n\n", temp);
        generateWriteStatement(temp); // calls the generateWriteStatement in codeGenerator.h
    }
    | RETURN SEMICOLON { $$ = AST_newTree($1, NULL, NULL); }
    | WRITE Exp SEMICOLON { 
        $$ = AST_newTree($1, NULL, $2); // adds to the tree
        char temp[50]; // creates a temp char pointer
        sprintf(temp, "%i", $2->val); // converts the value to a string
        generateWriteStatement(temp);  // calls the generateWriteStatement in codeGenerator.h
    } 
    | WRITELN Exp SEMICOLON { 
        $$ = AST_newTree($1, NULL, $2); // adds to the tree
        char temp[50]; // creates a temp char pointer
        sprintf(temp, "%i", $2->val); // converts the value to a string
        generateWriteStatement(temp); // calls the generateWriteStatement in codeGenerator.h
    }

// Grammar rules for the Parameter List of a Function
ParamList:              
    { // Rule for the Epsilon case
        struct AST* params_ = malloc(sizeof(struct AST)); // create new tree to recognize params
        struct AST* blank_ = malloc(sizeof(struct AST)); // create new tree to recognize blank
        blank_ = AST_newTree("END_OF_PARAMS", NULL, NULL); // Set blank as terminator node
        $$ = blank_; // Return parameter tree segment
    }
    | TYPE ID ParamTail { // rule to recognize a Type followed by an ID followed by our parameter tail
        struct AST *paramList_, *type_, *id_, *varDecl_; // Create trees for parameters, type, id, and variable declaration
        paramList_ = type_ = id_ = varDecl_ = malloc(sizeof(struct AST)); // see above line
        
        type_ = AST_newTree($1, NULL, NULL); // Set type as terminator node
        id_ = AST_newTree($2, NULL, $3); // Set id as tree with parameter tail as right child
        varDecl_ = AST_newTree("TYPE", type_, id_); // Set variable declaration as tree with type as left child and id as right child
        paramList_ = AST_newTree("PARAMS", NULL, varDecl_); // Sets the right of the parameter list tree to the variable decleration tree
        $$ = paramList_; // Returns the complete Parameter list tree
    }
;

// Grammar rules for the Parameter list's tail
ParamTail:      { $$ = NULL; } // Handles the epsilon case
    | COMMA TYPE ID ParamTail { // Handles multiple parameters
        struct AST* type_ = malloc(sizeof(struct AST)); // create new tree to recognize type
        struct AST* id_ = malloc(sizeof(struct AST)); // create new tree to recognize int
        struct AST* varDecl_ = malloc(sizeof(struct AST)); // create new tree to recognize variable declaration

        type_ = AST_newTree($2, NULL, NULL); // Set type as terminator node
        id_ = AST_newTree($3, NULL, $4); // Set id as tree with parameter tail as right child
        varDecl_ = AST_newTree("TYPE", type_, id_); // Set variable declaration as tree with type as left child and id as right child
        $$ = varDecl_; // Returns the variable declation tree
    }
;

// Grammar rules for the Key Functions
KeyFunc:
    IF PAREN_L BoolExpList PAREN_R CURLY_L {
    } 
    KeyFuncBlock CURLY_R { // Grammar rule
        printf("\nparser.y | RECOGNIZED RULE: If Statement\n\n"); // prints out a recognized rule
        struct AST* id_ = malloc(sizeof(struct AST)); // create new tree to recognize ID
        struct AST* type_ = malloc(sizeof(struct AST)); // create new tree to recognize type
        struct AST* block_ = malloc(sizeof(struct AST)); // create new tree to recognize block
        
        block_ = AST_newTree("BLOCK", NULL, $7); // Set block as tree with keyword function block as right child
        id_ = AST_newTree("LOGIC", NULL, $3); // Set id as tree with boolean expression list as right child
        type_ = AST_newTree($1, id_, block_); // Set type as tree with id as right child
        $$ = type_; // Returns the type tree
    }
;

// Grammar Rules for the Key Function Block
KeyFuncBlock:   { $$ = NULL; } // Handles the epsilon case
    | KeyFunc KeyFuncBlock { // Handles nested key functions
        struct AST* curr = $1; // Init 'curr' node at top of this tree
        while(curr->right != NULL) { curr = curr->right; } // Get lowest node in tree
        if ($2 != NULL) { curr->right = $2; } // sets the right of the key function to the key function block tail
    }
    | Stmt SEMICOLON KeyFuncBlock { // Handles nested statements
        struct AST* curr = $1; // Init 'curr' node at top of this tree
        while(curr->right != NULL) { curr = curr->right; } // Get lowest node in tree
        if ($3 != NULL) { curr->right = $3; } // sets the right of the statement to the key function block tail
    }
;

// Grammar Rules for the Boolean Expression List
BoolExpList:
    VarTypes { $$ = $1; } // Recognize a var type as a terminator for boolean expressions
    | VarTypes BOOLOP VarTypes { // Grammar Rule
        struct AST* boolExp_ = malloc(sizeof(struct AST)); // create a new tree to recognize boolean operators
        boolExp_ = AST_newTree($2, $1, $3); // Sets the boolean tree's nodeType = passed in token, LHS = ID, RHS = ID
        $$ = boolExp_; // Returns the boolean tree
    }
;

// Grammar Rules for Variable Types
VarTypes:
    NUMBER {
        char _value_[50];
        sprintf(_value_, "%i", $1); // Convert int to string
        struct AST* value_ = malloc(sizeof(struct AST)); // create a new tree to recognize value
        value_ = AST_newTree(_value_, NULL, NULL); // Set value as terminator node
        $$ = value_; // returns the value tree
    }
    | ASCII {
        struct AST* value_ = malloc(sizeof(struct AST)); // create a new tree to recognize value
        value_ = AST_newTree($1, NULL, NULL); // sets the value tree's nodetype = passed in token
        $$ = value_; // returns the value tree
    }
    | ID {
        struct AST* value_ = malloc(sizeof(struct AST)); // Create new tree for value
        value_ = AST_newTree($1, NULL, NULL); // Set value as terminator node
        $$ = value_; // returns the value tree
    }
;

%%

// Main function
int main(int argc, char**argv) {
    /* // DEBUGGER
	#ifdef YYDEBUG
		yydebug = 1;
	#endif
	*/

    strcpy(currentScope,"Global");

    ST_header = malloc(sizeof(struct ST_Row));
	printf("\n##### COMPILER STARTED #####\n\n"); // Prints that the compiler has started
	
    initIRcodeFile();
    openMipsFile();
    generateMipsHeader();

	if (argc > 1) { // Loops through the argeuement tokens
        if(!(yyin = fopen(argv[1], "r"))) { // Checks if they are not valid to read
        perror(argv[1]); // Throws an error
        return(1); // Exits the program
        }
	}
	yyparse(); // Parses the tokens
}

// Function for handling parsing errors
void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s); // Prints that there was a parse error
	exit(1); // Exits the program
}