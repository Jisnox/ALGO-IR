#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int prems_naif(int n) {
    if (n < 2) return 0;
    int sum = 0;
    int premier[n];
    for (int i = 2; i <= n; i++) {
        int racine = sqrt(i);
        int cle = 0;
        for (int j = 0; (j < sum) && (premier[j] <= racine); j++) {
            if (i % premier[j] == 0) {
                cle = 1;
                break;
            }
        }
        if (cle == 0) {
            premier[sum] = i;
            sum++;
        }
    }
    return sum;
}

int prems_dyn(int n) {
    if (n < 2) return 0;
    int sum = 0;
    int premiers[n + 1];
    for (int i = 0; i <= n; i++) {
        premiers[i] = 0;
    }
    for (int i = 2; i <= n; i++) {
        if (premiers[i] != -1) {
            sum++;
            long long k = i; 
            while (i * k <= n) {
                premiers[i * k] = -1;
                k++;
            }
        }
    }
    return sum;
}

void main() {
    int n = 1000;
    clock_t start_dyn = clock();
    int res_dyn = prems_dyn(n);
    clock_t end_dyn = clock();
    double time_dyn = (double)(end_dyn - start_dyn) / CLOCKS_PER_SEC;
    printf("Methode Dynamique Nombre trouves : %d\n", res_dyn);
    printf("Temps : %f secondes\n\n", time_dyn);

    clock_t start_naif = clock();
    int res_naif = prems_naif(n);
    clock_t end_naif = clock();
    double time_naif = (double)(end_naif - start_naif) / CLOCKS_PER_SEC;
    printf("Methode Naive Nombre trouves : %d\n", res_naif);
    printf("Temps : %f secondes\n", time_naif);
    return;
}