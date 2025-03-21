#ifndef PLANILHASCASAL_H
#define PLANILHACASAL_H 
#include <list>
#include <string>

#include "ClassesSistema/PessoaFisica.h"
#include "ClassesSistema/Controle.h"

using namespace std;
using namespace Sistema;

namespace Leitura
{
 class PlanilhasCasal
 {
 public:
    static void lePlanilhaLares(const string &pasta, Controle*);
    static void lePlanilhaCasamentos(const string &pasta, Controle*);
 };
}

#endif // !PLANILHASCASAL_H