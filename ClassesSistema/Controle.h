//
// Created by betelgeuse on 20/03/25.
//

#ifndef CONTROLE_H
#define CONTROLE_H
#include <list>

#include "Festa.h"
#include "Loja.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"

namespace Sistema {

class Controle {
    std::list<PessoaFisica*> pessoasFisicas;
    std::list<PessoaJuridica*> pessoasJuridicas;
    std::list<PessoaJuridica*> lojas;
    std::list<Festa*> festas;

public:
    Controle() = default;

    ~Controle() = default;

    [[nodiscard]] std::list<PessoaFisica *> pessoas_fisicas() const {
        return pessoasFisicas;
    }

    [[nodiscard]] std::list<PessoaJuridica *> pessoas_juridicas() const {
        return pessoasJuridicas;
    }

    [[nodiscard]] std::list<PessoaJuridica *> lojas1() const {
        return lojas;
    }

    [[nodiscard]] std::list<Festa *> festas1() const {
        return festas;
    }

    void add(PessoaFisica * pf);
    void add(PessoaJuridica * pj);
    void add(Loja *lj);
    void add(Festa *fe);
};

} // Sistema

#endif //CONTROLE_H
