//
// Created by betelgeuse on 20/03/25.
//

#ifndef FESTA_H
#define FESTA_H
#include <list>
#include <string>

#include "Parcela.h"

namespace Sistema {

class Festa {
private:
     std::string local;
     double precoPago;
     time_t data;
     std::string horario;
     std::list<std::string> listaConvidados;
     Parcela parcela;

public:
     Festa(const std::string &local, double preco_pago, time_t data, const std::string &horario,
          const std::list<std::string> &lista_convidados, const Parcela &parcela)
          : local(local),
            precoPago(preco_pago),
            data(data),
            horario(horario),
            listaConvidados(lista_convidados),
            parcela(parcela) {
     }

     ~Festa() = default;

     void imprimeFesta();
};

} // Sistema

#endif //FESTA_H
