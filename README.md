# Algoritmos de busca no Jogo dos 15

### Configurações:

Este programa foi escrito usando C nos Sistemas operativos Ubuntu versão 20.04.3 LTS.
Em termos de compiladores foi usado o cmake.


### Modo de utilização do programa:

Para efeitos de simplificação iremo-nos referir á Pasta principal como "IA".
Dentro de IA encontra-rá 3 pastas (`SearchAlgs`, `DataStructures` e `Utils`) e um ficheiro main.c.

Para a compilação do ficheiro deverá instalar o programa cmake através do comando
```
sudo apt-get install cmake
```
e em seguida executar, enquanto no diretório IA
```
cmake .
make
```
Após a execução do programa `IA`, de mesmo nome do diretório do programa, será-lhe perguntado qual algoritmo pretende utilizar, e nos casos A* e guloso, qual heurista pretende usar.
De seguida deverá apenas introduzir o estado inicial e final, respetivamente.

### Troubleshooting

Caso, ao tentar gerar o executável, houver algum problema relacionado a versionamento do CMAKE, recomenda-se checar a 
versão do programa instalada através de
```
cmake --version
```
e alterar o arquivo `CMakeLists.txt` para que a versão seja coincidente.