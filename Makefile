all: packfiles unpackfiles

packfiles: packfiles.o
	gcc packfiles.o -o packfiles

packfiles.o: packfiles.c
	gcc -c packfiles.c -o packfiles.o

unpackfiles: unpackfiles.o
	gcc unpackfiles.o -o unpackfiles

unpackfiles.o: unpackfiles.c
	gcc -c unpackfiles.c -o unpackfiles.o
clean:
	rm -f packfiles unpackfiles *.o *~
