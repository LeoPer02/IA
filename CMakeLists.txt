cmake_minimum_required(VERSION 3.21)
project(IA C)

set(CMAKE_C_STANDARD 11)

include_directories(DataStructures)
include_directories(SearchAlgs)

add_executable(IA
        DataStructures/BFSBoard.c
        DataStructures/BFSBoard.h
        DataStructures/BoardList.c
        DataStructures/BoardList.h
        DataStructures/BoardStack.c
        DataStructures/BoardStack.h
        DataStructures/HashStack.c
        DataStructures/HashStack.h
        DataStructures/IDSBoard.c
        DataStructures/IDSBoard.h
        DataStructures/MovementStack.c
        DataStructures/MovementStack.h
        DataStructures/Queue.c
        DataStructures/Queue.c
        DataStructures/Stack.c
        DataStructures/Stack.h
        DataStructures/Heap.c
        DataStructures/Heap.h
        SearchAlgs/A*.c
        SearchAlgs/A*.h
        SearchAlgs/BL.c
        SearchAlgs/BL.h
        SearchAlgs/BP.c
        SearchAlgs/BP.h
        SearchAlgs/Guloso.c
        SearchAlgs/Guloso.c
        SearchAlgs/BFS.c
        SearchAlgs/BFS.h
        SearchAlgs/Heur.c
        SearchAlgs/Heur.h
        SearchAlgs/IDS.c
        SearchAlgs/IDS.h
        SearchAlgs/Movimentos.c
        SearchAlgs/Movimentos.h
        main.c Utils/BoardUtils.c Utils/BoardUtils.h SearchAlgs/Heur.h DataStructures/Queue.h DataStructures/Heap.h SearchAlgs/A*.h SearchAlgs/BL.h DataStructures/Stack.h SearchAlgs/BP.h SearchAlgs/Guloso.h)
