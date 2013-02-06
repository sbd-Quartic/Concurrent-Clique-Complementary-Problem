CFLAGS = -std=gnu99 -g
LFLAGS = -lm

OBJS = obj/Unit/Unit.quartic.HashTable.o obj/Unit/Unit.quartic.LinkedList.o \
obj/quartic.Graph.o	obj/quartic.Vertex.o obj/quartic.HashTable.o \
obj/quartic.Prime.o obj/quartic.LinkedList.o obj/quartic.VanityList.o \
obj/MurmurHash64.o

BINS = bin/Unit/Unit.quartic.HashTable bin/Unit/Unit.quartic.LinkedList

all: $(OBJS) $(BINS)
bin/Unit/Unit.quartic.HashTable: obj/Unit/Unit.quartic.HashTable.o
	gcc $(CFLAGS) -o bin/Unit/Unit.quartic.HashTable obj/Unit/Unit.quartic.HashTable.o $(LFLAGS)

bin/Unit/Unit.quartic.LinkedList: obj/Unit/Unit.quartic.LinkedList.o
	gcc $(CFLAGS) -o bin/Unit/Unit.quartic.LinkedList obj/Unit/Unit.quartic.LinkedList.o $(LFLAGS)

obj/Unit/Unit.quartic.HashTable.o: src/quartic.HashTable.h src/quartic.Prime.h
	gcc $(CFLAGS) -c -o obj/Unit/Unit.quartic.HashTable.o src/Unit/Unit.quartic.HashTable.c

obj/Unit/Unit.quartic.LinkedList.o: src/quartic.LinkedList.h
	gcc $(CFLAGS) -c -o obj/Unit/Unit.quartic.LinkedList.o src/Unit/Unit.quartic.LinkedList.c

obj/quartic.Graph.o: src/quartic.Graph.h src/quartic.Vertex.h
	gcc $(CFLAGS) -c -o obj/quartic.Graph.o src/quartic.Graph.h

obj/quartic.Vertex.o: src/quartic.Vertex.h
	gcc $(CFLAGS) -c -o obj/quartic.Vertex.o src/quartic.Vertex.h

obj/quartic.HashTable.o: src/quartic.HashTable.h src/quartic.Prime.h
	gcc $(CFLAGS) -c -o obj/quartic.HashTable.o src/quartic.HashTable.h

obj/quartic.Prime.o: src/quartic.Prime.h
	gcc $(CFLAGS) -c -o obj/quartic.Prime.o src/quartic.Prime.h

obj/quartic.LinkedList.o: src/quartic.LinkedList.h
	gcc $(CFLAGS) -c -o obj/quartic.LinkedList.o src/quartic.LinkedList.h

obj/quartic.VanityList.o: src/quartic.VanityList.h src/quartic.LinkedList.h \
	src/quartic.HashTable.h
	gcc $(CFLAGS) -c -o obj/quartic.VanityList.o src/quartic.VanityList.h

obj/MurmurHash64.o: src/MurmurHash64.h
	gcc $(CFLAGS) -c -o obj/MurmurHash64.o src/MurmurHash64.h

clean:
	@rm -f $(OBJS) $(BINS)
	@echo 'Files removed'