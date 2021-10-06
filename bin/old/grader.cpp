// caduta.cpp
#include <bits/stdc++.h>
using namespace std;

typedef enum {
	OK,
	RISOLTO,
	IMPOSSIBILE
} stato_t;

typedef struct {
	int domino1;
	int domino2;
} coppia_t;

int buco = -1;
int delat = 0;
int accumulo = 1;
map <int, map <int, int> > maxp;    // n° in più, n° necessari, pos
map <int, int> maxdelta;            // n° delta, pos

stato_t correggi(int N, int altezze[], coppia_t* scambio) {
	// esempio di implementazione, cancella queste righe e implementa qui la tua soluzione

	for (int i = 0; i < N; ++i)
    {
        --accumulo;
        maxdelta.insert({accumulo - 1, i});

        map <int, int> temp;
        int min_ = 0;
        int max_ = altezze[i];
        while (min_ != max_)
        {
            int try_ = (min_ + max_) / 2
            int fake_accumolo = try_;
            for (int j = i+1; j < try_; ++j)
            {
                fake_accumulo += altezze[j] - 1;
            }
        }
        temp.insert({7, i});
        maxp.insert({5, temp});

        accumulo += altezze[i] - 1;
    }




	if (N % 3 == 0) {
		// usa la sintassi scambio->campo invece di scambio.campo
		scambio->domino1 = 0;
		scambio->domino2 = 3;

		// valorizzando il parametro scambio, stiamo dicendo di aver risolto
		return RISOLTO;
	} else if (N % 3 == 1) {
		// stiamo dicendo che non era necessario risolvere
		return OK;
	} else {
		// stiamo dicendo che non era possibile risolvere
		return IMPOSSIBILE;
	}
}









/* Example cases
5 3 2 1 4 1
2 3

5 3 2 2 4 1
OK

5 1 1 1 1 1
IMPOSSIBILE
*/




// Core
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
/*
typedef enum {
	OK,
	RISOLTO,
	IMPOSSIBILE
} stato_t;

typedef struct {
	int domino1;
	int domino2;
} coppia_t;
*/
stato_t correggi(int N, int altezze[], coppia_t* scambio);


int main() {
	int N, *altezze;

	assert(1 == scanf("%d", &N));

	altezze = (int*) malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
		assert(1 == scanf("%d", &altezze[i]));

	coppia_t scambio;
	stato_t stato = correggi(N, altezze, &scambio);

	if (stato == OK)
		printf("OK\n");
	else if (stato == IMPOSSIBILE)
		printf("IMPOSSIBILE\n");
	else
		printf("%d %d\n", scambio.domino1, scambio.domino2);

	free(altezze);
	return EXIT_SUCCESS;
}
