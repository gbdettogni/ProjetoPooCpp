#ifndef CASAL_H
#define CASAL_H
#include <string>
#include <unordered_map>

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

    double getGastoTotal();

    PessoaFisica *getPessoa1();

    PessoaFisica *getPessoa2();

    void processaGastoTotal();

    void processaCasamentoConjunto(unordered_map<string, Festa*> festas);

    friend ostream& operator<< (ostream &stream, Casal *casal);

    static bool comparaCasal(Casal *casal1, Casal *casal2);

    static void existo();
};


}


#endif // !CASAL_H