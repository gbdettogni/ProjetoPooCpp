//
// Created by betelgeuse on 20/03/25.
//

#include "Parcela.h"

#include <cstdio>
#include <iostream>
#include <ostream>

#include "../ClassesAjudantes/DateUtils.hpp"

namespace Sistema {
    void Parcela::imprimeParcela() {
        printf("Parcela no valor de %f, comecando em %s, por %d meses\n", valor, cpp_util::formatDate(dataInicio, cpp_util::DATE_FORMAT_PT_BR_SHORT).c_str(), numInicial);
    }

    bool Parcela::ativa(time_t time) {
        if (time >= dataInicio) {
            if (numAtual == 0) {
                return false;
            }
            numAtual --;
            return true;
        }
        return false;
    }

    bool Parcela::existente(Parcela * p) {
        if (p->numAtual <= 0) {
            return true;
        }
        return false;
    }

    time_t Parcela::getData() {
        return dataInicio;
    }
} // Sistema