#include "gauss.h"
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    int n = mat->r; // pobranie liczby wierszy

    for (int i = 0; i < n; i++) {
        // znajdywanie diagonali głównej - największego elementu w kolumnie
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(mat->data[k][i]) > fabs(mat->data[maxRow][i])) {
                maxRow = k;
            }
        }

        // zamiana wierszy by dać diagonalną główna na górze
        if (i != maxRow) {
            for (int k = i; k < n; k++) {
                double tmp = mat->data[i][k];
                mat->data[i][k] = mat->data[maxRow][k];
                mat->data[maxRow][k] = tmp;
            }
            double tmp = b->data[i][0];
            b->data[i][0] = b->data[maxRow][0];
            b->data[maxRow][0] = tmp;
        }

        // sprawdzanie czy macierz jest osobliwa
        if (mat->data[i][i] == 0) {
            return 1; // Kod błędu dla macierzy osobliwej
        }

        // proces eliminacji
        for (int j = i + 1; j < n; j++) {
            double factor = mat->data[j][i] / mat->data[i][i];
            for (int k = i; k < n; k++) {
                mat->data[j][k] -= factor * mat->data[i][k];
            }
            b->data[j][0] -= factor * b->data[i][0];
        }
    }

    return 0; // Sukces
}

