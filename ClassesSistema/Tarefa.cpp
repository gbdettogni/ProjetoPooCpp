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

    Tarefa::Tarefa(const string &_id, double _preco, time_t _data, int _prazo, Pessoa *_prestador, Parcela *_parcela) {
        id = _id;
        preco = _preco;
        data = _data;
        prazo = _prazo;
        prestador = _prestador;
        parcela = _parcela;
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