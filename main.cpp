#include <iostream>

#include "ClassesLeitura/PlanilhaCompras.h"
#include "ClassesLeitura/PlanilhaFestas.h"
#include "ClassesLeitura/PlanilhaPessoas.h"
#include "ClassesLeitura/PlanilhaTarefas.h"
#include "ClassesSistema/Controle.h"
#include "ClassesSistema/Pessoa.h"
#include "ClassesSistema/PessoaFisica.h"
#include "ClassesLeitura/PlanilhaCompras.h"

using namespace Sistema;
using namespace Leitura;

int main() {
    auto* con = new Controle();
    PlanilhaPessoas::lePlanilhaPessoas("/home/betelgeuse/CLionProjects/ProjetoPooCpp/casos/01/", con);
    PlanilhaFestas::lePlanilhaFestas("/home/betelgeuse/CLionProjects/ProjetoPooCpp/casos/01/");
    PlanilhaTarefas::lePlanilhaTarefas("/home/betelgeuse/CLionProjects/ProjetoPooCpp/casos/01/", con);
    PlanilhaCompras::lePlanilhaCompras("/home/betelgeuse/CLionProjects/ProjetoPooCpp/casos/01/", con);
    /* for (auto item: con->pessoas_fisicas()) {
        item->imprimeSujeito();
        delete item;
    }
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
