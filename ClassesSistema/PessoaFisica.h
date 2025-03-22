//
// Created by betelgeuse on 15/03/25.
//

#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H
#include <list>
#include <string>

#include "Pessoa.h"

using namespace std;
namespace Sistema {

class PessoaFisica: public Pessoa {
private:
    time_t dataNascimento;
    string cpf;
    double poupanca;
    double salario;
    double gastos;

public:
    PessoaFisica(const string &id, const string &nome, const string &telefone,
        const string &endereco, time_t data_nascimento,
        const string &cpf, double poupanca, double salario, double gastos)
        : Pessoa(id, nome, telefone, endereco),
          dataNascimento(data_nascimento),
          cpf(cpf),
          poupanca(poupanca),
          salario(salario),
          gastos(gastos) {
    }

    ~PessoaFisica() = default;

    void addToList();

    void imprimeSujeito();

    [[nodiscard]] double getPoupanca() const {
        return poupanca;
    }

    [[nodiscard]] double getSalario() const {
        return salario;
    }

    [[nodiscard]] double getGastos() const {
        return gastos;
    }

    [[nodiscard]] string getCpf() const {
        return cpf;
    }
};

} // Sistema

#endif //PESSOAFISICA_H
