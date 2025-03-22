#include "Casamento.hpp"

#include "Festa.h"
#include <iostream>
#include "../ClassesAjudantes/DateUtils.hpp"

namespace Sistema{
    void Casamento::imprimeCasamento() const {
        printf("Tem casamento\n");
        printf("Local: %s\n", local.c_str());
        cout << "Data: " + cpp_util::formatDate(data, cpp_util::DATE_FORMAT_PT_BR_SHORT) << endl;
        printf("Hora: %s\n", hora.c_str());
        if(festa != NULL){
            festa->imprimeFesta();
        }
    }
}
