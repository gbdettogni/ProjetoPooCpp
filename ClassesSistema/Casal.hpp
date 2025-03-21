#ifndef CASAL_H
#define CASAL_H
#include <string>

using namespace std;
#include "PessoaFisica.h"

namespace Sistema
{
class Casal {
private:
    PessoaFisica pessoa1, pessoa2;    
    //Casamento casamento;
    //Lar lar;
    //list<Parcela> parcelasTotais;

    double  poupancaConjunta,
            salarioConjunto,
            gastoConjunto,
            gastoTotal;

    int casamentosConjuntos;

public:
    Casal(/* args */);
    ~Casal() = default;
    static void existo();
};


}


#endif // !CASAL_H