//
// Created by betelgeuse on 22/03/25.
//

#ifndef RELATORIOFINANCEIRO_H
#define RELATORIOFINANCEIRO_H
#include <string>
#include "../ClassesSistema/Controle.h"
#include "../ClassesAjudantes/Pair.h"


namespace Relatorio {

class RelatorioFinanceiro {
    string meses;
    string gastos;

public:
    RelatorioFinanceiro(const string &meses, const string &gastos);
    friend ostream& operator<< (ostream &stream, RelatorioFinanceiro *rf);
    static void geraRelatorioFinanceiro(const std::string &pasta, Sistema::Controle * con, list<cpp_utils::Pair*> cpfs);

private:
    static string nextData(string data);

};

} // Relatorio

#endif //RELATORIOFINANCEIRO_H
