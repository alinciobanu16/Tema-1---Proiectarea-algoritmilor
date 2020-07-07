#include <stdio.h>
#include <stdlib.h>

struct gard {
	int start;
	int stop;
};

int cmpf(const void *x1, const void *x2) {
	const struct gard *pa =  x1;
	const struct gard *pb =  x2;
	/*sortez crescator dupa xstart si descrescator dupa xstop*/
	int rez = pa->start - pb->start;
	if (rez == 0) {
		return -(pa->stop - pb->stop);
	}
	return rez;
}

int main(int argc, char const *argv[]) {
	FILE *f, *g;
	f = fopen("gard.in", "r");
	if (f == NULL) {
		fprintf(stderr, "Eroare: Fisierul nu poate fi deschis %s", "gard.in");
		return -1;
	}
	g = fopen("gard.out", "w");

	int n, i, max, red = 0;;
	fscanf(f, "%d", &n);
	struct gard *a = malloc(sizeof(struct gard) * n);
	for (i = 0; i < n; i++) {
		fscanf(f, "%d %d", &a[i].start, &a[i].stop);
	}
	qsort(a, n, sizeof(struct gard), cmpf);
	max = a[0].stop;
	for (i = 1; i < n; i++) {
		if (a[i].stop <= max) {
			red++;
		} else {
			max = a[i].stop;
		}
	}

	fprintf(g, "%d", red);

	return 0;
}
