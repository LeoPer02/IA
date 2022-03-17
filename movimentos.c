void move_rigth(short int grid1[][4], short int vazio[]){
    if(vazio[1]!=3){                                            // vazio[0] posição do 0 na horizontal       
        vazio[1]++;                                            //vazio[1] posição do 0 na vertical
        grid1[vazio[0]][vazio[1]-1]=grid1[vazio[0]][vazio[1]];
        grid1[vazio[0]][vazio[1]]=0;    
        
    }
}

void move_left(short int grid1[][4], short int vazio[]){
    if(vazio[1]!=0){                                                  
        vazio[1]--;                                             
        grid1[vazio[0]][vazio[1]+1]=grid1[vazio[0]][vazio[1]];   
        grid1[vazio[0]][vazio[1]]=0;    
    }
}

void move_up(short int grid1[][4], short int vazio[]){
    if(vazio[1]!=0){                                                  
        vazio[0]--;                                             
        grid1[vazio[0]+1][vazio[1]]=grid1[vazio[0]][vazio[1]];   
        grid1[vazio[0]][vazio[1]]=0;    
    }
}

void move_down(short int grid1[][4], short int vazio[]){
    if(vazio[1]!=0){                                                  
        vazio[0]++;                                             
        grid1[vazio[0]-1][vazio[1]]=grid1[vazio[0]][vazio[1]];   
        grid1[vazio[0]][vazio[1]]=0;    
    }
}
