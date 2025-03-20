//
// Created by betelgeuse on 20/03/25.
//

#include "Controle.h"

namespace Sistema {
    void Controle::add(PessoaFisica *pf) {
        pessoasFisicas.push_back(pf);
    }

    void Controle::add(PessoaJuridica *pj) {
        pessoasJuridicas.push_back(pj);
    }
} // Sistema