//
// Created by betelgeuse on 20/03/25.
//

#ifndef FESTA_H
#define FESTA_H
#include <list>
#include <string>

#include "Parcela.h"

using namespace std;
namespace Sistema {

class Festa {
private:
     string local;
     double precoPago;
     time_t data;
     string horario;
     list<string> listaConvidados;
     Parcela parcela;

public:
     Festa(const string &local, double preco_pago, time_t data, const string &horario,
          const list<string> &lista_convidados, const Parcela &parcela)
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
