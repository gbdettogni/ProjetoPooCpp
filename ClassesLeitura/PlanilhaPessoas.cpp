//
// Created by betelgeuse on 15/03/25.
//

#include "PlanilhaPessoas.h"

#include <format>

#include "../ClassesAjudantes/Tokenizer.hpp"
#include "../ClassesAjudantes/DateUtils.hpp"
#include "../ClassesAjudantes/NumberUtils.hpp"
#include "../ClassesSistema/PessoaFisica.h"

#include <fstream>
#include <iostream>

using namespace Sistema;

namespace Leitura {
    list<PessoaFisica> PlanilhaPessoas::lePlanilhaPessoas(const std::string &pasta) {
        list<PessoaFisica> pessoasFisicas;

        fstream arq;
        arq.open(pasta + "pessoas.csv", std::ios::in);
        string linha;
        if (arq.is_open()) {
            while (! arq.eof() ) {
                getline (arq, linha);
                cout << linha << endl;
                auto t = Tokenizer(linha, ';');
                while (t.hasNext()) {
                    string id = t.next(),
                        tipo = t.next(),     //dados comuns a Pessoa
                        nome = t.next(),
                        telefone = t.next(),
                        endereco = t.next();
                    if(!tipo.compare("F")){       //dados adicionais PessoaFísica
                        string cpf = t.next();

                        time_t dataNascimento = cpp_util::parseDate(cpf, cpp_util::DATE_FORMAT_PT_BR_SHORT);

                        double poupanca, salario, gastos;
                            poupanca = parseDouble(t.next(), LOCALE_PT_BR);
                            salario = parseDouble(t.next(), LOCALE_PT_BR);
                            gastos = parseDouble(t.next(), LOCALE_PT_BR);

                        auto pf = new PessoaFisica(id, nome, telefone, endereco, dataNascimento, cpf, poupanca,
                                                            salario, gastos);

                        pessoasFisicas.push_back(*pf);
                    }
                }
            }
        }
        return pessoasFisicas;
    }
} // Leitura