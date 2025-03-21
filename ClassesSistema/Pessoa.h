//
// Created by betelgeuse on 15/03/25.
//

#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <ostream>
#include <string>

using namespace std;
namespace Sistema {

class Pessoa {
protected:
    string id;
    string nome;
    string telefone;
    string endereco;
    bool prestador;
    double valorRecebido;
public:
    Pessoa(const string &id, const string &nome, const string &telefone, const string &endereco
        )
        : id(id),
          nome(nome),
          telefone(telefone),
          endereco(endereco)

          {
    }

    string getNome();

    ~Pessoa() = default;

    static void func();
};

} // Sistema

#endif //PESSOA_H
