//
// Created by betelgeuse on 20/03/25.
//

#ifndef PLANILHATAREFAS_H
#define PLANILHATAREFAS_H
#include <string>
#include "../ClassesSistema/Controle.h"


namespace Leitura {

class PlanilhaTarefas {
public:
    static void lePlanilhaTarefas(const std::string &pasta, Sistema::Controle*);

};

} // Leitura

#endif //PLANILHATAREFAS_H
