//
// Created by betelgeuse on 15/03/25.
//

#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H
#include <list>

#include "Pessoa.h"

namespace Sistema {

class PessoaJuridica: public Pessoa {

private:
     static std::list<PessoaJuridica> pessoasJuridicas;
     std::string cnpj;

public:
     PessoaJuridica(const std::string &id, const std::string &nome, const std::string &telefone,
          const std::string &endereco, bool prestador, double valor_recebido, const std::string &cnpj)
          : Pessoa(id, nome, telefone, endereco),
            cnpj(cnpj) {
     }
};

} // Sistema

#endif //PESSOAJURIDICA_H
