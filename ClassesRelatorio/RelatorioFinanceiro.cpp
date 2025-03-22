//
// Created by betelgeuse on 22/03/25.
//

#include "RelatorioFinanceiro.h"

#include <format>

#include "../ClassesSistema/Casal.hpp"
#include "../ClassesSistema/Controle.h"

#include <fstream>

#include "../ClassesAjudantes/NumPunctPTBR.hpp"
#include "../ClassesAjudantes/NumberUtils.hpp"

namespace Relatorio {
    void RelatorioFinanceiro::geraRelatorioFinanceiro(const std::string &pasta, Sistema::Controle * con,  list<cpp_utils::Pair*> cpfs) {
        ofstream arq(pasta + "saida/1-planejamento.csv");


        if(arq.is_open()){
            for (cpp_utils::Pair *p : cpfs) {
                Sistema::Casal* c = con->getCasal(p->member1, p->member2);
                list<double> hist = c->getHistorico();
                auto* rf = new RelatorioFinanceiro("", "");
                string data = cpp_util::formatDate(c->getInicioDosTempos(), cpp_util::DATE_FORMAT_PT_BR_SHORT);
                rf->meses = "Nome 1;Nome 2";
                rf->gastos = format("{};{}", c->getPessoa1()->getNome(), c->getPessoa2()->getNome());
                for (double h : hist) {
                    rf->meses = format("{};{}", rf->meses, data.substr(3, 7));
                    data = gambiarra(data);
                    rf->gastos = format("{};R$ {}", rf->gastos, formatDoubleCurrency(h, LOCALE_PT_BR));
                }
                rf->meses = format("{}\n", rf->meses);

                arq << rf << endl;

                delete rf;
            }
        }
    }

    string RelatorioFinanceiro::gambiarra(string data) {
        int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string novaData;
        int dia, mes, ano;
        mes = stoi(data.substr(3, 2)) + 1;
        ano = stoi(data.substr(6, 4));
        if (mes == 13) {
            mes = 1;
            ano++;
        }
        if (mes == 2 && ano % 4 == 0) {
            dia = 29;
        }else {
            dia = (dias[mes - 1]);
        }
        // cout << dia << endl;
        if (mes <= 9) {
            novaData = std::format("{}/0{}/{}", dia, mes, ano);
        }
        else{
            novaData = std::format("{}/{}/{}", dia, mes, ano);
        }
        return novaData;
    }

    ostream& operator<<(ostream& stream, RelatorioFinanceiro* rf){
        stream.write(rf->meses.c_str(), rf->meses.size());
        stream.write(rf->gastos.c_str(), rf->gastos.size());
        return stream;
    }

} // Relatorio