//
// Created by betelgeuse on 20/03/25.
//

#ifndef COMPRA_H
#define COMPRA_H
#include <string>

#include "Loja.h"
#include "Parcela.h"

using namespace std;

namespace Sistema {

class Compra {
private:
    string nomeProduto;
    int quantidade;
    double precoUnidade;
    Loja* loja;
    Parcela* parcela;

public:
    Compra(const string &nome_produto, int quantidade, double preco_unidade, Loja *loja, Parcela *parcela);

    double getPreco();

    ~Compra() {
        delete parcela;
    };

    [[nodiscard]] Parcela * getParcela() const {
        return parcela;
    }

    void imprimeCompras() const;
};

} // Sistema

#endif //COMPRA_H
