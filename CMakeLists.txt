cmake_minimum_required(VERSION 3.30)
project(ProjetoPooCpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProjetoPooCpp main.cpp
        ClassesSistema/Pessoa.cpp
        ClassesSistema/Pessoa.h
        ClassesSistema/PessoaFisica.cpp
        ClassesSistema/PessoaFisica.h
        ClassesSistema/PessoaJuridica.cpp
        ClassesSistema/PessoaJuridica.h
        ClassesLeitura/PlanilhaPessoas.cpp
        ClassesLeitura/PlanilhaPessoas.h
        ClassesAjudantes/DateUtils.cpp
        ClassesAjudantes/NumberUtils.cpp
        ClassesAjudantes/NumPunctPTBR.hpp
        ClassesAjudantes/NumPunctPTBR.cpp
        ClassesAjudantes/Tokenizer.cpp)
