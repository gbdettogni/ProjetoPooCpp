#ifndef LAR_H
#define LAR_H

#include <string>
#include <unordered_map>

#include "Tarefa.h"
//#include "Tarefa.h"

using namespace std;
namespace Sistema{
    class Lar
    {
    private:
        string rua, complemento;
        int numero;
        list<Tarefa*> tarefas;
        //unordered_map<string,Tarefa> tarefas;
    public:
        Lar(string rua, string complemento, int numero);
        void addTarefa(Tarefa* t);

        void imprimeLar();

        ~Lar() {
            for (auto tarefa : tarefas) {
                delete tarefa;
            }
        };
    };
    
    
}

#endif // !LAR_H