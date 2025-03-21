//
// Created by betelgeuse on 20/03/25.
//

#ifndef PLANILHAFESTAS_H
#define PLANILHAFESTAS_H
#include <string>

namespace Sistema {
    class Controle;
}

using namespace std;

namespace Leitura {

class PlanilhaFestas {
public:
    static void lePlanilhaFestas(const string &pasta);
};

} // Leitura

#endif //PLANILHAFESTAS_H
