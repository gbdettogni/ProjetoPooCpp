#ifndef RELATORIOCASAIS_H
#define RELATORIOCASAIS_H

#include <iostream>
#include "../ClassesSistema/Controle.h"

namespace Relatorio
{
    class RelatorioCasais{
        public:
            static void geraRelatorioCasais(const string &pasta, Sistema::Controle * con);
    };
}

#endif // RELATORIOCASAIS_H