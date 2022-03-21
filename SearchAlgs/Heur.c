#include <math.h>

// Implementação das heuristicas


// Sumatório dos numeros fora de lugar
int sum(short int a[][4], short int b[][4]){
    int count = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(a[i][j] != b[i][j]){count++;}
        }
    }
    return count;
}


// Manhattam Distance
int manh(short int a[][4], short int b[][4]){
    int total = 0, k;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            k = 0;
            while(1){
                if (a[i][j] == b[k/4][k%4]) {
                    total += abs(i-(k/4)) + abs(j-(k%4));
                    break;
                }
                k++;
            }
        }
    }
    return total;
}