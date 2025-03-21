#include "Casal.hpp"
using namespace std;

namespace Sistema{
    void Casal::imprimeCasal() {
        printf("Casal, formado pelos seguintes suheitos:\n");
        pessoa1->imprimeSujeito();
        pessoa2->imprimeSujeito();
    }

    void Casal::existo(){
        cout << "eu existo veyr" << endl;
    }

    Casal::Casal(PessoaFisica *p1, PessoaFisica *p2){
        string n1 = (*p1).getNome(), n2 = (*p2).getNome();
        pessoa1 = p1;
        pessoa2 = p2;
    }

    void Casal::setLar(Lar* l){
        lar = l;
    }
    void Casal::setCasamento(Casamento *c){
        casamento = c;
    }
}