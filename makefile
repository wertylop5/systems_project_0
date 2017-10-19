my_tunez: main.o list.o music_library.o
	gcc -o my_tunez main.o list.o music_library.o
	make clean

debug:
	gcc -g main.c lib/*.c include/*.h

main.o: main.c include/list.h include/music_library.h
	gcc -c main.c include/list.h include/music_library.h

list.o: lib/list.c include/list.h
	gcc -c lib/list.c include/list.h

music_library.o: lib/music_library.c include/music_library.h include/list.h
	gcc -c lib/music_library.c include/music_library.h include/list.h

clean:
	rm *.o

run:
	./my_tunez
