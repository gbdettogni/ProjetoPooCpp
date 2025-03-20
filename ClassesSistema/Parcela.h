//
// Created by betelgeuse on 20/03/25.
//

#ifndef PARCELA_H
#define PARCELA_H
#include <ctime>

namespace Sistema {

class Parcela {
private:
    int numInicial;
    int numAtual;
    double valor;
    time_t dataInicio;

public:
    Parcela(int num_inicial, double valor, time_t data_inicio)
        : numInicial(num_inicial),
          valor(valor),
          dataInicio(data_inicio) {
    }
};

} // Sistema

#endif //PARCELA_H
