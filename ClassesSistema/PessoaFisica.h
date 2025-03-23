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
        const string &_cpf, double _poupanca, double _salario, double _gastos)
        : Pessoa(id, nome, telefone, endereco) {
        dataNascimento = data_nascimento;
        cpf = _cpf;
        poupanca = _poupanca;
        salario = _salario;
        gastos = _gastos;
    }

    ~PessoaFisica(){}

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
