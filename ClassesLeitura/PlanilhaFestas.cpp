//
// Created by betelgeuse on 20/03/25.
//

#include "PlanilhaFestas.h"
#include "../ClassesAjudantes/Tokenizer.hpp"
#include "../ClassesAjudantes/DateUtils.hpp"
#include "../ClassesAjudantes/NumberUtils.hpp"


#include <fstream>
#include <iostream>
#include <list>

#include "../ClassesSistema/Controle.h"
#include "../ClassesSistema/Festa.h"
#include "../ClassesSistema/Parcela.h"

using namespace Sistema;
namespace Leitura {
    void PlanilhaFestas::lePlanilhaFestas(const string &pasta, Sistema::Controle *con) {
        fstream arq;
        arq.open(pasta + "festas.csv", std::ios::in);
        string linha;
        if (arq.is_open()) {
            while (! arq.eof() ) {
                getline (arq, linha);
                cout << linha << endl;
                auto t = Tokenizer(linha, ';');
                while (t.hasNext()) {
                    string idFesta = t.next(),
                            idCasamento = t.next(),
                            local = t.next();
                    time_t dataFesta = cpp_util::parseDate(t.next(), cpp_util::DATE_FORMAT_PT_BR_SHORT);
                    string hora = t.next();
                    double preco = parseDouble(t.next(), LOCALE_PT_BR);
                    int numParcelas = stoi(t.next());
                    int numConvidados = stoi(t.next());

                    Sistema::Parcela* p = new Sistema::Parcela(numParcelas, preco, dataFesta);

                    list<string> convidados;

                    while (t.hasNext()) {
                        convidados.push_back(t.next());
                    }
                    Festa *f = new Festa(local, preco, dataFesta, hora, convidados, *p);
                    con->add(idFesta, f);
                }
            }
        }
    }
} // Leitura