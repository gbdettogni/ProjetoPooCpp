//
// Created by betelgeuse on 20/03/25.
//

#include "Compra.h"

namespace Sistema {
    void Compra::imprimeCompras() const {
        printf("Compra: %s\n", nomeProduto.c_str());
    }
} // Sistema