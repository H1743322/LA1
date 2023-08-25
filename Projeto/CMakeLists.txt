cmake_minimum_required(VERSION 3.16)
project(Projeto)

set(CMAKE_CXX_STANDARD 14)

include_directories(Dados)
include_directories(Interface)
include_directories(Logica)
include_directories(Teste)

add_executable(Projeto
        Dados/dados.c
        Dados/dados.h
        Dados/list.c
        Dados/list.h
        Interface/interface.c
        Interface/interface.h
        Logica/logica.c
        Logica/logica.h
        Teste/teste.c
        Teste/teste.h
        main.c)
