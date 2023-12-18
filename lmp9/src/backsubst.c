#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				
	int r = mat->r - 1;
	int c = mat->c - 1;
	//jeśli liczba kolumn nie jest równa liczbie wierszy, program zwraca 2
	if(r != c) return 2;

	int p = c;
	double sum;

	for(int i = r; i >= 0; i--) {
		for(int j = c; j > p; j--) {
			sum = (mat -> data[i][j])*(x -> data[j][0]);
			b -> data[i][0] -= sum;
		}
		// jeżeli element na diagonali = 0, program zwraca 1
		if(mat -> data[i][i] == 0) {
			return 1;
		}
		x -> data[i][0] = b -> data[i][0] / mat -> data[i][i];
		p--;
	}
	return 0;
}


