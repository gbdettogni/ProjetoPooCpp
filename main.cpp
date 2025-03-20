#include <iostream>

#include "ClassesLeitura/PlanilhaPessoas.h"
#include "ClassesSistema/Controle.h"
#include "ClassesSistema/Pessoa.h"
#include "ClassesSistema/PessoaFisica.h"

using namespace Sistema;

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    auto* con = new Controle();
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    Leitura::PlanilhaPessoas::lePlanilhaPessoas("/home/betelgeuse/CLionProjects/ProjetoPooCpp/casos/01/", con);
    for (auto item: con->pessoas_fisicas()) {
        item->imprimeSujeito();
        delete item;
    }
    for (auto item: con->pessoas_juridicas()) {
        item->imprimeSujeito();
        delete item;
    }

    delete con;
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.