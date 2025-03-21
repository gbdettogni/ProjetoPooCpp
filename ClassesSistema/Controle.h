//
// Created by betelgeuse on 20/03/25.
//

#ifndef CONTROLE_H
#define CONTROLE_H
#include <list>
#include <unordered_map>

#include "Festa.h"
#include "Loja.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"
#include "Casal.hpp"

using namespace std;
namespace Sistema {

class Controle {
private:
    list<PessoaFisica*> pessoasFisicas;
    list<PessoaJuridica*> pessoasJuridicas;
    list<PessoaJuridica*> lojas;
    list<Festa*> festas;
    unordered_map<string, Casal*> casais;

public:
    Controle() = default;

    ~Controle() = default;

    [[nodiscard]] list<PessoaFisica *> pessoas_fisicas() const {
        return pessoasFisicas;
    }

    [[nodiscard]] list<PessoaJuridica *> pessoas_juridicas() const {
        return pessoasJuridicas;
    }

    [[nodiscard]] list<PessoaJuridica *> lojas1() const {
        return lojas;
    }

    [[nodiscard]] list<Festa *> festas1() const {
        return festas;
    }

    void add(PessoaFisica * pf);
    void add(PessoaJuridica * pj);
    void add(Loja *lj);
    void add(Festa *fe);

    Casal* getCasalById(string &id1, string &id2);
};

} // Sistema

#endif //CONTROLE_H
