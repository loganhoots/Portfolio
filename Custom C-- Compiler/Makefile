all: parser

parser.tab.c parser.tab.h:	parser.y
	bison -t -v -d parser.y

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

parser: lex.yy.c parser.tab.c parser.tab.h AST.h
	gcc -o parser parser.tab.c lex.yy.c
	./parser ./inputs/ISAC_TEST_THIS.cmm

mips: mipsOutput.asm
	@echo "MIPS Output: \n"
	spim run "mipsOutput.asm"
	@echo "\n"

mipsTest: mipsTest.asm
	@echo "MIPS Output: \n"
	spim run "mipsTest.asm"
	@echo "\n"

clean:
	rm -f parser lexer parser.tab.c lex.yy.c parser.tab.h parser.output IRcode.ir mipsOutput.asm