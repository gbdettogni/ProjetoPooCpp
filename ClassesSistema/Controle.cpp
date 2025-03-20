//
// Created by betelgeuse on 20/03/25.
//

#include "Controle.h"

#include "Loja.h"

namespace Sistema {
    void Controle::add(PessoaFisica *pf) {
        pessoasFisicas.push_back(pf);
    }

    void Controle::add(PessoaJuridica *pj) {
        pessoasJuridicas.push_back(pj);
    }

    void Controle::add(Loja *lj) {
        lojas.push_back(lj);
    }

    void Controle::add(Festa *fe) {
        festas.push_back(fe);
    }
} // Sistema