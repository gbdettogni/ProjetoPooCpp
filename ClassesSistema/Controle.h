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
    string gambiarra(string data);
    unordered_map<string, PessoaFisica*> pessoasFisicas;
     unordered_map<string, PessoaJuridica*> pessoasJuridicas;
     unordered_map<string, Loja*> lojas;
     unordered_map<string, Festa*> festas;
     unordered_map<string, Casal*> casais;
     unordered_map<string, Casamento*> casamentos;
     unordered_map<string, Lar*> lares;
     unordered_map<string, Tarefa*> tarefas;
     unordered_map<string, Compra*> compras;
    time_t inicioDosTempos = cpp_util::parseDate("16/10/2099", cpp_util::DATE_FORMAT_PT_BR_SHORT);

public:
    Controle() = default;

    ~Controle() {
        for (const auto & iter : casais1())
        {
            delete iter.second;
        }
        for (auto & iter : pessoasFisicas)
        {
            delete iter.second;
        }
        for (auto & iter : pessoasJuridicas)
        {
            delete iter.second;
        }
        for (auto & iter : lojas)
        {
            delete iter.second;
        }
    }

    void somaParcelas();


     void processaParcelas();;

     [[nodiscard]] unordered_map<string, PessoaFisica *> pessoas_fisicas() const {
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

    [[nodiscard]] unordered_map<string, Casamento *> casamentos1() const {
        return casamentos;
    }

     [[nodiscard]] unordered_map<string, Casal *> casais1() const {
         return casais;
     }

    void add(string id, PessoaFisica * pf);
    void add(string id, Casal *c);
    void add(string id, Casamento *c);
    void add(string id, Lar *l);
    void add(string id, PessoaJuridica * pj);
    void add(string id, Loja *lj);
    void add(string id, Festa *fe);
    void add(string id, Tarefa * pf);
    void add(string id, Compra * pf);
    
     Casal* getCasal(string id1, string id2);
     PessoaFisica* getPessoaFisica(string id);
     PessoaJuridica* getPessoaJuridica(string id);
     Loja* getLoja(string id);
     Festa* getFesta(string id);
     Casamento* getCasamento(string id);
     Lar* getLar(string id);
     Tarefa* getTarefa(string id);
     Compra* getCompra(string id);

     void imprimeCasais();


};

} // Sistema

#endif //CONTROLE_H
