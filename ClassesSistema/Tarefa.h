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
     Pessoa* prestador;
     list<Compra*> compras;
     Parcela* parcela;
public:
     Tarefa(const string &id, double preco, time_t data, int prazo, Pessoa *prestador, Parcela *parcela);

     double getPrecoTarefa();

     void imprimeTarefa() const;

     void addCompra(Compra *cp);

     ~Tarefa() {
          delete parcela;
          for (Compra *cp : compras) {
               delete cp;
          }
     }

     list<Parcela *> getParcelasTarefasCompras();

     time_t getData();;
};

} // Sistema

#endif //TAREFA_H
