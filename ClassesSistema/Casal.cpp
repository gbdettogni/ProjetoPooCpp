#include "Casal.hpp"

#include "../ClassesAjudantes/DateUtils.hpp"
#include "../ClassesAjudantes/NumberUtils.hpp"
#include <cctype>
using namespace std;

namespace Sistema{
    time_t Casal::somadorParcelas() {
        list<Parcela*> parcelas;
        if (casamento != nullptr){
            Parcela* pFesta = casamento->getParcelasFesta();
            if (pFesta != nullptr) {
                parcelas.push_back(pFesta);
            }
        }
        if (lar != nullptr) {
            list<Parcela*> psTarefasCompras = lar->getParcelasTarefasCompras();
            parcelas.splice(parcelas.end(), psTarefasCompras);
        }
        somaParcelas = parcelas;
        for (Parcela* p : parcelas) {
            if (p->getData() < inicioDosTempos) {
                inicioDosTempos = p->getData();
            }
        }
        return inicioDosTempos;
    }

    bool Casal::processaParcelas(time_t dataAtual) {
        bool ativo = false;
        double debito = 0;
        for (Parcela* p : somaParcelas) {
            if (!Parcela::existente(p)) {
                if (p->ativa(dataAtual)) {
                    ativo = true;
                    debito += p->getValor();
                }
            }
        }
        somaParcelas.remove_if(Parcela::existente);
        if (ativo) {
            poupancaConjunta *= 1.005;
            if (!cpp_util::formatDate(dataAtual, cpp_util::DATE_FORMAT_PT_BR_SHORT).substr(3, 2).compare("12")) {
                poupancaConjunta += 2*salarioConjunto - gastoConjunto - debito;
            }else {
                poupancaConjunta += salarioConjunto - gastoConjunto - debito;
            }
            historico.push_back(poupancaConjunta);
            // printf("casal: %s, poupanca %.2f\n", pessoa1->getNome().c_str(), poupancaConjunta);
        }
        if (somaParcelas.empty()) {
            return false;
        };
        return true;
    }

    void Casal::imprimeCasal() {
        printf("Casal, formado pelos seguintes sujeitos:\n");
        pessoa1->imprimeSujeito();
        pessoa2->imprimeSujeito();
        lar->imprimeLar();
        casamento->imprimeCasamento();
        for (Parcela* p : somaParcelas) {
            p->imprimeParcela();
        }
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
        poupancaConjunta = pessoa1->getPoupanca() + pessoa2->getPoupanca();
        salarioConjunto = pessoa1->getSalario() + pessoa2->getSalario();
        gastoConjunto = pessoa1->getGastos() + pessoa2->getGastos();

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