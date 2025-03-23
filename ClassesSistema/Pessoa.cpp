//
// Created by betelgeuse on 15/03/25.
//

#include "Pessoa.h"
using namespace std;

namespace Sistema {
    void Pessoa::func(){
        std::cout << "Pessoa" << std::endl;
    }

    Pessoa::Pessoa(const string &_id, const string &_nome, const string &_telefone, const string &_endereco) {
        id = _id;
        nome = _nome;
        telefone = _telefone;
        endereco = _endereco;
    }

    string Pessoa::getNome(){
        return this->nome;
    }

} // Sistema