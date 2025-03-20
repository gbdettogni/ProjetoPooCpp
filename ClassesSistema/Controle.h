//
// Created by betelgeuse on 20/03/25.
//

#ifndef CONTROLE_H
#define CONTROLE_H
#include <list>

#include "PessoaFisica.h"
#include "PessoaJuridica.h"

namespace Sistema {

class Controle {
    std::list<PessoaFisica*> pessoasFisicas;
    std::list<PessoaJuridica*> pessoasJuridicas;

public:
    Controle() = default;

    ~Controle() = default;

    [[nodiscard]] std::list<PessoaFisica *> pessoas_fisicas() const {
        return pessoasFisicas;
    }

    [[nodiscard]] std::list<PessoaJuridica *> pessoas_juridicas() const {
        return pessoasJuridicas;
    }

    void add(PessoaFisica * pf);
    void add(PessoaJuridica * pj);
};

} // Sistema

#endif //CONTROLE_H
