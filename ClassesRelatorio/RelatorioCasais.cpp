#include "RelatorioCasais.hpp"

#include <iostream>
#include <fstream>

#include "../ClassesAjudantes/DateUtils.hpp"
#include "../ClassesAjudantes/NumberUtils.hpp"

using namespace Sistema;

namespace Relatorio{
    void RelatorioCasais::geraRelatorioCasais(const string &pasta, Sistema::Controle * con){
        fstream arq;
        arq.open(pasta + "saida/3-estatisticas-casais.csv");
        if(arq.is_open()){
            unordered_map<string,Casal*> casais = con->casais1();
            arq << "doideira" << endl;
        }
    }
}

#include "Controle.h"

