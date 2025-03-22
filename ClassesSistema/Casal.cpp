#include "Casal.hpp"
using namespace std;

namespace Sistema{
    void Casal::imprimeCasal() {
        printf("Casal, formado pelos seguintes sujeitos:\n");
        pessoa1->imprimeSujeito();
        pessoa2->imprimeSujeito();
        lar->imprimeLar();
        casamento->imprimeCasamento();
    }

    void Casal::existo(){
        cout << "eu existo veyr" << endl;
    }

    Casal::Casal(PessoaFisica *p1, PessoaFisica *p2){
        string n1 = (*p1).getNome(), n2 = (*p2).getNome();
        if (n1.compare(n2) < 0){
            pessoa1 = p1;
            pessoa2 = p2;
        }
        else{
            pessoa1 = p2;
            pessoa2 = p1;
        }
        casamento = nullptr;
        lar = nullptr;
    }

    void Casal::setLar(Lar* l){
        lar = l;
    }
    void Casal::setCasamento(Casamento *c){
        casamento = c;
    }
}