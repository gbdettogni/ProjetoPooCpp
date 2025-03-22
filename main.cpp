#include <iostream>
#include <fstream>

#include "ClassesLeitura/PlanilhaCompras.h"
#include "ClassesLeitura/PlanilhaFestas.h"
#include "ClassesLeitura/PlanilhaPessoas.h"
#include "ClassesLeitura/PlanilhaTarefas.h"
#include "ClassesLeitura/PlanilhasCasal.hpp"
#include "ClassesSistema/Controle.h"
#include "ClassesSistema/Pessoa.h"
#include "ClassesSistema/PessoaFisica.h"
#include "ClassesLeitura/PlanilhaCompras.h"
#include "ClassesRelatorio/RelatorioCasais.hpp"
#include "ClassesException/Exception.hpp"
#include "ClassesAjudantes/Pair.h"
#include "ClassesAjudantes/StringUtils.hpp"
#include "ClassesAjudantes/Tokenizer.hpp"
#include "ClassesRelatorio/RelatorioFinanceiro.h"

using namespace Sistema;
using namespace Leitura;
using namespace Relatorio;


int main(int argc, char *argv[]) {

    auto* con = new Controle();
    ofstream arq1(string(argv[1]) + "saida/1-planejamento.csv");
    ofstream arq2(string(argv[1]) + "saida/2-estatisticas-prestadores.csv");
    ofstream arq3(string(argv[1]) + "saida/3-estatisticas-casais.csv");
    try
    {
        PlanilhaPessoas::lePlanilhaPessoas(argv[1], con);
        PlanilhasCasal::lePlanilhaLares(argv[1], con);
        PlanilhasCasal::lePlanilhaCasamentos(argv[1], con);
        PlanilhaFestas::lePlanilhaFestas(argv[1], con);
        PlanilhaTarefas::lePlanilhaTarefas(argv[1], con);
        PlanilhaCompras::lePlanilhaCompras(argv[1], con);
        //LEITURA CABREIRA

    list<cpp_utils::Pair *> cpfs;
    while (true) {
        string cpf1;
        string cpf2;
        cin >> cpf1;
        //gambiarra
        cpf1 = Tokenizer(cpf1, ',').next();
        cin >> cpf2;

        if (cpf1.empty()) {
            break;
        }

        auto* p = new cpp_utils::Pair(cpf1, cpf2);
        cout << p->member1 << " & " << p->member2 << endl;
        cpfs.push_back(p);
    }

    con->somaParcelas();
    //con->imprimeCasais();
    con->processaParcelas();

    RelatorioCasais::geraRelatorioCasais(argv[1], con);
    RelatorioFinanceiro::geraRelatorioFinanceiro(argv[1], con, cpfs);
    }
    catch(Exc::Excecao &e)
    {
        cout << e << endl;
    }
    
     

    delete con;
    return 0;
}
