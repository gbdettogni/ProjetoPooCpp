#include "RelatorioCasais.hpp"

#include <iostream>
#include <fstream>
#include <algorithm>

#include "../ClassesAjudantes/DateUtils.hpp"
#include "../ClassesAjudantes/NumberUtils.hpp"
#include "../ClassesSistema/Controle.h"
#include "../ClassesException/Exception.hpp"

namespace Relatorio{
    void RelatorioCasais::geraRelatorioCasais(const string &pasta, Sistema::Controle * con){
        ofstream arq(pasta + "saida/3-estatisticas-casais.csv");

        if(arq.is_open()){
            list<Casal*> casaisOrdenados = ordenaRelatorioCasais(con);

            for(Casal *c : casaisOrdenados){
                arq << c << endl;
            }
        }
        else throw Exc::IOExcecao("Erro de I/O");
    }
    list<Casal*> RelatorioCasais::ordenaRelatorioCasais(Controle *con){
        list<Casal*> casaisProcessados;
        for (auto & iter : con->casais1())
        {
            Casal* c = iter.second; // pointer to Node
            c->processaGastoTotal();
            c->processaCasamentoConjunto(con->festas1());
            casaisProcessados.push_back(c);
        }
        casaisProcessados.sort(Casal::comparaCasal);
        return casaisProcessados;
    }
}