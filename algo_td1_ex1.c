#include <stdio.h>
#include <limits.h>
#include <time.h>

unsigned long long Naive_Fibonacci (unsigned int n) {
    if(n==0 || n==1){return n;} 
    else {return Naive_Fibonacci(n-1)+ Naive_Fibonacci(n-2);}
}

unsigned long long fibonacci_memo(unsigned int n, unsigned long long memo[]) {
    if (memo[n] != ULLONG_MAX) {
        return memo[n];
    }
    if (n<= 1) {
        memo[n] = n;
    } else {
        memo[n] = fibonacci_memo(n-1,memo) + fibonacci_memo(n-2,memo);
    }
    return memo[n];
}

void main() {
    unsigned int n = 40; 
    unsigned long long memo[n + 1];
    for (unsigned int i = 0; i <= n; i++) {
        memo[i] = ULLONG_MAX;
    }
    clock_t start_dyn = clock();
    unsigned long long resultat_dyn = fibonacci_memo(n, memo);
    clock_t end_dyn = clock();
    double temps_dyn = (double)(end_dyn - start_dyn) / CLOCKS_PER_SEC;
    printf("Methode Dynamique Resultat : %llu\n", resultat_dyn);
    printf("Temps : %f secondes\n", temps_dyn);

    clock_t start_naif = clock();
    unsigned long long resultat_naif = Naive_Fibonacci(n);
    clock_t end_naif = clock();
    double temps_naif = (double)(end_naif - start_naif) / CLOCKS_PER_SEC;
    printf("Methode Naive Resultat : %llu\n", resultat_naif);
    printf("Temps : %f secondes\n", temps_naif);
    return;
}