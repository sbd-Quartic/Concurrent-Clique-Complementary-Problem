#include <stdlib.h>
#include <math.h>

char isPrime(size_t candidate) {
	size_t upperBound = sqrt(candidate)+1;

	if (!(candidate%2))
		return 0;
	for (int i=3; i < upperBound; i+=2)
		if (!(candidate%i))
			return 0;
	return 1;
}

size_t nextPrime(size_t init) {
	for (size_t i=init+1;;i++)
		if (isPrime(i))
			return i;
}