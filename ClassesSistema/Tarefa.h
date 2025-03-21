//
// Created by betelgeuse on 20/03/25.
//

#ifndef TAREFA_H
#define TAREFA_H
#include <list>
#include <string>

#include "Compra.h"
#include "Parcela.h"
#include "Pessoa.h"

using namespace std;

namespace Sistema {

class Tarefa {
private:
     string id;
     double preco;
     time_t data;
     int prazo;
     Pessoa prestador;
     list<Compra> compras;
     Parcela parcela;
public:
     Tarefa(const string &id, double preco, time_t data, int prazo, const Pessoa &prestador,
          const Parcela &parcela)
          : id(id),
            preco(preco),
            data(data),
            prazo(prazo),
            prestador(prestador),
            parcela(parcela) {
     }

     void imprimeTarefa() const;
};

} // Sistema

#endif //TAREFA_H
