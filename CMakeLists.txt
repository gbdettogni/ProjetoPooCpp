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
        ClassesAjudantes/Tokenizer.cpp
        ClassesSistema/Controle.cpp
        ClassesSistema/Controle.h
        ClassesSistema/Loja.cpp
        ClassesSistema/Loja.h
        ClassesLeitura/PlanilhaFestas.cpp
        ClassesLeitura/PlanilhaFestas.h
        ClassesSistema/Festa.cpp
        ClassesSistema/Festa.h
        ClassesSistema/Parcela.cpp
        ClassesSistema/Parcela.h
        ClassesSistema/Tarefa.cpp
        ClassesSistema/Tarefa.h
        ClassesSistema/Compra.cpp
        ClassesSistema/Compra.h
        ClassesLeitura/PlanilhaTarefas.cpp
        ClassesLeitura/PlanilhaTarefas.h
        ClassesLeitura/PlanilhaCompras.cpp
        ClassesLeitura/PlanilhaCompras.h
        ClassesLeitura/PlanilhasCasal.cpp
        ClassesSistema/Casal.cpp
        ClassesSistema/Casal.hpp
        ClassesSistema/Lar.hpp
        ClassesSistema/Lar.cpp
        ClassesSistema/Casamento.cpp
        ClassesRelatorio/RelatorioCasais.cpp
        ClassesRelatorio/RelatorioCasais.hpp
        ClassesAjudantes/StringUtils.hpp
        ClassesAjudantes/StringUtils.cpp
        ClassesAjudantes/Pair.cpp
        ClassesAjudantes/Pair.h
        ClassesRelatorio/RelatorioFinanceiro.cpp
        ClassesRelatorio/RelatorioFinanceiro.h
)
