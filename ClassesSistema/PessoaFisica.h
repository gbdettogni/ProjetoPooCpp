//
// Created by betelgeuse on 15/03/25.
//

#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H
#include <list>
#include <string>

#include "Pessoa.h"

namespace Sistema {

class PessoaFisica: public Pessoa {
private:
    static std::list<PessoaFisica> pessoasFisicas;
    time_t dataNascimento;
    std::string cpf;
    double poupanca;
    double salario;
    double gastos;

public:
    PessoaFisica(const std::string &id, const std::string &nome, const std::string &telefone,
        const std::string &endereco, time_t data_nascimento,
        const std::string &cpf, double poupanca, double salario, double gastos)
        : Pessoa(id, nome, telefone, endereco),
          dataNascimento(data_nascimento),
          cpf(cpf),
          poupanca(poupanca),
          salario(salario),
          gastos(gastos) {
    }

    void addToList();

    void imprimeSujeito();
};

} // Sistema

#endif //PESSOAFISICA_H
