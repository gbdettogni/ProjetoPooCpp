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
#include "Tarefa.h"
#include "Casamento.hpp"
#include "Lar.hpp"

namespace Sistema {

class Controle {
private:
    static unordered_map<string, PessoaFisica*> pessoasFisicas;
    static unordered_map<string, PessoaJuridica*> pessoasJuridicas;
    static unordered_map<string, Loja*> lojas;
    static unordered_map<string, Festa*> festas;
    static unordered_map<string, Casal*> casais;
    static unordered_map<string, Casamento*> casamentos;
    static unordered_map<string, Lar*> lares;
    static unordered_map<string, Tarefa*> tarefas;
    static unordered_map<string, Compra*> compras;

public:
    Controle() = default;

    ~Controle() = default;

    [[nodiscard]] unordered_map<string, PessoaFisica*> pessoas_fisicas() const {
        return pessoasFisicas;
    }

    [[nodiscard]] unordered_map<string, PessoaJuridica *> pessoas_juridicas() const {
        return pessoasJuridicas;
    }

    [[nodiscard]] unordered_map<string, Loja *> lojas1() const {
        return lojas;
    }

    [[nodiscard]] unordered_map<string, Festa *> festas1() const {
        return festas;
    }

    [[nodiscard]] unordered_map<string, Tarefa *> tarefas1() const {
        return tarefas;
    }

    [[nodiscard]] unordered_map<string, Compra *> compras1() const {
        return compras;
    }

    static void add(string id, PessoaFisica * pf);
    static void add(string id, Casal *c);
    static void add(string id, Casamento *c);
    static void add(string id, Lar *l);
    static void add(string id, PessoaJuridica * pj);
    static void add(string id, Loja *lj);
    static void add(string id, Festa *fe);
    static void add(string id, Tarefa * pf);
    static void add(string id, Compra * pf);
    
    static Casal* getCasal(string id1, string id2);
    static PessoaFisica* getPessoaFisica(string id);
    static PessoaJuridica* getPessoaJuridica(string id);
    static Loja* getLoja(string id);
    static Festa* getFesta(string id);
    static Casamento* getCasamento(string id);
    static Lar* getLar(string id);
    static Tarefa* getTarefa(string id);
    static Compra* getCompra(string id);
};

} // Sistema

#endif //CONTROLE_H
