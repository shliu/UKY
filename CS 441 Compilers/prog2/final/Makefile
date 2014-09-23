#calc3
cacl3a:
	bison -y -d calc3.y
	flex calc3.l
	gcc -c -g y.tab.c lex.yy.c
	g++ -c -g calc3a.cc
	g++ -c -g pstcode.cc
	g++ -c -g symbol_table.cc
	g++ -g y.tab.o lex.yy.o symbol_table.o calc3a.o pstcode.o -o cs441_calc3a
	rm *.o

clean:
	rm y.tab.c y.tab.h
	rm lex.yy.c
	rm *.o
	rm cs441_calc3a
