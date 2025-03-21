//
// Created by betelgeuse on 20/03/25.
//

#ifndef PLANILHACOMPRAS_H
#define PLANILHACOMPRAS_H
#include <string>

namespace Sistema {
    class Controle;
}

using namespace std;

namespace Leitura {

    class PlanilhaCompras {
    public:
        static void lePlanilhaCompras(const string &pasta, Sistema::Controle* con);
    };

} // Leitura

#endif //PLANILHAFESTAS_H
