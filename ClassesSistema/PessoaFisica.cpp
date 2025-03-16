//
// Created by betelgeuse on 15/03/25.
//

#include "PessoaFisica.h"

namespace Sistema {
    void PessoaFisica::addToList(){
        std::cout << nome << std::endl;
    }

    void PessoaFisica::imprimeSujeito() {
        printf("Nome: %s\nEndereço: %s\nTelefone: %s\nCPF: %s\nGasto Mensal: %f\n", nome.c_str(), endereco.c_str(), telefone.c_str(), cpf.c_str(), gastos);
    }
} // Sistema