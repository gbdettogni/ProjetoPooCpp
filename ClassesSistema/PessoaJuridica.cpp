//
// Created by betelgeuse on 15/03/25.
//

#include "PessoaJuridica.h"

namespace Sistema {
    void PessoaJuridica::imprimeSujeito() const {
        printf("Nome: %s\nEndereço: %s\nTelefone: %s\nCNPJ: %s\n", nome.c_str(), endereco.c_str(), telefone.c_str(), cnpj.c_str());
    }

} // Sistema