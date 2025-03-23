//
// Created by betelgeuse on 20/03/25.
//

#ifndef LOJA_H
#define LOJA_H
#include "PessoaJuridica.h"

namespace Sistema {

class Loja: public PessoaJuridica{
public:
    Loja(const std::string &id, const std::string &nome, const std::string &telefone, const std::string &endereco,
        const std::string &cnpj)
        : PessoaJuridica(id, nome, telefone, endereco, cnpj) {
    }

    ~Loja(){}
};

} // Sistema

#endif //LOJA_H
