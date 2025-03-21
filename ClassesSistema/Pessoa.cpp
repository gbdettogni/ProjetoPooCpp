//
// Created by betelgeuse on 15/03/25.
//

#include "Pessoa.h"
using namespace std;

namespace Sistema {
    void Pessoa::func(){
        std::cout << "Pessoa" << std::endl;
    }

    string Pessoa::getNome(){
        return this->nome;
    }

} // Sistema