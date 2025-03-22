//
// Created by betelgeuse on 20/03/25.
//

#include "Tarefa.h"

namespace Sistema {
    void Tarefa::imprimeTarefa() const {
        printf("Tarefa: %f %d\n", preco, prazo);
        for (Compra* c : compras) {
            c->imprimeCompras();
        }
    }

    void Tarefa::addCompra(Compra* cp) {
        compras.push_back(cp);
    }

    double Tarefa::getPrecoTarefa(){
        double precoTarefa = preco;
        for(Compra *c : compras){
            precoTarefa += c->getPreco();
        }
        return precoTarefa;
    }

    list<Parcela *> Tarefa::getParcelasTarefasCompras() {
        list<Parcela *> parcelas;
        parcelas.push_back(parcela);
        for (Compra* c : compras) {
            parcelas.push_back(c->getParcela());
        }
        return parcelas;
    }

    time_t Tarefa::getData() {
        return parcela->getData();
    }
} // Sistema