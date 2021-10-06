#include <bits/stdc++.h>
using namespace std;

typedef enum
{
	OK,
	RISOLTO,
	IMPOSSIBILE
} stato_t;

typedef struct
{
	int domino1;
	int domino2;
} coppia_t;

bool ok();

vector<int> tessere;

stato_t correggi(int N, int altezze[], coppia_t *scambio)
{
	tessere.resize(N);

	for (size_t i = 0; i < N; ++i)
		tessere[i] = altezze[i];

	if (ok())
	{
		return OK;
	}
	else
	{
		return IMPOSSIBILE;
	}

	/*// esempio di implementazione, cancella queste righe e implementa qui la tua soluzione

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
	}*/
}

bool ok()
{
	int potenza_cadente = 1;

	for (size_t i = 0; i < tessere.size(); ++i)
	{
		if (--potenza_cadente < 0)
			return false;

		potenza_cadente = max(potenza_cadente, tessere[i] - 1);
	}

	return true;
}
