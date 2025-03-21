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
#include "Casal.hpp"

namespace Sistema {

class Controle {
private:
    list<PessoaFisica*> pessoasFisicas;
    list<PessoaJuridica*> pessoasJuridicas;
    list<PessoaJuridica*> lojas;
    list<Festa*> festas;
    static unordered_map<string, Casal*> casais;
    list<Tarefa*> tarefas;
    list<Compra*> compras;

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

    [[nodiscard]] std::list<Tarefa *> tarefas1() const {
        return tarefas;
    }

    [[nodiscard]] std::list<Compra *> compras1() const {
        return compras;
    }

    void add(PessoaFisica * pf);
    void add(PessoaJuridica * pj);
    void add(Loja *lj);
    void add(Festa *fe);

    static Casal* getCasalById(string &id1, string &id2);
    void add(Tarefa * pf);
    void add(Compra * pf);

};

} // Sistema

#endif //CONTROLE_H
