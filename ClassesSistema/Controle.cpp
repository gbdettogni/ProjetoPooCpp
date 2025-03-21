//
// Created by betelgeuse on 20/03/25.
//

#include "Controle.h"
#include "Loja.h"

namespace Sistema {
    void Controle::add(string id, PessoaFisica *pf) {
        pessoasFisicas.insert(pair<string,PessoaFisica*>(id,pf));
    }

    void Controle::add(string id, Casal *c){
        casais.insert(pair<string,Casal*>(id,c));
    }

    void Controle::add(string id, Casamento *c){
        casamentos.insert(pair<string,Casamento*>(id,c));
    }

    void Controle::add(string id, Lar *l){
        lares.insert(pair<string,Lar*>(id,l));
    }

    void Controle::add(string id, PessoaJuridica *pj) {
        pessoasJuridicas.insert(pair<string,PessoaJuridica*>(id,pj));
    }

    void Controle::add(string id, Loja *lj) {
        lojas.insert(pair<string,Loja*>(id,lj));
    }

    void Controle::add(string id, Festa *fe) {
        festas.insert(pair<string,Festa*>(id,fe));
    }

    void Controle::add(string id, Tarefa *tf) {
        tarefas.insert(pair<string,Tarefa*>(id,tf));
    }

    void Controle::add(string id, Compra *cp) {
        compras.insert(pair<string,Compra*>(id,cp));
    }
    
    Casal* Controle::getCasal(string id1, string id2){ //tenta achar o casal no Map por cada um dos ids das pessoas
        if (casais.count(id1) > 0)                          //vai que a entrada do lar/casamento tem os mesmos ids porém invertidos em ordem
        {
            return casais.at(id1);
        }else if (casais.count(id2)>0)
        {
            return casais.at(id2);
        }
        else return nullptr;
    }

    PessoaFisica* Controle::getPessoaFisica(string id){
        if (pessoasFisicas.count(id) > 0)
        return pessoasFisicas.at(id);
        else return nullptr;
    }

    PessoaJuridica* Controle::getPessoaJuridica(string id){
        if (pessoasJuridicas.count(id) > 0)
        return pessoasJuridicas.at(id);
        else return nullptr;
        
    }
    Loja* Controle::getLoja(string id){
        if (lojas.count(id) > 0)
        return lojas.at(id);
        else return nullptr;
        
    }
    Festa* Controle::getFesta(string id){
        if (festas.count(id) > 0)
        return festas.at(id);
        else return nullptr;
        
    }
    Casamento* Controle::getCasamento(string id){
        if (casamentos.count(id) > 0)
        return casamentos.at(id);
        else return nullptr;
        
    }
    Lar* Controle::getLar(string id){
        if (lares.count(id) > 0)
        return lares.at(id);
        else return nullptr;
        
    }
    Tarefa* Controle::getTarefa(string id){
        if (tarefas.count(id) > 0)
        return tarefas.at(id);
        else return nullptr;
        
    }
    Compra* Controle::getCompra(string id){
        if (compras.count(id) > 0)
        return compras.at(id);
        else return nullptr;
        
    }
} // Sistema