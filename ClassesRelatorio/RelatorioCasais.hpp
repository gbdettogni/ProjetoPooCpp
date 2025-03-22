#ifndef RELATORIOCASAIS_H
#define RELATORIOCASAIS_H

#include <iostream>
#include "../ClassesSistema/Controle.h"
using namespace Sistema;

namespace Relatorio
{
    class RelatorioCasais{
        public:
            static void geraRelatorioCasais(const string &pasta, Sistema::Controle * con);
            static list<Casal*> ordenaRelatorioCasais(Controle *con);
    };
}

#endif // RELATORIOCASAIS_H