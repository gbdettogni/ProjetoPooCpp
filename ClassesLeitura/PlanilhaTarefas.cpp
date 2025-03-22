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

                    Sistema::Pessoa* send;

                    if (con->getPessoaFisica(idPrestador) != nullptr) {
                        send = con->getPessoaFisica(idPrestador);;
                    }else if (con->getPessoaJuridica(idPrestador) != nullptr) {
                        send = con->getPessoaJuridica(idPrestador);
                    }else if (con->getLoja(idPrestador) != nullptr) {
                        send = con->getLoja(idPrestador);
                    }

                    auto *tarefa = new Sistema::Tarefa(idTarefa, valorPrestador, data, prazo,send, p);

                    con->getLar(idLar)->addTarefa(tarefa);
                    con->add(idTarefa, tarefa);
                }
            }
        }
    }

} // Leitura