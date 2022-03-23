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

Descrição jogo dos 15:
O jogo consiste em uma caixa e 15 peças numeras de 1 a 15 que preenchem a caixa, deixando um espaço vazio. O as peças numeradas começam numa ordem aleatória e o objetivo do jogo é ordená-las (nem sempre possível dependendo da configuração inicial A ordenação é feita através de várias ações consecutivas que consistem em trocar o espaço vazio com uma das peças a ele adjacente.


Comparação das estratégias:
Em termos de complexidade temporal os algoritmos A* e Iterative Deepening Search com complexidades de O(bd), sendo que o b é o fator de ramificação e o d é a profundidade do objetivo, enquanto que o Greedy tem complexidade O(bm).
No que diz respeito à complexidade espacial o Iterative Deepening Search é o mais eficiente, sendo a sua complexidade O(d). Assim, o IDS é a melhor estratégia para o problema.


Bibliografia:

Contributors, W. (2022). A* search algorithm. Wikipedia, The Free Encyclopedia. 
  https://en.wikipedia.org/w/index.php?title=A*_search_algorithm&oldid=1073628314

Contributors, W. (2022). Greedy algorithm. Wikipedia, The Free Encyclopedia. 
  https://en.wikipedia.org/w/index.php?title=Greedy_algorithm&oldid=1070097233

Contributors, W. (2021). Iterative deepening depth-first search. Wikipedia, The Free Encyclopedia. 
  https://en.wikipedia.org/w/index.php?title=Iterative_deepening_depth-first_search&oldid=1001650193
