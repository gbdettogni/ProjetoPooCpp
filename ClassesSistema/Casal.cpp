#include "Casal.hpp"
#include "../ClassesAjudantes/NumberUtils.hpp"
#include <cctype>
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
        cout << "eu existo" << endl;
    }

    Casal::Casal(PessoaFisica *p1, PessoaFisica *p2){
        string n1 = p1->getNome(), n2 = p2->getNome();
        std::cout << n1 + "/" + n2 << std::endl;
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

        casamentosConjuntos = 0;
        gastoTotal = 0;
    }

    void Casal::setLar(Lar* l){
        lar = l;
    }
    void Casal::setCasamento(Casamento *c){
        casamento = c;
    }

    double Casal::getGastoTotal(){
        return gastoTotal;
    }

    PessoaFisica *Casal::getPessoa1(){
        return pessoa1;
    }

    PessoaFisica *Casal::getPessoa2(){
        return pessoa2;
    }

    void Casal::processaGastoTotal(){
        if(casamento != nullptr){
            Festa *f = casamento->getFesta();
            if(f != nullptr) gastoTotal += f->getPrecoPago();
        }
        if(lar != nullptr) gastoTotal += lar->getPrecoTotalTarefas();
        std::cout << "gasto total: " << gastoTotal << std::endl;
    }

    void Casal::processaCasamentoConjunto(unordered_map<string, Festa*> festas){
        string n1 = pessoa1->getNome(), n2 = pessoa2->getNome();
        for (auto & iter : festas)
        {
            Festa* c = iter.second; // pointer to Node
                
            bool p1 = false, p2 = false;
            for(string convidado : c->getListaConvidados()){
                if(convidado.compare(n1) == 0) p1 = true;
                if(convidado.compare(n2) == 0) p2 = true;
                if(p1 && p2){
                    casamentosConjuntos++;
                    break;
                }
            }
                
        }
        std::cout << "casamentos conjuntos: " << casamentosConjuntos << std::endl;
    }

    ostream& operator<<(ostream& stream, Casal* casal){
        string linha = casal->pessoa1->getNome() + ";" + casal->pessoa2->getNome() + ";" + "R$ " + formatDoubleCurrency(casal->gastoTotal, LOCALE_PT_BR) + ";" + to_string(casal->casamentosConjuntos);

        stream.write(linha.c_str(), linha.size());
        return stream;
    }

    bool Casal::comparaCasal(Casal *c1, Casal *c2){ //para sorting
        if(c1->getGastoTotal() > c2->getGastoTotal() ||    (c1->getGastoTotal() == c2->getGastoTotal() && 
                                                            c1->getPessoa1()->getNome().compare(c2->getPessoa1()->getNome()) < 0)) return true;
        else return false;
    }
}