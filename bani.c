#include <stdio.h>
#include <time.h>
#define MOD 1000000007


long fastPow(long base, int exponent, int mod) {
	if (exponent == 0) {
    	return 1;
	}

	long aux = 1;
    while (exponent != 1) {
    	if (exponent % 2 == 0) {   // par
        	base = (1LL * base * base) % (1LL * mod);
            exponent /= 2;
        } else {                   // impar
        	aux = (1LL * aux * base) % (1LL * mod);
            exponent--;
        }
    }

    return (1LL * aux * base) % (1LL * mod);
}

int main(int argc, char const *argv[]) {
	FILE *f, *g;
	f = fopen("bani.in", "r");
	if (f == NULL) {
		fprintf(stderr, "Eroare: Fisierul nu poate fi deschis %s", "bani.in");
		return -1;
	}
	g = fopen("bani.out", "w");

	int type, N;
	long res = 0;
	fscanf(f, "%d %d", &type, &N);

	if (type == 1) {
		/*la fiecare pas se dubleaza numarul de moduri*/
		res = fastPow(2, N-1, MOD);
		fprintf(g, "%ld", (5 * res) % MOD);
		fclose(f);
		fclose(g);
	}

	if (type == 2) {
		/*memorez cate combinatii se termina in fiecare bacnota*/
		long bac10, bac50, bac100, bac200, bac500;
		long aux10, aux50, aux100, aux200, aux500;
		bac10 = bac50 = bac100 = bac200 = bac500 = 1;
		aux10 = aux50 = aux100 = aux200 = aux500 = 1;
		for (int i = 2; i <= N; i++) {
			bac10 = aux50 + aux100 + aux500;
			bac10 %= MOD;

			bac50 = aux10 + aux200;
			bac50 %= MOD;

			bac100 = aux10 + aux100 + aux200;
			bac100 %= MOD;
			bac200 = aux50 + aux500;
			bac200 %= MOD;

		 	bac500 = aux200;
		 	bac500 %= MOD;
		 	res = bac10 + bac50 + bac100 + bac200 + bac500;
		 	res %= MOD;

		 	aux10 = bac10;
		 	aux50 = bac50;
		 	aux100 = bac100;
		 	aux200 = bac200;
		 	aux500 = bac500;
		}
		fprintf(g, "%ld", res % MOD);
		fclose(f);
		fclose(g);
	}

	return 0;
}
