#ifndef PRIME_H
#define PRIME_H

#include <stdlib.h>
#include "quartic.Prime.c"

char isPrime(size_t candidate);
size_t nextPrime(size_t init);

#endif /* PRIME_H */