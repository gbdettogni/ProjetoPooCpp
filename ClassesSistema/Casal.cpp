#include "Casal.hpp"
using namespace std;

namespace Sistema{
    void Casal::existo(){
        cout << "eu existo veyr" << endl;
    }

    Casal::Casal(PessoaFisica &p1, PessoaFisica &p2){
        string n1 = p1.getNome(), n2 = p2.getNome();
        this->pessoa1 = &p1;
        this->pessoa2 = &p2;
    }
}