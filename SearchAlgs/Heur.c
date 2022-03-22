
// Implementação das heuristicas
int manh(short int a[][4], short int b[][4]);
int sum(short int a[][4], short int b[][4]);

int heuristica(short int a[][4], short int goal[][4], short int heur){
    if(heur == 1) return manh(a,goal);
    return sum(a,goal);
}


// Sumatório dos numeros fora de lugar
int sum(short int a[][4], short int b[][4]){
    int count = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(a[i][j] != b[i][j] && a[i][j] != 0 && b[i][j] != 0){count++;}
        }
    }
    return count;
}


// Manhattam Distance
int manh(short int a[][4], short int b[][4]){
    int total = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                for(int l = 0; l < 4; l++){
                    if(a[i][j] == b[k][l] && a[i][j] != 0 && b[i][j] != 0) total += abs(i-k) + abs(j-l);
                }
            }
        }
    }
    return total;
}