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

using namespace Sistema;
using namespace Leitura;

int main() {
    auto* con = new Controle();
    PlanilhaPessoas::lePlanilhaPessoas("/home/betelgeuse/CLionProjects/ProjetoPooCpp/casos/01/", con);
    PlanilhasCasal::lePlanilhaLares("/home/betelgeuse/CLionProjects/ProjetoPooCpp/casos/01/", con);
    PlanilhasCasal::lePlanilhaCasamentos("/home/betelgeuse/CLionProjects/ProjetoPooCpp/casos/01/", con);
    PlanilhaFestas::lePlanilhaFestas("/home/betelgeuse/CLionProjects/ProjetoPooCpp/casos/01/", con);
    PlanilhaTarefas::lePlanilhaTarefas("/home/betelgeuse/CLionProjects/ProjetoPooCpp/casos/01/", con);
    PlanilhaCompras::lePlanilhaCompras("/home/betelgeuse/CLionProjects/ProjetoPooCpp/casos/01/", con);

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
