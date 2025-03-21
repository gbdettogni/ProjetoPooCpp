//
// Created by betelgeuse on 20/03/25.
//

#include "Tarefa.h"

namespace Sistema {
    void Tarefa::imprimeTarefa() const {
        printf("Tarefa: %f %d\n", preco, prazo);
    }
} // Sistema