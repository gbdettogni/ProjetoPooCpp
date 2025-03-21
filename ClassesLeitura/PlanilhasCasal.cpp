#include "PlanilhasCasal.hpp"

#include <format>

#include "../ClassesAjudantes/Tokenizer.hpp"
#include "../ClassesAjudantes/DateUtils.hpp"
#include "../ClassesAjudantes/NumberUtils.hpp"
#include "../ClassesSistema/PessoaFisica.h"
#include "../ClassesSistema/Casal.hpp"

#include <fstream>
#include <iostream>

using namespace std;
using namespace Sistema;

namespace Leitura
{
    void PlanilhasCasal::lePlanilhaLares(const string &pasta, Controle* c){
        fstream arq;
        arq.open(pasta + "lares.csv", ios::in);
        string linha;
        if (arq.is_open())
        {
            while (!arq.eof())
            {
                getline(arq, linha);
                std::cout << linha << std::endl;
                auto t = Tokenizer(linha, ';');
                while (t.hasNext())
                {
                    string  idLar = t.next(), idPessoa1 = t.next(),
                            idPessoa2 = t.next(), rua = t.next();
                    int numero = stoi(t.next());
                    string complemento = t.next();
                    
                    PessoaFisica    *p1 = Controle::getPessoaFisica(idPessoa1),
                                    *p2 = Controle::getPessoaFisica(idPessoa2);

                    if(p1 != nullptr && p2 != nullptr){
                        Casal* c = Controle::getCasal(idPessoa1,idPessoa2);
                        if (c == nullptr)
                        {
                            c = new Casal(p1,p2);
                            Controle::add(idPessoa1, c);
                        }
                        Lar *l = new Lar(rua,complemento,numero);
                        Controle::add(idLar, l);
                        c->setLar(l);
                    }else
                    {
                        //EXCEPTION PESSOA INEXISTENTE
                    }                                                          
                }
            }
        }
    }

    void lePlanilhaCasamentos(const string &pasta, Controle*){
        fstream arq;
        arq.open(pasta + "casamentos.csv", ios::in);
        string linha;
        if (arq.is_open())
        {
            while (!arq.eof())
            {
                getline(arq, linha);
                std::cout << linha << std::endl;
                auto t = Tokenizer(linha, ';');
                while (t.hasNext())
                {
                    string  idCasamento = t.next(), idPessoa1 = t.next(),
                            idPessoa2 = t.next();
                    time_t data = cpp_util::parseDate(t.next(), cpp_util::DATE_FORMAT_PT_BR_SHORT);
                    string hora = t.next(), local = t.next();
                    
                    PessoaFisica    *p1 = Controle::getPessoaFisica(idPessoa1),
                                    *p2 = Controle::getPessoaFisica(idPessoa2);

                    if(p1 != nullptr && p2 != nullptr){
                        Casal* c = Controle::getCasal(idPessoa1,idPessoa2);
                        if (c == nullptr)
                        {
                            c = new Casal(p1,p2);
                            Controle::add(idPessoa1, c);
                        }
                        Casamento *casamento = new Casamento(local, data, hora);
                        Controle::add(idCasamento, casamento);
                        c->setCasamento(casamento);
                    }else
                    {
                        //EXCEPTION PESSOA INEXISTENTE
                    }                   
                }                
            }            
        }
    }
}