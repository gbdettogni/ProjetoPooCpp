#ifndef CASAL_H
#define CASAL_H
#include <string>
#include <unordered_map>

#include "../ClassesAjudantes/DateUtils.hpp"

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
    time_t inicioDosTempos = cpp_util::parseDate("16/10/2099", cpp_util::DATE_FORMAT_PT_BR_SHORT);
    //list<Parcela> parcelasTotais;

    double  poupancaConjunta,
            salarioConjunto,
            gastoConjunto,
            gastoTotal;
    list<double> historico;

    int casamentosConjuntos;

    list<Parcela*> somaParcelas;

public:
    [[nodiscard]] time_t getInicioDosTempos() const {
        return inicioDosTempos;
    }

    [[nodiscard]] list<double> getHistorico() const {
        return historico;
    }

    Casal(PessoaFisica *p1, PessoaFisica *p2);
    void setLar(Lar *l);
    void setCasamento(Casamento *c);
    ~Casal() {
        delete casamento;
        delete lar;
    }

    time_t somadorParcelas();

    [[nodiscard]] PessoaFisica * getPessoa1() const {
        return pessoa1;
    }

    bool processaParcelas(time_t dataAtual);;

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