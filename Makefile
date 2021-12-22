main.o: main.c snippet_list.h
	gcc -c -Wall --pedantic main.c
snippet_list.o: snippet_list.c snippet_list.h
	gcc -c -Wall --pedantic snippet_list.c
db: main.o snippet_list.o
	gcc -o db main.o snippet_list.o
clean:
	rm –f main.o snippet_list.o db
all: db
tarball: main.c snippet_list.c snippet_list.h Makefile
	tar -cvf project3.tar main.c snippet_list.c snippet_list.h Makefile

