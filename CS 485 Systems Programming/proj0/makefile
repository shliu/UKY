GCC = gcc
OBJECTS = main.o read_format.o read_data.o print.o operator.o

output : $(OBJECTS)
	$(GCC) $(OBJECTS) -o bindata
print.o : global.h print.c
	$(GCC) -c print.c
operator.o : global.h operator.c
	$(GCC) -c operator.c
data.o : global.h read_data.c
	$(GCC) -c read_data.c
format.o : global.h format.c
	$(GCC) -c read_format.c
main.o : global.h main.c
	$(GCC) -c main.c

clean:
	-rm -f $(OBJECTS) bindata 
