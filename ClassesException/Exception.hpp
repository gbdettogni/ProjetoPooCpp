#ifndef EXCECAO_H
#define EXCECAO_H
#include <iostream>
#include <string>

using namespace std;
namespace Exc{
    class Excecao {
        string motivo;
        public:
        Excecao(const string& motivo) { this->motivo=motivo; }
        friend ostream& operator<< (ostream &out, const Excecao& excecao){
            return out << excecao.motivo;
        }
    };
    class idRepetidoExcecao : public Excecao{
        public: idRepetidoExcecao(const string &motivo) : Excecao(motivo){};
    };
    class idNaoExisteExcecao : public Excecao{
        public: idNaoExisteExcecao(const string &motivo) : Excecao(motivo){};
    };
    class IOExcecao : public Excecao{
        public: IOExcecao(const string &motivo) : Excecao(motivo){};
    };
}
    
#endif // !EXCECAO_H
