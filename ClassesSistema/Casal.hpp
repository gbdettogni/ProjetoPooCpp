#ifndef CASAL_H
#define CASAL_H
#include <string>

using namespace std;
#include "PessoaFisica.h"
#include "Lar.hpp"
#include "Casamento.hpp"

namespace Sistema
{
class Casal {
private:
    PessoaFisica *pessoa1, *pessoa2;    
    Casamento *casamento;
    Lar *lar;
    //list<Parcela> parcelasTotais;

    double  poupancaConjunta,
            salarioConjunto,
            gastoConjunto,
            gastoTotal;

    int casamentosConjuntos;

public:
    Casal(PessoaFisica *p1, PessoaFisica *p2);
    void setLar(Lar *l);
    void setCasamento(Casamento *c);
    ~Casal() {
        delete casamento;
        delete lar;
    };

    void imprimeCasal();

    static void existo();
};


}


#endif // !CASAL_H