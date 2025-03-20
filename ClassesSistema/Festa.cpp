//
// Created by betelgeuse on 20/03/25.
//

#include "Festa.h"
#include "../ClassesAjudantes/DateUtils.hpp"


namespace Sistema {
    void Festa::imprimeFesta() {
        printf("Local: %s, preco: %f, data: %s\n", local.c_str(), precoPago, cpp_util::formatDate(data, cpp_util::DATE_FORMAT_PT_BR_SHORT).c_str());
    }
} // Sistema