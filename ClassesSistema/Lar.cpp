#include "Lar.hpp"

namespace Sistema
{
    Lar::Lar(string rua, string complemento, int numero){
        this->rua = rua;
        this->complemento = complemento;
        this->numero = numero;
    }

    void Lar::addTarefa(Tarefa *t) {
        this->tarefas.push_back(t);
    }

    double Lar::getPrecoTotalTarefas(){
        double precoTarefas = 0;
        for(Tarefa *t : tarefas){
            precoTarefas += t->getPrecoTarefa();
        }
        return precoTarefas;
    }

    void Lar::imprimeLar() {
        std::cout << "Possui lar" << std::endl;
        for (Tarefa *t : tarefas) {
            t->imprimeTarefa();
        }
    }

    list<Parcela *> Lar::getParcelasTarefasCompras() {
        list<Parcela *> parcelas;
        for (Tarefa *t : tarefas) {
            parcelas.splice(parcelas.end(), t->getParcelasTarefasCompras());
        }
        return parcelas;
    }
}
