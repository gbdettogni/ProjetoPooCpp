#include "PlanilhasCasal.hpp"

#include <format>

#include "../ClassesAjudantes/Tokenizer.hpp"
#include "../ClassesAjudantes/DateUtils.hpp"
#include "../ClassesAjudantes/NumberUtils.hpp"
#include "../ClassesSistema/PessoaFisica.h"

#include <fstream>
#include <iostream>

using namespace std;
using namespace Sistema;

namespace Leitura
{
    void PlanilhasCasal::lePlanilhaLares(const string &pasta, Controle* c){
        fstream arq;
        arq.open(pasta + "lares.csv", ios::in);
        string linha;
        if (arq.is_open())
        {
            while (!arq.eof())
            {
                getline(arq, linha);
                std::cout << linha << std::endl;
                auto t = Tokenizer(linha, ';');
                while (t.hasNext())
                {
                    string  idLar = t.next(), idPessoa1 = t.next(),
                            idPessoa2 = t.next(), rua = t.next();
                    int numero = stoi(t.next());
                    string complemento = t.next();
                }
                
            }
            
        }
        
    }
}