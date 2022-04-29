#include <stdio.h>
#include <math.h>

using namespace std;

double nlogn(int n) {
    return (double)n * log2((double)n);
}

int main() {
    long long times[7] = { 
        1000ULL,
        1000ULL * 60, 
        1000ULL * 60 * 60, 
        1000ULL * 60 * 60 * 24, 
        1000ULL * 60 * 60 * 24 * 30,
        1000ULL * 60 * 60 * 24 * 365,
        1000ULL * 60 * 60 * 24 * 365 * 100,
    };
    char* timeNames[7] = { (char*)"second", (char*)"minute", (char*)"hour", (char*)"day", (char*)"month", (char*)"year", (char*)"century" };

    printf("nlogn\n");
    for (int i = 0; i < 7; i++) {
        long long time = times[i];
        long long n = 1;
        while (nlogn(n) <= time)
            ++n;
        printf("%s %lld\n", timeNames[i], n);
    }

    printf("n!\n");
    for (int i = 0; i < 7; i++) {
        long long time = times[i];
        long long n = 1;
        while (tgamma(n + 1) <= time)
            ++n;
        printf("%s %lld\n", timeNames[i], n);
    }
}