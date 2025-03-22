#include <iostream>

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

using namespace Sistema;
using namespace Leitura;
using namespace Relatorio;

int main(int argc, char *argv[]) {
    auto* con = new Controle();
    PlanilhaPessoas::lePlanilhaPessoas(argv[1], con);
    PlanilhasCasal::lePlanilhaLares(argv[1], con);
    PlanilhasCasal::lePlanilhaCasamentos(argv[1], con);
    PlanilhaFestas::lePlanilhaFestas(argv[1], con);
    PlanilhaTarefas::lePlanilhaTarefas(argv[1], con);
    PlanilhaCompras::lePlanilhaCompras(argv[1], con);

    //  for (auto & iter : con->pessoas_fisicas())
    //  {
    //      const auto item = iter.second; // pointer to Node
    //      item->imprimeSujeito();
    //  }
    //
    // for (auto & iter : con->pessoas_juridicas())
    // {
    //     const auto item = iter.second; // pointer to Node
    //     item->imprimeSujeito();
    // }
    //
    // for (auto & iter : con->lojas1())
    // {
    //     const auto item = iter.second; // pointer to Node
    //     item->imprimeSujeito();
    // }
    //
    // for (auto & iter : con->festas1())
    // {
    //     const auto item = iter.second; // pointer to Node
    //     item->imprimeFesta();
    // }
    //
    // for (auto & iter : con->tarefas1())
    // {
    //     const auto item = iter.second; // pointer to Node
    //     item->imprimeTarefa();
    // }
    //
    // for (auto & iter : con->compras1())
    // {
    //     const auto item = iter.second; // pointer to Node
    //     item->imprimeCompras();
    // }
    //
    // for (auto & iter : con->casais1())
    // {
    //     const auto item = iter.second; // pointer to Node
    //     item->imprimeCasal();
    // }

    con->imprimeCasais();

    RelatorioCasais::geraRelatorioCasais(argv[1], con);
     /*
     for (auto item: con->pessoas_juridicas()) {
         item->imprimeSujeito();
         delete item;
     }
     for (auto item: con->lojas1()) {
         item->imprimeSujeito();
         delete item;
     }

     for (auto item: con->festas1()) {
         item->imprimeFesta();
         delete item;
     }

     for (auto item: con->tarefas1()) {
         item->imprimeTarefa();
         delete item;
     }

     for (auto item: con->compras1()) {
         item->imprimeCompras();
         delete item;
     } */

    delete con;
    return 0;
}
