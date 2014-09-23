#calc3
cacl3a:
	bison -y -d calc3.y
	flex calc3.l
	gcc -c y.tab.c lex.yy.c
	gcc y.tab.o lex.yy.o calc3a.c -o cs441_calc3a

clean:
	rm y.tab.c y.tab.h
	rm lex.yy.c
	rm *.o
	rm cs441_calc3a
