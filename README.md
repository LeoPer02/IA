# IA

Configurações:

Este programa foi escrito usando C nos Sistemas operativos [Fill] versão [Fill].
Em termos de compiladores foi usado o gcc versão [Fill]


Modo de utilização do programa:

Para efeitos de simplificação iremo-nos referir á Pasta principal como "IA".
Dentro de IA encontra-rá 2 pastas ("SearchAlgs" e "DataStructures") e um ficheiro main.c

Para a compilação do ficheiro deverá apenas usar [ gcc -o nomeficheiro main.c  ] ou apenas gcc main.c (Com um eventual -Wall caso ache necessário)
Após a execução do programa [ time ./nomeficheiro ] será-lhe perguntado qual algoritmo pretende utilizar, e nos casos A* e guloso, qual heurista pretende usar.
De seguida deverá apenas introduzir o estado inicial e final, respetivamente.

Desta forma caso queira tornar a testagem mais automática recomendá-mos a criação de ficheiros com o seguinte formato:

3                                           #Algoritmo a ser usado 1->Profundidade Ite. 2->Guloso 3->A*
1					    #Heuristica pretendida 1->Manhattan 2->Sumatório
1 2 3 4 5 6 8 12 13 9 0 7 14 11 10 15       #Estado inicial
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0       #Estado final
