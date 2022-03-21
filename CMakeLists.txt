cmake_minimum_required(VERSION 3.21)
project(IA C)

set(CMAKE_C_STANDARD 11)

add_executable(IA
        DataStructures/IDSBoard.c
        SearchAlgs/Heur.c
        SearchAlgs/IDS.c
        main.c
        SearchAlgs/Movimentos.c
        DataStructures/BoardStack.c
        DataStructures/MovementStack.c DataStructures/HashStack.c DataStructures/HashStack.h SearchAlgs/BFS.c DataStructures/BoardList.c DataStructures/BoardList.h DataStructures/BFSBoard.c DataStructures/BFSBoard.h SearchAlgs/BFS.h)
