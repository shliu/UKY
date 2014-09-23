#calc3
cacl3a:
	bison -y -d calc3.y
	flex calc3.l
	gcc -c -g y.tab.c lex.yy.c
	gcc -c -g calc3a.c
	g++ -c -g symbol_table.cc
	g++ -g y.tab.o lex.yy.o symbol_table.o calc3a.o -o cs441_calc3a

clean:
	rm y.tab.c y.tab.h
	rm lex.yy.c
	rm *.o
	rm cs441_calc3a
