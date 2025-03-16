//
// Created by betelgeuse on 15/03/25.
//

#ifndef PLANILHAPESSOAS_H
#define PLANILHAPESSOAS_H
#include <list>
#include <string>
#include "../ClassesSistema/PessoaFisica.h"


using namespace std;

namespace Leitura {

class PlanilhaPessoas {
public:
    static list<Sistema::PessoaFisica>  lePlanilhaPessoas(const std::string &pasta);
};

} // Leitura

#endif //PLANILHAPESSOAS_H
