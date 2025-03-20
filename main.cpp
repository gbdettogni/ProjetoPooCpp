#include <iostream>

#include "ClassesLeitura/PlanilhaFestas.h"
#include "ClassesLeitura/PlanilhaPessoas.h"
#include "ClassesSistema/Controle.h"
#include "ClassesSistema/Pessoa.h"
#include "ClassesSistema/PessoaFisica.h"

using namespace Sistema;

int main() {
    auto* con = new Controle();
    Leitura::PlanilhaPessoas::lePlanilhaPessoas("/home/betelgeuse/CLionProjects/ProjetoPooCpp/casos/01/", con);
    Leitura::PlanilhaFestas::lePlanilhaFestas("/home/betelgeuse/CLionProjects/ProjetoPooCpp/casos/01/", con);
    for (auto item: con->pessoas_fisicas()) {
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

    delete con;
    return 0;
}
