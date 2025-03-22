#include "PlanilhasCasal.hpp"

#include <format>

#include "../ClassesAjudantes/Tokenizer.hpp"
#include "../ClassesAjudantes/DateUtils.hpp"
#include "../ClassesAjudantes/NumberUtils.hpp"
#include "../ClassesSistema/PessoaFisica.h"
#include "../ClassesSistema/Controle.h"
#include "../ClassesSistema/Casal.hpp"
#include "../ClassesException/Exception.hpp"

#include <fstream>
#include <iostream>

using namespace std;
using namespace Sistema;

namespace Leitura
{
    void PlanilhasCasal::lePlanilhaLares(const string &pasta, Controle* con) {
        fstream arq;
        arq.open(pasta + "lares.csv", ios::in);
        string linha;
        if (arq.is_open())
        {
            while (!arq.eof())
            {
                getline(arq, linha);
                auto t = Tokenizer(linha, ';');
                while (t.hasNext())
                {
                    string idLar = t.next();
                    if(con->getLar(idLar) != nullptr){
                        throw Exc::idRepetidoExcecao("ID repetido " + idLar + " na classe Lar.");
                    }
                    if (idLar.length() <3) {
                        break;
                    }
                    string  idPessoa1 = t.next(),
                            idPessoa2 = t.next(),
                            rua = t.next();

                    int numero = stoi(t.next());
                    string complemento = t.next();
                    
                    PessoaFisica    *p1 = con->getPessoaFisica(idPessoa1),
                                    *p2 = con->getPessoaFisica(idPessoa2);

                    if(p1 != nullptr && p2 != nullptr){
                        Casal* c = con->getCasal(idPessoa1,idPessoa2);
                        if (c == nullptr)
                        {
                            c = new Casal(p1,p2);
                            con->add(idPessoa1, c);
                        }
                        Lar *l = new Lar(rua,complemento,numero);
                        con->add(idLar, l);
                        c->setLar(l);
                    }else
                    {
                        if(con->getPessoaFisica(idPessoa1) == nullptr){
                            if(con->getPessoaFisica(idPessoa2) == nullptr){
                                throw Exc::idNaoExisteExcecao("ID(s) de Pessoa " + idPessoa1 + " " + idPessoa2 + " não cadastrado no Lar de ID " + idLar + ".");
                            }else{
                                throw Exc::idNaoExisteExcecao("ID(s) de Pessoa " + idPessoa1 + " não cadastrado no Lar de ID " + idLar + ".");
                            }
                        } else throw Exc::idNaoExisteExcecao("ID(s) de Pessoa " + idPessoa2 + " não cadastrado no Lar de ID " + idLar + ".");
                    }                                                          
                }
            }
        }
    }

    void PlanilhasCasal::lePlanilhaCasamentos(const string &pasta, Controle* con) {
        fstream arq;
        arq.open(pasta + "casamentos.csv", ios::in);
        string linha;
        if (arq.is_open())
        {
            while (!arq.eof())
            {
                getline(arq, linha);
                auto t = Tokenizer(linha, ';');
                while (t.hasNext())
                {
                    string  idCasamento = t.next(), idPessoa1 = t.next(),
                            idPessoa2 = t.next();
                    
                    if(con->getCasamento(idCasamento) != nullptr){
                        throw Exc::idRepetidoExcecao("ID repetido " + idCasamento + " na classe Casamento.");
                    }

                    time_t data = cpp_util::parseDate(t.next(), cpp_util::DATE_FORMAT_PT_BR_SHORT);
                    string hora = t.next(), local = t.next();
                    
                    PessoaFisica    *p1 = con->getPessoaFisica(idPessoa1),
                                    *p2 = con->getPessoaFisica(idPessoa2);

                    if(p1 != nullptr && p2 != nullptr){
                        Casal* c = con->getCasal(idPessoa1,idPessoa2);
                        if (c == nullptr)
                        {
                            c = new Casal(p1,p2);
                            con->add(idPessoa1, c);
                        }
                        Casamento *casamento = new Casamento(local, data, hora);
                        con->add(idCasamento, casamento);
                        c->setCasamento(casamento);
                    }else
                    {
                        if(con->getPessoaFisica(idPessoa1) == nullptr){
                            if(con->getPessoaFisica(idPessoa2) == nullptr){
                                throw Exc::idNaoExisteExcecao("ID(s) de Pessoa " + idPessoa1 + " " + idPessoa2 + " não cadastrado no Casamento de ID " + idCasamento + ".");
                            }else{
                                throw Exc::idNaoExisteExcecao("ID(s) de Pessoa " + idPessoa1 + " não cadastrado no Casamento de ID " + idCasamento + ".");
                            }
                        } else throw Exc::idNaoExisteExcecao("ID(s) de Pessoa " + idPessoa2 + " não cadastrado no Casamento de ID " + idCasamento + ".");
                    }                   
                }                
            }            
        }
    }
}