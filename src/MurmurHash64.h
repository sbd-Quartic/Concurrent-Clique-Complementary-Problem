#ifndef MURMURHASH_H
#define MURMURHASH_H

#include <stdint.h>
uint64_t MurmurHash64A ( const void * key, int len, unsigned int seed ); 
uint64_t MurmurHash64B ( const void * key, int len, unsigned int seed );
#include "MurmurHash64.c"

#endif /* MURMURHASH_H */