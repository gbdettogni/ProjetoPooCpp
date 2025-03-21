//
// Created by betelgeuse on 15/03/25.
//

#ifndef PLANILHAPESSOAS_H
#define PLANILHAPESSOAS_H
#include <list>
#include <string>

#include "../ClassesSistema/Controle.h"
#include "../ClassesSistema/PessoaFisica.h"


using namespace std;

namespace Leitura {

class PlanilhaPessoas {
public:
    static void lePlanilhaPessoas(const string &pasta, Sistema::Controle* con);
};

} // Leitura

#endif //PLANILHAPESSOAS_H
