#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

struct bomboane {
	int x;
	int y;
};

int main(int argc, char const *argv[]) {
	FILE *f, *g;
	f = fopen("bomboane.in", "r");
	if (f == NULL) {
		fprintf(stderr, "Eroare: Fisierul nu poate fi deschis %s", "bomboane.in");
		return -1;
	}
	g = fopen("bomboane.out", "w");

	int N, M, i, j, k;
	fscanf(f, "%d %d", &N, &M);
	struct bomboane *a = malloc(sizeof(struct bomboane) * (N+1));
	for (i = 1; i <= N; i++) {
		fscanf(f, "%d %d", &a[i].x, &a[i].y);
	}

	/*dp[i][j] = in cate moduri pot sa dau j bomboane la i copii*/
	long dp[51][2001] = {0};
	for (j = 0; j <= M; j++) {
		if (j >= a[1].x && j <= a[1].y) {
			dp[1][j] = 1;
		} else {
			dp[1][j] = 0;
		}
	}

	for (i = 2; i <= N; i++) {
		for (j = 0; j <= M; j++) {
			dp[i][j] = 0;
			for (k = a[i].x; k <= a[i].y; k++) {
				if (j >= k) {
					dp[i][j] += (dp[i - 1][j - k] % MOD);
					dp[i][j] %= MOD;
				}
			}
		}
	}

	fprintf(g, "%ld", dp[N][M] % MOD);

	fclose(f);
	fclose(g);

	return 0;
}
