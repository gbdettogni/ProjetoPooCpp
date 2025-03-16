#include <iostream>

#include "ClassesLeitura/PlanilhaPessoas.h"
#include "ClassesSistema/Pessoa.h"
#include "ClassesSistema/PessoaFisica.h"

using namespace Sistema;

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    list<PessoaFisica> lista = Leitura::PlanilhaPessoas::lePlanilhaPessoas("/home/betelgeuse/CLionProjects/ProjetoPooCpp/casos/01/");
    for (PessoaFisica pf : lista) {
        pf.imprimeSujeito();
    }
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.