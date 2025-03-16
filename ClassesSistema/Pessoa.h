//
// Created by betelgeuse on 15/03/25.
//

#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <ostream>
#include <string>

namespace Sistema {

class Pessoa {
protected:
    std::string id;
    std::string nome;
    std::string telefone;
    std::string endereco;
    bool prestador;
    double valorRecebido;
public:
    Pessoa(const std::string &id, const std::string &nome, const std::string &telefone, const std::string &endereco
        )
        : id(id),
          nome(nome),
          telefone(telefone),
          endereco(endereco)

          {
    }

    ~Pessoa() = default;

    static void func();
};

} // Sistema

#endif //PESSOA_H
