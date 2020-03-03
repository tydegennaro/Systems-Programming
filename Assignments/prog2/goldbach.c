#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Calculate the primes up to upperBound
void getPrimes(int upperBound, int **primes, int *numPrimes) {
	// Get the starting index
	int i = 2;
	if (*numPrimes) {
		i = (*primes)[*numPrimes - 1] + 1;
	}

	// Calculate primes between i and upperBound
	for ( ; i < upperBound; i++) {
		bool isPrime = true;
		for (int j = 2; j < i; j++) {
			if (!(i % j)) {
				isPrime = false;
				break;
			}
		}
		// If i is prime, then add it to the end of primes
		if (isPrime) {
			(*primes)[(*numPrimes)++] = i;
		}
	}
}

// Calculate the prime breakdown of n using an array of precalculated primes of size 'size'
// Returns the lower of the two primes that make up n
int getGoldbach(int *primes, int size, int n) {
	int i = 0;
	int j = size - 1;
	while (i < j) {
		int sum = primes[i] + primes[j];
		if (sum == n) {
			// We found it!
			return primes[i];
		} else if (sum > n) {
			j--;
		} else {
			i++;
		}
	}
	printf("We just proved Goldbach's conjecture false. Ha.\n");
	return 0;
}

int main() {
  int n;
  int numPrimes = 0;
  // Read in a new upper bound
  scanf("%d", &n);
  int *primes = malloc(n * sizeof(int));
  // Get primes up to the upper bound we read in
  getPrimes(n, &primes, &numPrimes);
  // Keep reading in new numbers until we get a 0
  while (n != 0) {
    // Compute the prime breakdown n = lowPrime + highPrime
	int lowPrime = getGoldbach(primes, numPrimes, n);
	int highPrime = n - lowPrime;	
    printf("%d = %d + %d\n", n, lowPrime, highPrime);
    // Get next value
    scanf("%d", &n);
	if (n > primes[numPrimes - 1]) {
		primes = realloc(primes, n * sizeof(int));
		getPrimes(n, &primes, &numPrimes);
	}
  }
  return 0;
}