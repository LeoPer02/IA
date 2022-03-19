cmake_minimum_required(VERSION 3.21)
project(IA C)

set(CMAKE_C_STANDARD 11)

add_executable(IA
        Board.c
        BPI.c
        heur.c
        IDS.c
        main.c
        movimentos.c
        BoardStack.c
        MovementStack.c)
