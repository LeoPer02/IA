cmake_minimum_required(VERSION 3.21)
project(IA C)

set(CMAKE_C_STANDARD 11)

add_executable(IA
        DataStructures/Board.c
        BPI.c
        SearchAlgs/heur.c
        SearchAlgs/IDS.c
        main.c
        movimentos.c
        DataStructures/BoardStack.c
        DataStructures/MovementStack.c)
