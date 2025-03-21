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

    Casal* Controle::getCasalById(string &id1, string &id2){ //tenta achar o casal no Map por cada um dos ids das pessoas
        if (casais.count(id1) > 0)                          //vai que a entrada do lar/casamento tem os mesmos ids porém invertidos em ordem
        {
            return casais.at(id1);
        }else if (casais.count(id2)>0)
        {
            return casais.at(id2);
        }
        else return nullptr;
    }
} // Sistema