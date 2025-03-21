//
// Created by betelgeuse on 20/03/25.
//

#include "PlanilhaTarefas.h"

#include <fstream>
#include "../ClassesAjudantes/Tokenizer.hpp"
#include "../ClassesAjudantes/DateUtils.hpp"
#include "../ClassesAjudantes/NumberUtils.hpp"
#include "../ClassesSistema/Tarefa.h"


using namespace std;

namespace Leitura {
    void PlanilhaTarefas::lePlanilhaTarefas(const std::string &pasta, Sistema::Controle* con) {
        std::fstream arq;
        arq.open(pasta + "tarefas.csv", std::ios::in);
        string linha;
        if (arq.is_open()) {
            while (! arq.eof() ) {
                getline (arq, linha);
                cout << linha << endl;
                auto t = Tokenizer(linha, ';');
                while (t.hasNext()) {
                    string idTarefa = t.next(),
                            idLar = t.next(),
                            idPrestador = t.next();
                    time_t data = cpp_util::parseDate(t.next(), cpp_util::DATE_FORMAT_PT_BR_SHORT);

                    int prazo = stoi(t.next());
                    double valorPrestador = parseDouble(t.next(), LOCALE_PT_BR);
                    int numParcelas = stoi(t.next());

                    auto p = new Sistema::Parcela(numParcelas, valorPrestador, data);
                    auto *imbecil = new Sistema::PessoaFisica("a", "a", "a", "a", data, "a", 2.5, 2.5, 2.5);
                    auto *tarefa = new Sistema::Tarefa(idTarefa, valorPrestador, data, prazo,*imbecil, *p);
                    con->add(idTarefa, tarefa);
                }
            }
        }
    }

} // Leitura