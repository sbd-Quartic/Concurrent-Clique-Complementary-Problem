CFLAGS = -std=gnu99 -g
LFLAGS = -lm

test: test.o
	gcc $(CFLAGS) -o test test.o $(LFLAGS)
test.o: test.c quartic.Graph.h quartic.Edge.h quartic.Vertex.h \
 	quartic.HashTable.h quartic.Prime.h quartic.LinkedList.h \
	MurmurHash64.h
	gcc $(CFLAGS) -c -o test.o test.c
clean:
	rm test.o test
