//
// Created by betelgeuse on 20/03/25.
//

#include "PlanilhaCompras.h"

#include "PlanilhaTarefas.h"

#include <fstream>
#include "../ClassesAjudantes/Tokenizer.hpp"
#include "../ClassesAjudantes/DateUtils.hpp"
#include "../ClassesAjudantes/NumberUtils.hpp"
#include "../ClassesSistema/Tarefa.h"
#include "../ClassesException/Exception.hpp"

using namespace std;

namespace Leitura {
    void PlanilhaCompras::lePlanilhaCompras(const std::string &pasta, Sistema::Controle* con) {
        std::fstream arq;
        arq.open(pasta + "compras.csv", std::ios::in);
        string linha;
        if (arq.is_open()) {
            while (! arq.eof() ) {
                getline (arq, linha);
                 auto t = Tokenizer(linha, ';');
                while (t.hasNext()) {
                    string idCompra = t.next(),
                            idTarefa = t.next(),
                            idLoja = t.next(),
                            nome = t.next();

                    if(con->getPessoaJuridica(idLoja) != nullptr){
                        throw Exc::idNaoExisteExcecao("ID " + idLoja + " da Compra de ID " + idCompra + " não se refere a uma Loja, mas a uma PJ.");
                    }
                    if(con->getLoja(idLoja) == nullptr){
                        throw Exc::idNaoExisteExcecao("ID(s) de Loja " + idLoja + " não cadastrado na Compra de ID " + idCompra +".");
                    }
                    if(con->getCompra(idCompra) != nullptr){
                        throw Exc::idRepetidoExcecao("ID repetido " + idCompra + " na classe Compra.");
                    }
                    if(con->getTarefa(idTarefa) == nullptr){
                        throw Exc::idNaoExisteExcecao("ID(s) de Tarefa " + idTarefa + " não cadastrado na Compra de ID " + idCompra + ".");
                    }

                    int quantidade = stoi(t.next());
                    double preco = parseDouble(t.next(), LOCALE_PT_BR);
                    int numParcelas = stoi(t.next());

                    auto p = new Sistema::Parcela(numParcelas, preco, cpp_util::parseDate("16/10/2004", cpp_util::DATE_FORMAT_PT_BR_SHORT));
                    
                    
                    auto *loja = con->getLoja(idLoja);
                    auto* comp = new Sistema::Compra(nome, quantidade, preco, loja, p);



                    con->getTarefa(idTarefa)->addCompra(comp);

                    con->add(idCompra, comp);
                }
            }
        }
    }

} // Leitura