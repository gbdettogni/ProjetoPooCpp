//
// Created by betelgeuse on 20/03/25.
//

#include "Compra.h"

namespace Sistema {
    void Compra::imprimeCompras() const {
        printf("Compra: %s\n", nomeProduto.c_str());
    }

    Compra::Compra(const string &nome_produto, int _quantidade, double preco_unidade, Loja *_loja, Parcela *_parcela) {
        nomeProduto = nome_produto;
        quantidade = _quantidade;
        precoUnidade = preco_unidade;
        loja = _loja;
        parcela = _parcela;
    }

    double Compra::getPreco(){
        return precoUnidade * quantidade;
    }
} // Sistema