#ifndef LAR_H
#define LAR_H

#include <string>
#include <unordered_map>
//#include "Tarefa.h"

using namespace std;
namespace Sistema{
    class Lar
    {
    private:
        string rua, complemento;
        int numero;
        //unordered_map<string,Tarefa> tarefas;
    public:
        Lar(string rua, string complemento, int numero);
    };
    
    
}

#endif // !LAR_H