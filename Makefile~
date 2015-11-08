scan: 		scanMain.o lex.yy.o
		gcc -o scan scanMain.o lex.yy.o

scanMain.o:	scanMain.c cminus.tab.h
		gcc -c scanMain.c


cminus.tab.h:	cminus.y
		bison -d cminus.y

lex.yy.o:	cminus.l cminus.tab.h
		flex cminus.l
		gcc -c lex.yy.c 

parse:		parseMain.o cminus.tab.o lex.yy.o symtab.o
		gcc -o parse parseMain.o cminus.tab.o symtab.o lex.yy.o

parseMain.o:	parseMain.c
		gcc -c parseMain.c

cminus.tab.o:	cminus.y lex.yy.o
		bison cminus.y
		gcc -c cminus.tab.c

symtab.o:	symtab.c symtab.h
		gcc -c symtab.c

gencode:	gencodeMain.o gencode.o cminus.tab.o  symtab.o lex.yy.o
		gcc -o gencode gencodeMain.o gencode.o cminus.tab.o  symtab.o lex.yy.o

gencodeMain.o:	gencodeMain.c  


# use del on Windows. use rm on Linux/Cygwin/Mac
clean:		
		rm *.o 

#scan: 		scanMain.o lex.yy.o
#		gcc -o scan scanMain.o lex.yy.o

#scanMain.o:	scanMain.c tiny.tab.h
#		gcc -c scanMain.c

#tiny.tab.h:	tiny.y
#		bison -d tiny.y

#lex.yy.o:	tiny.l tiny.tab.h
#		flex tiny.l
#		gcc -c lex.yy.c 

#parse:		parseMain.o tiny.tab.o  symtab.o lex.yy.o
#		gcc -o parse parseMain.o tiny.tab.o symtab.o lex.yy.o

#parseMain.o:	parseMain.c  tiny.tab.h 
#		gcc -c parseMain.c

#tiny.tab.o:	tiny.y  symtab.h
#		bison tiny.y
#		gcc -c tiny.tab.c

#testsymtab:	symtabMain.o symtab.o
#		gcc -o testsymtab symtabMain.o symtab.o

#symtab.o:	symtab.c symtab.h
#		gcc -c symtab.c

#symtabMain.o: 	symtabMain.c symtab.h
#		gcc -c symtabMain.c
# use del on Windows. use rm on Linux/Cygwin/Mac
#clean:		
#		rm *.o 



