//
// Created by betelgeuse on 20/03/25.
//

#include "Controle.h"

#include <format>

#include "Loja.h"
#include "../ClassesAjudantes/DateUtils.hpp"

namespace Sistema {
    Controle::Controle() {
    }

    void Controle::somaParcelas() {
        for (const auto & iter : casais1())
        {
            time_t saved = iter.second->somadorParcelas();
            if (saved < inicioDosTempos) {
                inicioDosTempos = saved;
            }
        }
    }

    void Controle::processaParcelas() {
        string data = cpp_util::formatDate(inicioDosTempos, cpp_util::DATE_FORMAT_PT_BR_SHORT);
        bool ativo;
        while (true){
            ativo = false;
            for (const auto & iter : casais1())
            {
                time_t dataAtual = cpp_util::parseDate(data, cpp_util::DATE_FORMAT_PT_BR_SHORT);
                if (iter.second->processaParcelas(dataAtual)) {
                    ativo = true;
                }
            }
            if (!ativo) {
                return;
            }
            data = nextData(data);
        }
    }

    string Controle::nextData(string data) {
        int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string novaData;
        int dia, mes, ano;
        mes = stoi(data.substr(3, 2)) + 1;
        ano = stoi(data.substr(6, 4));
        if (mes == 13) {
            mes = 1;
            ano++;
        }
        if (mes == 2 && ano % 4 == 0) {
            dia = 29;
        }else {
            dia = (dias[mes - 1]);
        }
        //cout << dia << endl;
        if (mes <= 9) {
            novaData = format("{}/0{}/{}", dia, mes, ano);
        }
        else{
            novaData = format("{}/{}/{}", dia, mes, ano);
        }
        return novaData;
    }

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

    void Controle::imprimeCasais() {
        for (auto & iter : casais1())
        {
            const auto item = iter.second; // pointer to Node
            item->imprimeCasal();
        }
    }


} // Sistema