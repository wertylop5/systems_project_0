my_tunez: main.o list.o
	gcc -o my_tunez main.o list.o
	make clean

main.o: main.c include/list.h
	gcc -c main.c include/list.h

list.o: lib/list.c include/list.h
	gcc -c lib/list.c include/list.h

clean:
	rm *.o

run:
	./my_tunez
